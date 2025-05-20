//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: optimized
#include <stdio.h>
#include <math.h>

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two numbers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two numbers
int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Cannot divide by zero");
        return 0;
    }

    return a / b;
}

int main() {
    int num1, num2, choice;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n");

    while (1) {
        printf("Enter your choice (1-%d): ", 5);
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Result of addition: %d\n", add(num1, num2));
                break;
            case 2:
                printf("Result of subtraction: %d\n", subtract(num1, num2));
                break;
            case 3:
                printf("Result of multiplication: %d\n", multiply(num1, num2));
                break;
            case 4:
                printf("Result of division: %f\n", divide(num1, num2));
                break;
            case 5:
                return 0;
            default:
                printf("Invalid input. Try again.\n");
        }
    }

    return 0;
}