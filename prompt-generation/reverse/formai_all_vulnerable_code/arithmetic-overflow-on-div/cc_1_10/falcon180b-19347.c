//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>

// Function to perform addition
int add(int a, int b) {
    return a + b;
}

// Function to perform subtraction
int subtract(int a, int b) {
    return a - b;
}

// Function to perform multiplication
int multiply(int a, int b) {
    return a * b;
}

// Function to perform division
int divide(int a, int b) {
    if (b == 0) {
        printf("Division by zero is not allowed.\n");
        return 0;
    }
    return a / b;
}

// Function to perform modulus
int modulus(int a, int b) {
    if (b == 0) {
        printf("Division by zero is not allowed.\n");
        return 0;
    }
    return a % b;
}

// Function to perform exponentiation
int exponentiate(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

int main() {
    int num1, num2, result;
    char operation;

    // Get user input for numbers and operation
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the operation (+, -, *, /, %%, ^): ");
    scanf(" %c", &operation);

    // Perform the operation and print the result
    switch (operation) {
        case '+':
            result = add(num1, num2);
            printf("The result is: %d\n", result);
            break;
        case '-':
            result = subtract(num1, num2);
            printf("The result is: %d\n", result);
            break;
        case '*':
            result = multiply(num1, num2);
            printf("The result is: %d\n", result);
            break;
        case '/':
            result = divide(num1, num2);
            printf("The result is: %d\n", result);
            break;
        case '%':
            result = modulus(num1, num2);
            printf("The result is: %d\n", result);
            break;
        case '^':
            result = exponentiate(num1, num2);
            printf("The result is: %d\n", result);
            break;
        default:
            printf("Invalid operation.\n");
    }

    return 0;
}