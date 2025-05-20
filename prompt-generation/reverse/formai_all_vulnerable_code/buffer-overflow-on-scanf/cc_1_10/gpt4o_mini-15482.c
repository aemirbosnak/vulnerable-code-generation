//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Custom error handling function
void handleError(const char *errorMessage) {
    fprintf(stderr, "Error: %s\n", errorMessage);
    exit(EXIT_FAILURE);
}

// Function to calculate square root with error handling for negative inputs
double safeSqrt(double number) {
    if (number < 0) {
        handleError("Cannot compute the square root of a negative number.");
    }
    return sqrt(number);
}

// Function to read a double value from the user
double readDouble(const char *prompt) {
    double value;
    printf("%s", prompt);
    
    if (scanf("%lf", &value) != 1) {
        handleError("Invalid input. Please enter a valid double number.");
    }

    return value;
}

// Function to perform error-free division
double safeDivide(double numerator, double denominator) {
    if (denominator == 0) {
        handleError("Division by zero is not allowed.");
    }
    return numerator / denominator;
}

int main() {
    // Step 1: Read the first number for square root calculation
    double number = readDouble("Enter a number to compute its square root: ");
    double resultSqrt = safeSqrt(number);
    printf("The square root of %.2f is %.2f\n", number, resultSqrt);

    // Step 2: Read two numbers for division
    double numerator = readDouble("Enter the numerator for division: ");
    double denominator = readDouble("Enter the denominator for division: ");
    
    double resultDivision = safeDivide(numerator, denominator);
    printf("The result of %.2f divided by %.2f is %.2f\n", numerator, denominator, resultDivision);
    
    // Step 3: Read numbers from the user to fill an array and calculate the average
    int size;
    printf("Enter the number of elements you wish to input: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        handleError("Invalid input. Size must be a positive integer.");
    }

    double *numbers = (double *)malloc(size * sizeof(double));
    if (!numbers) {
        handleError("Memory allocation failed.");
    }

    for (int i = 0; i < size; i++) {
        numbers[i] = readDouble("Enter a number: ");
    }

    // Calculate average
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    double average = sum / size;
    printf("The average of the entered numbers is %.2f\n", average);

    // Free allocated memory
    free(numbers);
    
    return EXIT_SUCCESS;
}