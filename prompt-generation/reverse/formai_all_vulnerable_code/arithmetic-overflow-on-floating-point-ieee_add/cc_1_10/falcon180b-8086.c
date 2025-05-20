//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARS 10

typedef struct {
    char name[20];
    double value;
} Variable;

Variable variables[MAX_VARS];
int num_vars;

void add_variable(char *name) {
    if (num_vars >= MAX_VARS) {
        printf("Error: Too many variables\n");
        return;
    }
    strcpy(variables[num_vars].name, name);
    variables[num_vars].value = 0;
    num_vars++;
}

void set_variable(char *name, double value) {
    int i;
    for (i = 0; i < num_vars; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            variables[i].value = value;
            return;
        }
    }
    printf("Error: Variable not found\n");
}

double get_variable(char *name) {
    int i;
    for (i = 0; i < num_vars; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return variables[i].value;
        }
    }
    printf("Error: Variable not found\n");
    return 0;
}

double evaluate_expression(char *expr) {
    double result = 0;
    char *token;
    int i, j;

    token = strtok(expr, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            result += atof(token);
        } else {
            i = 0;
            while (i < num_vars && strcmp(variables[i].name, token)!= 0) {
                i++;
            }
            if (i >= num_vars) {
                printf("Error: Variable not found\n");
                return 0;
            }
            result += get_variable(variables[i].name);
        }
        token = strtok(NULL, " ");
    }

    return result;
}

int main() {
    char input[100];
    while (1) {
        printf("Enter an expression or type 'quit' to exit: ");
        fgets(input, 100, stdin);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        double result = evaluate_expression(input);
        if (result!= 0) {
            printf("Result: %lf\n", result);
        }
    }
    return 0;
}