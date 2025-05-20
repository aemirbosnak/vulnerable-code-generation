//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPERANDS 5
#define MAX_NUMBERS 10

typedef struct {
    char op;
    int num1, num2;
} operation;

operation operations[MAX_OPERANDS] = {
    {'+', 0, 0},
    {'-', 0, 0},
    {'*', 0, 0},
    {'/', 0, 0},
    {'%', 0, 0}
};

int main() {
    int num1, num2, result;
    char op;

    printf("Welcome to Arithmetic Land!\n");

    do {
        printf("Enter a number: ");
        scanf("%d", &num1);

        printf("Enter another number: ");
        scanf("%d", &num2);

        printf("Enter an operation (+, -, *, /, or %): ");
        scanf(" %c", &op);

        if (op == '+') {
            operations[0].op = '+';
            operations[0].num1 = num1;
            operations[0].num2 = num2;
        } else if (op == '-') {
            operations[1].op = '-';
            operations[1].num1 = num1;
            operations[1].num2 = num2;
        } else if (op == '*') {
            operations[2].op = '*';
            operations[2].num1 = num1;
            operations[2].num2 = num2;
        } else if (op == '/') {
            operations[3].op = '/';
            operations[3].num1 = num1;
            operations[3].num2 = num2;
        } else if (op == '%') {
            operations[4].op = '%';
            operations[4].num1 = num1;
            operations[4].num2 = num2;
        }

        result = perform_operation(operations);

        printf("Result: %d\n", result);

    } while (1);

    return 0;
}

int perform_operation(operation *ops) {
    int result = 0;

    for (int i = 0; i < MAX_OPERANDS; i++) {
        if (ops[i].op == '+') {
            result = ops[i].num1 + ops[i].num2;
        } else if (ops[i].op == '-') {
            result = ops[i].num1 - ops[i].num2;
        } else if (ops[i].op == '*') {
            result = ops[i].num1 * ops[i].num2;
        } else if (ops[i].op == '/') {
            result = ops[i].num1 / ops[i].num2;
        } else if (ops[i].op == '%') {
            result = ops[i].num1 % ops[i].num2;
        }
    }

    return result;
}