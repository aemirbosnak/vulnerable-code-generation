//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 1000
#define MAX_VARIABLES 100

typedef struct {
    char name[20];
    double value;
} Variable;

Variable variables[MAX_VARIABLES];
int num_variables = 0;

double evaluate_expression(char* expression) {
    double result = 0;
    char* token = strtok(expression, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            result += atof(token);
        } else {
            int i;
            for (i = 0; i < num_variables; i++) {
                if (strcmp(token, variables[i].name) == 0) {
                    result += variables[i].value;
                    break;
                }
            }
            if (i == num_variables) {
                printf("Undefined variable: %s\n", token);
                exit(1);
            }
        }
        token = strtok(NULL, " ");
    }
    return result;
}

void define_variable(char* name, double value) {
    int i;
    for (i = 0; i < num_variables; i++) {
        if (strcmp(name, variables[i].name) == 0) {
            printf("Variable %s already defined.\n", name);
            return;
        }
    }
    if (num_variables == MAX_VARIABLES) {
        printf("Maximum number of variables reached.\n");
        exit(1);
    }
    strcpy(variables[num_variables].name, name);
    variables[num_variables].value = value;
    num_variables++;
}

int main() {
    char input[MAX_BUFFER];
    while (1) {
        printf("Enter expression: ");
        fgets(input, MAX_BUFFER, stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "exit") == 0) {
            break;
        }
        double result = evaluate_expression(input);
        printf("Result: %f\n", result);
    }
    return 0;
}