//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num1;
    int num2;
    char op;
} Arithmetic_op;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        exit(1);
    }
    return a / b;
}

void recursive_arithmetic(Arithmetic_op op) {
    int result;
    switch (op.op) {
        case '+':
            result = add(op.num1, op.num2);
            printf("%d + %d = %d\n", op.num1, op.num2, result);
            if (op.num2 != 0) {
                Arithmetic_op new_op = {result, op.num1, '+'};
                recursive_arithmetic(new_op);
            }
            break;
        case '-':
            result = subtract(op.num1, op.num2);
            printf("%d - %d = %d\n", op.num1, op.num2, result);
            if (op.num2 != 0) {
                Arithmetic_op new_op = {result, op.num1, '-'};
                recursive_arithmetic(new_op);
            }
            break;
        case '*':
            result = multiply(op.num1, op.num2);
            printf("%d * %d = %d\n", op.num1, op.num2, result);
            if (op.num2 != 1) {
                Arithmetic_op new_op = {result, op.num1, '*'};
                recursive_arithmetic(new_op);
            }
            break;
        case '/':
            result = divide(op.num1, op.num2);
            printf("%d / %d = %d\n", op.num1, op.num2, result);
            if (op.num2 != 1) {
                Arithmetic_op new_op = {result, op.num1, '/'};
                recursive_arithmetic(new_op);
            }
            break;
    }
}

int main() {
    int num1 = 10;
    int num2 = 5;
    char operation = '+';

    Arithmetic_op op = {num1, num2, operation};
    recursive_arithmetic(op);

    return 0;
}