//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER_OF_OPERATIONS 10
#define MAX_NUMBER_OF_VARIABLES 5

typedef struct {
    int value;
    char name[20];
} variable_t;

variable_t variables[MAX_NUMBER_OF_VARIABLES];
int current_variable = 0;

void init_variables(void) {
    int i;

    for (i = 0; i < MAX_NUMBER_OF_VARIABLES; i++) {
        sprintf(variables[i].name, "x%d", i);
        variables[i].value = 0;
    }
}

void perform_operation(char *operation) {
    int first_variable, second_variable;
    int result;

    if (sscanf(operation, "%d%d%c", &first_variable, &second_variable, &result) == 3) {
        if (strcmp(operation, "+") == 0) {
            result = first_variable + second_variable;
        } else if (strcmp(operation, "-") == 0) {
            result = first_variable - second_variable;
        } else if (strcmp(operation, "*") == 0) {
            result = first_variable * second_variable;
        } else if (strcmp(operation, "/") == 0) {
            result = first_variable / second_variable;
        } else if (strcmp(operation, "%") == 0) {
            result = first_variable % second_variable;
        }
        printf("Result: %d\n", result);
    } else {
        printf("Invalid operation: %s\n", operation);
    }
}

int main(void) {
    srand(time(NULL));

    init_variables();

    while (1) {
        char operation[20];
        int i;

        printf("Enter an operation (+, -, *, /, %): ");
        fgets(operation, 20, stdin);
        perform_operation(operation);

        for (i = 0; i < MAX_NUMBER_OF_VARIABLES; i++) {
            printf("Variable %d: %d\n", i, variables[i].value);
        }

        if (current_variable == MAX_NUMBER_OF_VARIABLES) {
            break;
        }
    }

    return 0;
}