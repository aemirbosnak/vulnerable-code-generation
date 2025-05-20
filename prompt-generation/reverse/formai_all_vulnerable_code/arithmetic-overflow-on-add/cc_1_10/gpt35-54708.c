//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#define MAX_NODES 100

int nto;                        //Total number of nodes
int cmat[MAX_NODES][MAX_NODES]; //Capacitance matrix
int zmat[MAX_NODES][MAX_NODES]; //Impedance matrix
int vm[MAX_NODES];              //Voltage matrix
int v[MAX_NODES];               //Temprary voltage matrix
int r[MAX_NODES];               //Resistor matrix
int c[MAX_NODES];               //Capacitor matrix

//Function to initialize matrices and vectors
void initialize()
{
    for(int i=0;i<nto;i++)
        vm[i]=v[i]=0;
        
    for(int i=0;i<nto;i++)
        for(int j=0;j<nto;j++)
            cmat[i][j]=zmat[i][j]=0;
}

//Function to add resistor
void addRes(int i, int j, int res)
{
    cmat[i][i]+=1.0/res;
    cmat[i][j]-=1.0/res;
    cmat[j][i]-=1.0/res;
    cmat[j][j]+=1.0/res;
}

//Function to add capacitor
void addCap(int i, int j, int cap)
{
    cmat[i][i]+=1.0/cap;
    cmat[j][j]+=1.0/cap;
    cmat[i][j]-=1.0/cap;
    cmat[j][i]-=1.0/cap;
}

//Function to compute impedance matrix for frequency f
void computeZmat(double f)
{
    for(int i=0;i<nto;i++)
        for(int j=0;j<nto;j++)
            zmat[i][j]=0;
            
    for(int i=0;i<nto;i++)
        for(int j=0;j<nto;j++)
            zmat[i][j]+=cmat[i][j]-1.0/(2*3.14*f*c[j]);
}

//Function to solve the circuit for frequency f
void solve(double f)
{
    computeZmat(f);
    
    for(int i=0;i<nto;i++)
    {
        for(int j=0;j<nto;j++)
        {
            if(i!=j) v[i]+=zmat[i][j]*vm[j];
        }
        v[i]/=zmat[i][i];
    }
    
    for(int i=0;i<nto;i++)
        vm[i]=v[i];
}

int main()
{
    nto=5;
    
    r[0]=1;
    r[1]=2;
    r[2]=1;
    r[3]=2;
    
    c[3]=1.0;
    c[4]=0.5;
    
    addRes(0,1,r[0]);
    addRes(1,2,r[1]);
    addRes(2,3,r[2]);
    addRes(3,0,r[3]);
    
    addCap(3,4,c[3]);
    addCap(4,0,c[4]);
    
    initialize();
    vm[0]=1;
    
    for(double f=1;f<=1000;f+=10)
    {
        solve(f);
        printf("%f   %f\n",f,v[0]);
    }
    
    return 0;
}