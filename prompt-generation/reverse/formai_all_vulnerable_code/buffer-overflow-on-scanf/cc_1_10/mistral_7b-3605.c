//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM 100

typedef struct {
    char name[50];
    float value;
} Variable;

void calculate(Variable variables[], int num_vars) {
    int i, j;
    float sum = 0.0, prod = 1.0;

    for (i = 0; i < num_vars; i++) {
        if (strcmp(variables[i].name, "SQUARE") == 0) {
            variables[i].value = pow(variables[i - 1].value, 2);
        } else if (strcmp(variables[i].name, "SINE") == 0) {
            variables[i].value = sin(variables[i - 1].value);
        } else if (strcmp(variables[i].name, "COSINE") == 0) {
            variables[i].value = cos(variables[i - 1].value);
        } else if (strcmp(variables[i].name, "TAN") == 0) {
            variables[i].value = tan(variables[i - 1].value);
        } else if (strcmp(variables[i].name, "ADD") == 0) {
            sum += variables[i - 1].value;
            variables[i].value = sum;
        } else if (strcmp(variables[i].name, "SUB") == 0) {
            prod *= variables[i - 1].value;
            variables[i].value = prod;
        } else if (strcmp(variables[i].name, "MULTIPLY") == 0) {
            sum += variables[i - 1].value;
            variables[i].value = sum;
        } else if (strcmp(variables[i].name, "DIVIDE") == 0) {
            variables[i].value = prod / variables[i - 1].value;
        } else {
            variables[i].value = atof(variables[i].name);
        }
    }
}

int main() {
    Variable variables[MAX_NUM];
    int num_vars = 0, i;
    char input[50];

    printf("Welcome to The Analytical Engine!\n");
    printf("Enter the initial values and operations as 'name value operation' pairs:\n");

    while (1) {
        printf("\nVariable %d: ", num_vars);
        scanf("%s %f %s", input, &variables[num_vars].value, input);

        if (strcmp(input, "END") == 0) {
            break;
        }

        strcpy(variables[num_vars].name, input);
        num_vars++;
    }

    calculate(variables, num_vars);

    printf("\nResults:\n");
    for (i = 0; i < num_vars; i++) {
        printf("Variable %s = %f\n", variables[i].name, variables[i].value);
    }

    return 0;
}