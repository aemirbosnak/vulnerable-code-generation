//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

// Function Prototypes
double safeDivision(double numerator, double denominator);
void calculateSquareRoot(double value);
void handleError(int errorCode);

int main() {
    double numerator, denominator, result, value;

    printf("Welcome to the Mathematical Operations Program!\n");

    // Input for division
    printf("Enter numerator for division: ");
    if (scanf("%lf", &numerator) != 1) {
        handleError(1);
        return 1;
    }

    printf("Enter denominator for division: ");
    if (scanf("%lf", &denominator) != 1) {
        handleError(1);
        return 1;
    }

    // Safe Division
    result = safeDivision(numerator, denominator);
    if (result != -1) {
        printf("Result of division: %.2lf\n", result);
    }

    // Input for square root
    printf("Enter a number to calculate its square root: ");
    if (scanf("%lf", &value) != 1) {
        handleError(1);
        return 1;
    }

    // Calculating Square Root
    calculateSquareRoot(value);

    printf("Thank you for using the program!\n");
    return 0;
}

double safeDivision(double numerator, double denominator) {
    if (denominator == 0) {
        handleError(2);
        return -1;
    }
    return numerator / denominator;
}

void calculateSquareRoot(double value) {
    if (value < 0) {
        handleError(3);
        return;
    }
    double result = sqrt(value);
    printf("Square root of %.2lf is %.2lf\n", value, result);
}

void handleError(int errorCode) {
    switch (errorCode) {
        case 1:
            fprintf(stderr, "Error: Invalid input. Please enter numeric values.\n");
            break;
        case 2:
            fprintf(stderr, "Error: Division by zero is undefined.\n");
            break;
        case 3:
            fprintf(stderr, "Error: Cannot calculate the square root of a negative number.\n");
            break;
        default:
            fprintf(stderr, "Error: An unknown error has occurred.\n");
    }
    exit(errorCode);
}