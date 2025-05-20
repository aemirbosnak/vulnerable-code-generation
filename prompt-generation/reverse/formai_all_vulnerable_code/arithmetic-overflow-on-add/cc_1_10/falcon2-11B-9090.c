//Falcon2-11B DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>

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
        printf("Error: Division by zero is not allowed\n");
        return 0;
    }
    return a / b;
}

int main() {
    int num1, num2, result;
    char op;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    switch (op) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            printf("Invalid operation\n");
            return 0;
    }

    printf("Result: %d\n", result);

    return 0;
}