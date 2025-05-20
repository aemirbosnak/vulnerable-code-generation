//FormAI DATASET v1.0 Category: Math exercise ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int generateRandomNumber(int maxNumber);
int sum(int a, int b);
int difference(int a, int b);
double division(int a, int b);
int multiplication(int a, int b);

int main(void) {
    // Seed the random number generator
    srand(time(NULL));

    // Generate two random numbers between 1 and 10
    int num1 = generateRandomNumber(10);
    int num2 = generateRandomNumber(10);

    int choice;
    int result;

    // Loop until the user chooses to quit
    do {
        // Display options to the user
        printf("Choose an operation to perform (1-4):\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Divide\n");
        printf("4. Multiply\n");

        // Get the user's choice
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add
                result = sum(num1, num2);
                printf("The sum of %d and %d is %d\n", num1, num2, result);
                break;

            case 2: // Subtract
                result = difference(num1, num2);
                printf("The difference between %d and %d is %d\n", num1, num2, result);
                break;

            case 3: // Divide
                if (num2 == 0) {
                    printf("Cannot divide by zero!\n");
                } else {
                    double quotient = division(num1, num2);
                    printf("%d divided by %d is %.2f\n", num1, num2, quotient);
                }
                break;

            case 4: // Multiply
                result = multiplication(num1, num2);
                printf("The product of %d and %d is %d\n", num1, num2, result);
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }

        // Generate new random numbers for the next iteration
        num1 = generateRandomNumber(10);
        num2 = generateRandomNumber(10);

    } while (choice != 0);

    return 0;
}

// Function to generate a random number up to a maximum value
int generateRandomNumber(int maxNumber) {
    return rand() % maxNumber + 1;
}

// Function to add two numbers
int sum(int a, int b) {
    return a + b;
}

// Function to subtract two numbers
int difference(int a, int b) {
    return a - b;
}

// Function to divide two numbers
double division(int a, int b) {
    return (double)a / b;
}

// Function to multiply two numbers
int multiplication(int a, int b) {
    return a * b;
}