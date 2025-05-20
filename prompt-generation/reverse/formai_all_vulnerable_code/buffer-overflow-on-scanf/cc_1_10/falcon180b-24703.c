//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_OPERATORS 100

typedef struct {
    char *name;
    int (*func)(double, double);
} Operator;

Operator operators[MAX_OPERATORS];
int num_operators = 0;

void add_operator(char *name, int (*func)(double, double)) {
    if (num_operators >= MAX_OPERATORS) {
        printf("Error: Too many operators.\n");
        return;
    }
    operators[num_operators] = (Operator) {name, func};
    num_operators++;
}

int calculate(double a, double b, char *operator_name) {
    for (int i = 0; i < num_operators; i++) {
        if (strcmp(operator_name, operators[i].name) == 0) {
            return operators[i].func(a, b);
        }
    }
    printf("Error: Invalid operator '%s'.\n", operator_name);
    return 0;
}

int add(double a, double b) {
    return a + b;
}

int subtract(double a, double b) {
    return a - b;
}

int multiply(double a, double b) {
    return a * b;
}

int divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero.\n");
        return 0;
    }
    return a / b;
}

int power(double a, double b) {
    return pow(a, b);
}

int main() {
    add_operator("+", add);
    add_operator("-", subtract);
    add_operator("*", multiply);
    add_operator("/", divide);
    add_operator("^", power);

    char input[100];
    while (1) {
        printf("Enter an expression or type 'quit' to exit: ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        double a, b;
        char *operator_name = strtok(input, " ");
        a = atof(strtok(NULL, " "));
        b = atof(strtok(NULL, " "));
        int result = calculate(a, b, operator_name);
        if (result!= 0) {
            printf("Result: %g\n", result);
        }
    }

    return 0;
}