//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20
#define MAX_VALUE 100

int nodes;
double R[MAX_NODES][MAX_NODES], G[MAX_NODES][MAX_NODES], V[MAX_NODES][MAX_NODES];
double b[MAX_NODES], x[MAX_NODES];

void inputCircuit()
{
    int i, j, k;

    //Get number of nodes
    printf("Enter the number of nodes in the circuit: ");
    scanf("%d", &nodes);

    //Initialize circuit matrices to zero
    for(i = 0; i <= nodes; ++i)
    {
        for(j = 0; j <= nodes; ++j)
        {
            R[i][j] = 0;
            G[i][j] = 0;
            V[i][j] = 0;
        }
        b[i] = 0.0;
        x[i] = 0.0;
    }

    //Get resistor values
    printf("\nEnter resistance values of the circuit:\n");
    for(i = 1; i <= nodes; ++i)
    {
        for(j = 1; j <= nodes; ++j)
        {
            if(i != j)
            {
                printf("R%d%d: ", i, j);
                scanf("%lf", &R[i][j]);

                G[i][j] = 1.0 / R[i][j];
            }
        }
    }

    //Get current and voltage sources values
    printf("\nEnter current and voltage source values:\n");
    for(i = 1; i <= nodes; ++i)
    {
        for(j = 1; j <= nodes; ++j)
        {
            if(i != j)
            {
                printf("V%d%d: ", i, j);
                scanf("%lf", &V[i][j]);                
            }
            else
            {
                printf("I%d: ", i);
                scanf("%lf", &b[i]);
            }
        }
    }
}

void solveCircuit()
{
    int i, j, k;
    double f;

    //Gaussian elimination
    for(k = 1; k <= nodes; ++k)
    {
        for(i = 1; i <= nodes; ++i)
        {
            if(i != k)
            {
                f = G[i][k] / G[k][k];
                b[i] -= f * b[k];

                for(j = 1; j <= nodes; ++j)
                {
                    if(j != k)
                    {
                        G[i][j] -= f * G[k][j];
                    }
                    else
                    {
                        G[i][j] /= f;
                    }
                }
            }
        }
    }

    //Back-substitution
    for(i = 1; i <= nodes; ++i)
    {
        x[i] = b[i] / G[i][i];
    }
}

void printResults()
{
    int i;

    printf("\nCircuit analysis solved by Classical Circuit Simulator:\n");

    //Print node voltages
    printf("\nNode voltages:\n");
    for(i = 1; i <= nodes; ++i)
    {
        printf("V%d = %.2lfV\n", i, x[i]);
    }
}

int main()
{
    inputCircuit();
    solveCircuit();
    printResults();

    return EXIT_SUCCESS;
}