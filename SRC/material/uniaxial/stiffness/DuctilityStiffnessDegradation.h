/* ****************************************************************** **
**    OpenSees - Open System for Earthquake Engineering Simulation    **
**          Pacific Earthquake Engineering Research Center            **
**                                                                    **
**                                                                    **
** (C) Copyright 1999, The Regents of the University of California    **
** All Rights Reserved.                                               **
**                                                                    **
** Commercial use of this program without express permission of the   **
** University of California, Berkeley, is strictly prohibited.  See   **
** file 'COPYRIGHT'  in main directory for information on usage and   **
** redistribution,  and for a DISCLAIMER OF ALL WARRANTIES.           **
**                                                                    **
** Developed by:                                                      **
**   Frank McKenna (fmckenna@ce.berkeley.edu)                         **
**   Gregory L. Fenves (fenves@ce.berkeley.edu)                       **
**   Filip C. Filippou (filippou@ce.berkeley.edu)                     **
**                                                                    **
** ****************************************************************** */
                                                                        
// $Revision$
// $Date$
// $Source$

// Written: MHS
// Created: August 2000
//
// Description: This file contains the implementation of 
// DuctilityStiffnessDegradation, which models hysteretic stiffness
// degradation with the relation alpha*(u-1.0), based on
// deformation ductility.

#ifndef DuctitlityStiffnessDegradation_h
#define DuctitlityStiffnessDegradation_h

#include <StiffnessDegradation.h>

class DuctilityStiffnessDegradation : public StiffnessDegradation
{
 public:
  DuctilityStiffnessDegradation(int tag, double a, double b);    
  DuctilityStiffnessDegradation();
  virtual ~DuctilityStiffnessDegradation();
  
  const char *getMeasure(void);
  int setTrialMeasure(double measure);
  double getValue(void);
  
  void setNegative(bool flag = false);
  
  int commitState(void);
  int revertToLastCommit(void);
  int revertToStart(void);
  
  StiffnessDegradation *getCopy(void);
  
  int sendSelf(int commitTag, Channel &theChannel);  
  int recvSelf(int commitTag, Channel &theChannel, 
	       FEM_ObjectBroker &theBroker);    
  
  void Print(OPS_Stream &s, int flag = 0);
  
 protected:
  
 private:
  bool isNegative;
  
  double alpha;
  double beta;
  double Tductility;
  double Cductility;
};

#endif
