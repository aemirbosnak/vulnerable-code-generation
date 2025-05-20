//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100

int resistance[MAX_NODES][MAX_NODES];
int admittance[MAX_NODES][MAX_NODES];
int numberOfNodes, numberOfElements;

void addResistor(int n1, int n2, double resistanceValue)
{
    resistance[n1][n2] += resistanceValue;
    resistance[n2][n1] += resistanceValue;
}

void addCapacitor(int n1, int n2, double capacitanceValue, double deltaT)
{
    double impedance = 1 / (capacitanceValue * deltaT);
    admittance[n1][n1] += impedance;
    admittance[n2][n2] += impedance;
    admittance[n1][n2] -= impedance;
    admittance[n2][n1] -= impedance;
}

void addInductor(int n1, int n2, double inductanceValue, double deltaT)
{
    double impedance = inductanceValue / deltaT;
    admittance[n1][n1] += impedance;
    admittance[n2][n2] += impedance;
    admittance[n1][n2] -= impedance;
    admittance[n2][n1] -= impedance;
}

void printMatrix(double matrix[MAX_NODES][MAX_NODES], int size)
{
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void gaussianElimination(double A[MAX_NODES][MAX_NODES], double B[MAX_NODES], int size)
{
    double pivot, temp, max;
    int i, j, k, row;
    for(i=0; i<size; i++) {
        max = 0.0;
        row = i;
        for(j=i; j<size; j++) {
            if(fabs(A[j][i]) > max) {
                max = fabs(A[j][i]);
                row = j;
            }
        }
        for(j=i; j<=size; j++) {
            temp = A[row][j];
            A[row][j] = A[i][j];
            A[i][j] = temp;
        }
        temp = B[row];
        B[row] = B[i];
        B[i] = temp;
        for(j=i+1; j<size; j++) {
            pivot = A[j][i] / A[i][i];
            for (k=i; k<=size; k++) {
                A[j][k] -= pivot * A[i][k];
            }
            B[j] -= pivot * B[i];
        }
    }
    for (i=size-1; i>=0; i--) {
        temp = 0.0;
        for (j=i+1; j<size; j++) {
            temp += A[i][j] * B[j];
        }
        B[i] = (B[i] - temp) / A[i][i];
    }
}

int main(void)
{
    scanf("%d %d", &numberOfNodes, &numberOfElements);
    double capacitanceValue, inductanceValue, resistanceValue, deltaT, sourceValue;

    for(int i=0; i<numberOfElements; i++) {
        int n1, n2;
        char elementType;
        scanf("%*s %d %d", &n1, &n2);
        if(n1 > numberOfNodes || n2 > numberOfNodes) {
            printf("Invalid node number\n");
            exit(1);
        }

        scanf("%*s ");
        scanf("%c", &elementType);

        switch(elementType) {
            case 'R':   // Resistor
                scanf("%lf", &resistanceValue);
                addResistor(n1-1, n2-1, resistanceValue);
                break;
            case 'C':   // Capacitor
                scanf("%lf %lf", &capacitanceValue, &deltaT);
                addCapacitor(n1-1, n2-1, capacitanceValue, deltaT);
                break;
            case 'L':   // Inductor
                scanf("%lf %lf", &inductanceValue, &deltaT);
                addInductor(n1-1, n2-1, inductanceValue, deltaT);
                break;
            case 'V':   // Voltage Source
                scanf("%lf", &sourceValue);
                break;
            default:
                printf("Invalid element type\n");
                exit(1);
        }
    }

    double A[MAX_NODES][MAX_NODES];
    double B[MAX_NODES];

    // Initialize A and B matrices
    for(int i=0; i<numberOfNodes; i++) {
        for(int j=0; j<numberOfNodes; j++) {
            A[i][j] = 0.0;
        }
        B[i] = 0.0;
    }

    // Populate A and B matrices
    for(int i=0; i<numberOfNodes; i++) {
        for(int j=0; j<numberOfNodes; j++) {
            if(i==j) {
                A[i][j] = admittance[i][j];
            }
            else {
                A[i][j] = -admittance[i][j];
            }
        }
    }

    // Solve the matrix equation Ax=B
    gaussianElimination(A, B, numberOfNodes);

    // Print the result
    for(int i=0; i<numberOfNodes; i++) {
        printf("Node %d voltage: %.2lf V\n", i+1, B[i]);
    }

    return 0;
}