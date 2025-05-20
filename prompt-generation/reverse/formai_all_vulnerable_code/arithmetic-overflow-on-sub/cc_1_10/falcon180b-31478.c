//Falcon-180B DATASET v1.0 Category: Educational ; Style: retro
#include <stdio.h>

// Function to calculate the sum of two integers
int add(int num1, int num2) {
    return num1 + num2;
}

// Function to calculate the difference between two integers
int subtract(int num1, int num2) {
    return num1 - num2;
}

// Function to calculate the product of two integers
int multiply(int num1, int num2) {
    return num1 * num2;
}

// Function to calculate the quotient of two integers
int divide(int num1, int num2) {
    if (num2 == 0) {
        printf("Error: Division by zero\n");
        return 0;
    }
    return num1 / num2;
}

int main() {
    int num1, num2, choice;

    // Input two integers from user
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Display menu of arithmetic operations
    printf("\nMenu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");

    // Get user choice
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Perform arithmetic operation based on user choice
    switch (choice) {
        case 1:
            printf("\nResult: %d", add(num1, num2));
            break;
        case 2:
            printf("\nResult: %d", subtract(num1, num2));
            break;
        case 3:
            printf("\nResult: %d", multiply(num1, num2));
            break;
        case 4:
            printf("\nResult: %d", divide(num1, num2));
            break;
        case 5:
            printf("\nExiting...\n");
            break;
        default:
            printf("\nInvalid choice! Please enter again.\n");
    }

    return 0;
}