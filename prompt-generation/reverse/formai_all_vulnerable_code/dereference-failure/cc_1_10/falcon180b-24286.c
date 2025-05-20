//Falcon-180B DATASET v1.0 Category: Error handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VARIABLES 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Variable;

Variable variables[MAX_VARIABLES];
int num_variables = 0;

void add_variable(char* name, char* value) {
    if (num_variables >= MAX_VARIABLES) {
        printf("Error: Too many variables.\n");
        exit(1);
    }

    strcpy(variables[num_variables].name, name);
    strcpy(variables[num_variables].value, value);

    num_variables++;
}

int main() {
    add_variable("x", "10");
    add_variable("y", "20");
    add_variable("z", "30");

    int result = evaluate_expression("x + y * z");

    printf("Result: %d\n", result);

    return 0;
}

int evaluate_expression(char* expression) {
    char* token = strtok(expression, " ");
    int num_tokens = 0;

    while (token!= NULL) {
        num_tokens++;

        if (num_tokens > MAX_VARIABLES) {
            printf("Error: Expression too complex.\n");
            exit(1);
        }

        int variable_index = -1;
        for (int i = 0; i < num_variables; i++) {
            if (strcmp(token, variables[i].name) == 0) {
                variable_index = i;
                break;
            }
        }

        if (variable_index == -1) {
            printf("Error: Undefined variable.\n");
            exit(1);
        }

        token = strtok(NULL, " ");
    }

    return 0;
}