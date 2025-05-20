//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VARIABLES 100

int main() {
    int num_variables;
    double **coefficients, **constants;
    double *solution;
    int i, j;

    // Get number of variables from user
    printf("Enter the number of variables: ");
    scanf("%d", &num_variables);

    // Allocate memory for coefficients and constants
    coefficients = (double **)malloc(num_variables * sizeof(double *));
    constants = (double **)malloc(num_variables * sizeof(double *));
    for (i = 0; i < num_variables; i++) {
        coefficients[i] = (double *)malloc(num_variables * sizeof(double));
        constants[i] = (double *)malloc(num_variables * sizeof(double));
    }

    // Get coefficients and constants from user
    printf("Enter the coefficients and constants for each variable:\n");
    for (i = 0; i < num_variables; i++) {
        for (j = 0; j < num_variables; j++) {
            scanf("%lf", &coefficients[i][j]);
        }
        scanf("%lf", &constants[i][0]);
    }

    // Solve system of equations
    solution = (double *)malloc(num_variables * sizeof(double));
    for (i = 0; i < num_variables; i++) {
        solution[i] = constants[i][0] / coefficients[i][i];
        for (j = 1; j < num_variables; j++) {
            constants[i][j] -= coefficients[i][j] * solution[i];
        }
    }

    // Print solution
    printf("The solution is:\n");
    for (i = 0; i < num_variables; i++) {
        printf("%lf\n", solution[i]);
    }

    // Free memory
    for (i = 0; i < num_variables; i++) {
        free(coefficients[i]);
        free(constants[i]);
    }
    free(coefficients);
    free(constants);
    free(solution);

    return 0;
}