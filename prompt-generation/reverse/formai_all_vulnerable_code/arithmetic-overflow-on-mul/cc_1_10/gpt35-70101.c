//FormAI DATASET v1.0 Category: Arithmetic ; Style: calm
#include <stdio.h>

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two integers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two integers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two integers
float divide(int a, int b) {
    return (float)a / (float)b;
}

int main() {
    int num1, num2;
    char operator;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch(operator) {
        case '+':
            printf("%d + %d = %d", num1, num2, add(num1, num2));
            break;
        case '-':
            printf("%d - %d = %d", num1, num2, subtract(num1, num2));
            break;
        case '*':
            printf("%d * %d = %d", num1, num2, multiply(num1, num2));
            break;
        case '/':
            if(num2 == 0) {
                printf("Cannot divide by zero");
            } else {
                printf("%d / %d = %.2f", num1, num2, divide(num1, num2));
            }
            break;
        default:
            printf("Invalid operator");
    }

    return 0;
}