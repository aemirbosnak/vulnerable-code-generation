//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: calm
#include <stdio.h>

// Function prototypes
int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

// Main function
int main() {
    int num1, num2, result, choice;

    printf("Enter two integers:\n");
    scanf("%d %d", &num1, &num2);

    printf("Enter your choice:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            result = add(num1, num2);
            printf("Result: %d\n", result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("Result: %d\n", result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("Result: %d\n", result);
            break;
        case 4:
            result = divide(num1, num2);
            printf("Result: %d\n", result);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

// Function to add two integers
int add(int x, int y) {
    return x + y;
}

// Function to subtract two integers
int subtract(int x, int y) {
    return x - y;
}

// Function to multiply two integers
int multiply(int x, int y) {
    return x * y;
}

// Function to divide two integers
int divide(int x, int y) {
    if(y == 0) {
        printf("Division by zero is not allowed!\n");
        return 0;
    }
    return x / y;
}