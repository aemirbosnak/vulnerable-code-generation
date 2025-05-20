//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_OPERATORS 10
#define MAX_OPERANDS 10

enum Operator {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

double calculate(int num_operators, char* operators, int num_operands, double* operands) {
    double result = operands[0];

    for (int i = 0; i < num_operators; i++) {
        switch (operators[i]) {
            case '+':
                result = result + operands[i + 1];
                break;
            case '-':
                result = result - operands[i + 1];
                break;
            case '*':
                result = result * operands[i + 1];
                break;
            case '/':
                result = result / operands[i + 1];
                break;
        }
    }

    return result;
}

int main() {
    int num_operators, num_operands;
    char operators[MAX_OPERATORS];
    double operands[MAX_OPERANDS];

    printf("Enter the number of operators: ");
    scanf("%d", &num_operators);

    printf("Enter the operators (e.g. +, -, *, /): ");
    scanf("%s", operators);

    printf("Enter the number of operands: ");
    scanf("%d", &num_operands);

    for (int i = 0; i < num_operands; i++) {
        printf("Enter operand %d: ", i + 1);
        scanf("%lf", &operands[i]);
    }

    double result = calculate(num_operators, operators, num_operands, operands);

    printf("Result: %f\n", result);

    return 0;
}