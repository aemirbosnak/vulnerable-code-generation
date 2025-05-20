//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Function declarations
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int modulus(int a, int b);

int main() {
    int choice, num1, num2;

    // Welcome message
    printf("Welcome to the medieval arithmetic program!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");

    // Get user choice
    scanf("%d", &choice);

    // Get two numbers from user
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);

    // Perform selected operation and display result
    switch(choice) {
        case 1:
            printf("The result is %d\n", add(num1, num2));
            break;
        case 2:
            printf("The result is %d\n", subtract(num1, num2));
            break;
        case 3:
            printf("The result is %d\n", multiply(num1, num2));
            break;
        case 4:
            if(num2 == 0) {
                printf("Cannot divide by zero.\n");
            }
            else {
                printf("The result is %d\n", divide(num1, num2));
            }
            break;
        case 5:
            printf("The result is %d\n", modulus(num1, num2));
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

// Function definitions
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
    return a / b;
}

int modulus(int a, int b) {
    return a % b;
}