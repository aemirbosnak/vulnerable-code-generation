//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VARIABLES 100
#define MAX_COEFFICIENTS 1000

typedef struct {
    char name[20];
    double coefficient;
} Variable;

Variable variables[MAX_VARIABLES];
double coefficients[MAX_COEFFICIENTS];
int numVariables;
int numCoefficients;

void readVariables() {
    FILE *file;
    char line[50];
    int i = 0;

    file = fopen("variables.txt", "r");

    while (fgets(line, sizeof(line), file)!= NULL) {
        sscanf(line, "%s %lf", variables[i].name, &variables[i].coefficient);
        i++;
    }

    fclose(file);
    numVariables = i;
}

void readCoefficients() {
    FILE *file;
    double coefficient;
    int i = 0;

    file = fopen("coefficients.txt", "r");

    while (fscanf(file, "%lf", &coefficient)!= EOF) {
        coefficients[i] = coefficient;
        i++;
    }

    fclose(file);
    numCoefficients = i;
}

void calculateOptimization() {
    int i, j, k;
    double sum = 0;

    for (i = 0; i < numVariables; i++) {
        for (j = 0; j < numCoefficients; j++) {
            sum += variables[i].coefficient * coefficients[j];
        }
    }

    printf("The optimization value is: %lf\n", sum);
}

int main() {
    readVariables();
    readCoefficients();
    calculateOptimization();

    return 0;
}