//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define RESISTOR 1
#define CAPACITOR 2
#define INDUCTOR 3

typedef struct Element{
  int type; // resistor,capacitor or inductor
  double value; // value of the element
  int n1,n2; // nodes to which this element is connected
}Element;

int numEl; // number of elements in the circuit
Element* elementList; // list of elements 

double* solution; // nodal voltages
double* current; // current through each element

// function to allocate memory for all arrays
void allocateMem(){

  elementList = (Element*)calloc(numEl,sizeof(Element));
  solution = (double*)calloc(numEl+1,sizeof(double));
  current = (double*)calloc(numEl,sizeof(double));

}

// function to calculate the respective conductance value
double calcConductance(int i,int j){

  double res = 0;

  if(i==-1 || j==-1) // ground node assumed zero
    res = 0;
  else{
    for(int k=0;k<numEl;k++){ // locating the connected node
      if(i==elementList[k].n1 && j==elementList[k].n2){
        if(elementList[k].type==RESISTOR)
          res = 1/elementList[k].value;
        else if(elementList[k].type==CAPACITOR)
          res = 0;
        else if(elementList[k].type==INDUCTOR)
          res = 0;
        break;
      }
      if(j==elementList[k].n1 && i==elementList[k].n2){
        if(elementList[k].type==RESISTOR)
          res = 1/elementList[k].value;
        else if(elementList[k].type==CAPACITOR)
          res = 0;
        else if(elementList[k].type==INDUCTOR)
          res = 0;
        break;
      }
    }
  }

  return res;

}

// function to calculate the current
void calcCurrent(){

  for(int i=0;i<numEl;i++){
    if(elementList[i].type==RESISTOR)
      current[i] = (solution[elementList[i].n1] - solution[elementList[i].n2])/elementList[i].value;
    else if(elementList[i].type==CAPACITOR)
      current[i] = 0;
    else if(elementList[i].type==INDUCTOR)
      current[i] = 0;
  }

}

// function to find the next node in the current loop
int nextNode(int n){

  for(int i=n+1;i<numEl+1;i++)
    if(fabs(current[i]) > 0.0001) // checking for non zero elements
      return i;

  return -1; // reached ground node

}

// function to solve the circuit using Gauss-Siedel method 
void solve(){

  double tol = 0.00001, maxError = 100;
  int iterCount = 0;
  double error;
  int n1,n2,next;

  while(maxError > tol && iterCount<1000){ // make sure to terminate if it takes too long

    maxError = 0.0;

    for(int i=0;i<numEl+1;i++){
      solution[i] = 0.0;
      for(int j=0;j<numEl+1;j++){ // solving for each node voltage
        if(i!=j)
          solution[i] += calcConductance(i,j)*solution[j];
      }
    }

    for(int i=0;i<numEl;i++){
      n1 = elementList[i].n1;
      n2 = elementList[i].n2;

      if(elementList[i].type==RESISTOR)
        error = fabs(solution[n1]-solution[n2])+elementList[i].value*current[i];
      else if(elementList[i].type==CAPACITOR)
        error = current[i]-((solution[n1]-solution[n2])/elementList[i].value);
      else if(elementList[i].type==INDUCTOR)
        error = current[i]-(elementList[i].value*(solution[n1]-solution[n2]));

      if(fabs(error)>maxError)
        maxError = fabs(error);

      current[i] -= error;

    }

    next = nextNode(-1); // starting from ground node
    while(next!=-1){
      solution[next] += current[next];
      next = nextNode(next);
    }

    iterCount++;

  }

}

void main(){

  printf("Enter the number of elements in the circuit: ");
  scanf("%d",&numEl);
  allocateMem();

  printf("Enter the element values and their connections (node indices)\n");
  for(int i=0;i<numEl;i++){
    printf("Type of element:\n1. Resistor\n2. Capacitor\n3. Inductor\n");
    scanf("%d",&elementList[i].type);
    printf("Value of element: ");
    scanf("%lf",&elementList[i].value);
    printf("Enter node indices: ");
    scanf("%d %d",&elementList[i].n1,&elementList[i].n2);
  }

  solve();

  printf("Nodal voltages:\n");
  for(int i=0;i<numEl+1;i++)
    printf("Node %d: %lf\n",i,solution[i]);

}