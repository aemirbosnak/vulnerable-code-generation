//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_OPERANDS 2
#define MAX_OPERATORS 1

int main() {
    double operands[MAX_OPERANDS];
    char operators[MAX_OPERATORS];
    int num_operands = 0;
    int num_operators = 0;
    char input[100];
    char *token;
    char *endptr;

    printf("Welcome to the C Scientific Calculator!\n");
    printf("Enter an expression, such as \"2+2*3\": ");
    fgets(input, 100, stdin);

    token = strtok(input, "+-*/");
    while (token != NULL) {
        if (isdigit(token[0])) {
            operands[num_operands++] = strtod(token, &endptr);
        } else {
            operators[num_operators++] = *token;
        }
        token = strtok(NULL, "+-*/");
    }

    if (num_operands != 2) {
        printf("Error: Invalid number of operands.\n");
        return 1;
    }

    if (num_operators != 1) {
        printf("Error: Invalid number of operators.\n");
        return 1;
    }

    switch (operators[0]) {
        case '+':
            printf("Result: %f\n", operands[0] + operands[1]);
            break;
        case '-':
            printf("Result: %f\n", operands[0] - operands[1]);
            break;
        case '*':
            printf("Result: %f\n", operands[0] * operands[1]);
            break;
        case '/':
            printf("Result: %f\n", operands[0] / operands[1]);
            break;
        default:
            printf("Error: Invalid operator.\n");
            return 1;
    }

    return 0;
}