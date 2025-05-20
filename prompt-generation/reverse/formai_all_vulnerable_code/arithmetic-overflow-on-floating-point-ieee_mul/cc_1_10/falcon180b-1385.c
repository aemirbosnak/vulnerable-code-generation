//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);

int main() {
    int choice;
    double num1, num2;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user for two numbers
    printf("Enter two numbers separated by a space: ");
    scanf("%lf %lf", &num1, &num2);

    // Display a menu of arithmetic operations
    printf("\nSelect an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    // Get the user's choice
    scanf("%d", &choice);

    // Perform the selected operation and display the result
    switch (choice) {
        case 1:
            printf("The result is: %.2lf\n", add(num1, num2));
            break;
        case 2:
            printf("The result is: %.2lf\n", subtract(num1, num2));
            break;
        case 3:
            printf("The result is: %.2lf\n", multiply(num1, num2));
            break;
        case 4:
            printf("The result is: %.2lf\n", divide(num1, num2));
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

// Function to add two numbers
double add(double num1, double num2) {
    return num1 + num2;
}

// Function to subtract two numbers
double subtract(double num1, double num2) {
    return num1 - num2;
}

// Function to multiply two numbers
double multiply(double num1, double num2) {
    return num1 * num2;
}

// Function to divide two numbers
double divide(double num1, double num2) {
    if (num2 == 0) {
        printf("Error: Division by zero.\n");
        exit(1);
    }
    return num1 / num2;
}