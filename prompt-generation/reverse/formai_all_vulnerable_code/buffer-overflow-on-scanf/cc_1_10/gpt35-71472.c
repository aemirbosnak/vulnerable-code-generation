//FormAI DATASET v1.0 Category: Calculator ; Style: inquisitive
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
        printf("Undefined\n");
        return 0;
    } else {
        return a / b;
    }
}

int main() {
    printf("Welcome to the Calculator Program!\n");
    int a, b;
    char operation;
    printf("Enter the first integer: ");
    scanf("%d", &a);
    printf("Enter the operation (+,-,*,/): ");
    scanf(" %c", &operation);
    printf("Enter the second integer: ");
    scanf("%d", &b);
    int result;
    switch(operation) {
        case '+':
            result = add(a, b);
            printf("%d + %d = %d\n", a, b, result);
            break;
        case '-':
            result = subtract(a, b);
            printf("%d - %d = %d\n", a, b, result);
            break;
        case '*':
            result = multiply(a, b);
            printf("%d * %d = %d\n", a, b, result);
            break;
        case '/':
            result = divide(a, b);
            printf("%d / %d = %d\n", a, b, result);
            break;
        default:
            printf("Invalid operation\n");
    }
    printf("Thank you for using the Calculator Program!\n");
    return 0;
}