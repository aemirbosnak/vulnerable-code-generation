//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

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
    if (y == 0) {
        printf("Error: Division by zero is not allowed.\n");
        exit(1);
    }
    return x / y;
}

int main() {
    int num1, num2, choice;

    // Post-apocalyptic introduction
    printf("In the desolate wasteland of a world long gone,\n");
    printf("where the remnants of civilization struggle to survive,\n");
    printf("a lone programmer must use their skills to calculate\n");
    printf("the resources needed to rebuild society.\n\n");

    // Get user input for first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get user input for second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get user input for operation
    printf("\nSelect an operation:\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    scanf("%d", &choice);

    // Perform selected operation and display result
    switch (choice) {
        case 1:
            printf("Result: %d\n", add(num1, num2));
            break;
        case 2:
            printf("Result: %d\n", subtract(num1, num2));
            break;
        case 3:
            printf("Result: %d\n", multiply(num1, num2));
            break;
        case 4:
            printf("Result: %d\n", divide(num1, num2));
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}