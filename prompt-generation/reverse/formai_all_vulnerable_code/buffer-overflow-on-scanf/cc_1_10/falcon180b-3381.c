//Falcon-180B DATASET v1.0 Category: Educational ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VARIABLES 10
#define MAX_TERMS 1000

typedef struct {
    char name[20];
    double coefficient;
    int power;
} Term;

typedef struct {
    int num_variables;
    char variables[MAX_VARIABLES][20];
    int num_terms;
    Term terms[MAX_TERMS];
} Equation;

int main() {
    Equation eqn;
    int i, j, num_vars, num_terms;
    char input[100];

    // Get number of variables
    printf("Enter the number of variables: ");
    scanf("%d", &num_vars);

    // Get variable names
    for (i = 0; i < num_vars; i++) {
        printf("Enter variable %d name: ", i+1);
        scanf("%s", eqn.variables[i]);
    }

    // Get number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &num_terms);

    // Get term coefficients and powers
    for (i = 0; i < num_terms; i++) {
        printf("Enter term %d coefficient: ", i+1);
        scanf("%lf", &eqn.terms[i].coefficient);

        printf("Enter term %d variable: ", i+1);
        scanf("%s", input);

        for (j = 0; j < num_vars; j++) {
            if (strcmp(input, eqn.variables[j]) == 0) {
                eqn.terms[i].power = j;
                break;
            }
        }

        if (j == num_vars) {
            printf("Variable not found.\n");
            exit(1);
        }
    }

    // Print equation
    printf("Equation:\n");
    for (i = 0; i < num_terms; i++) {
        if (eqn.terms[i].power == 1) {
            printf("%s", eqn.variables[eqn.terms[i].power]);
        } else {
            printf("%s^%d", eqn.variables[eqn.terms[i].power], eqn.terms[i].power);
        }

        if (i < num_terms-1) {
            printf(" + ");
        }
    }

    return 0;
}