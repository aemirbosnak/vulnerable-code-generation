//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER 20

typedef struct {
    int num1;
    int num2;
    char op;
} ArithmeticOperation;

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

void perform_arithmetic_operation(ArithmeticOperation op) {
    switch (op.op) {
        case '+':
            printf("%d + %d = %d\n", op.num1, op.num2, op.num1 + op.num2);
            break;
        case '-':
            printf("%d - %d = %d\n", op.num1, op.num2, op.num1 - op.num2);
            break;
        case '*':
            printf("%d * %d = %d\n", op.num1, op.num2, op.num1 * op.num2);
            break;
        case '/':
            if (op.num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                exit(EXIT_FAILURE);
            }
            printf("%d / %d = %.2f\n", op.num1, op.num2, (float)op.num1 / (float)op.num2);
            break;
        default:
            printf("Error: Invalid arithmetic operation.\n");
            exit(EXIT_FAILURE);
    }
}

int main() {
    int num, i;
    char op;
    ArithmeticOperation arithmetic_operation;

    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);

    if (num > MAX_NUMBER) {
        printf("Error: Number is too large to calculate factorial.\n");
        exit(EXIT_FAILURE);
    }

    printf("Factorial of %d = %d\n", num, factorial(num));

    printf("Enter the first number: ");
    scanf("%d", &arithmetic_operation.num1);

    printf("Enter the second number: ");
    scanf("%d", &arithmetic_operation.num2);

    printf("Enter an arithmetic operation (+, -, *, /): ");
    scanf(" %c", &op);

    arithmetic_operation.op = op;

    perform_arithmetic_operation(arithmetic_operation);

    printf("Enter y to perform another arithmetic operation or any other key to exit: ");
    scanf(" %c", &i);

    if (i != 'y') {
        printf("Exiting the program.\n");
    }

    return 0;
}