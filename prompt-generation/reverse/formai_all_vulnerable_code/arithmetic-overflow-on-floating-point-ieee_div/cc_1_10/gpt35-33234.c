//FormAI DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h> // Standard input/output library
#include <stdlib.h> // Standard library
#include <math.h> // Math library

// Function declarations
void checkError(int code);
double divide(double a, double b);

int main() {
    double a, b, result;
    int error;
    
    printf("Enter first number: ");
    scanf("%lf", &a); // Read input from user
    printf("Enter second number: ");
    scanf("%lf", &b); // Read input from user
    
    // Call divide function and check for errors
    error = divide(a, b);
    checkError(error);
    
    // Calculate result
    result = sqrt(error); // Calculate square root of error
    
    // Output result
    printf("The square root of the error is %lf", result);
    
    return 0;
}

// Function to perform division
double divide(double a, double b) {
    if (b == 0) {
        // If denominator is 0, return error code
        return -1;
    }
    else {
        // Otherwise, return result of division
        return a / b;
    }
}

// Function to check for errors
void checkError(int code) {
    if (code == -1) {
        // If error code is -1, print error message and exit program
        printf("Error: Division by zero");
        exit(1);
    }
    else {
        // Otherwise, continue program execution
        return;
    }
}