//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define BUFFER_SIZE 100

void paranoid_print(const char *message) {
    printf("[!] %s\n", message);
}

int paranoid_input(double *value) {
    char buffer[BUFFER_SIZE];

    paranoid_print("Please enter a number:");
    fgets(buffer, BUFFER_SIZE, stdin);

    // Check if input is valid
    for (size_t i = 0; i < strlen(buffer); i++) {
        if ((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '.' && buffer[i] != '-' && buffer[i] != '\n') {
            paranoid_print("Invalid input detected! Only numbers, dots, and minus signs are allowed.");
            return 0; // Input is invalid
        }
    }

    // Convert to double
    *value = atof(buffer);
    return 1; // Input is valid
}

double safe_square_root(double number) {
    if (number < 0) {
        paranoid_print("Cannot compute the square root of a negative number!");
        exit(EXIT_FAILURE);
    }
    return sqrt(number);
}

double safe_division(double numerator, double denominator) {
    if (denominator == 0) {
        paranoid_print("Division by zero! Exiting program.");
        exit(EXIT_FAILURE);
    }
    return numerator / denominator;
}

int main() {
    double number, multiplier, numerator, denominator;
    double result;

    paranoid_print("Welcome to the Paranoid Math Program!");
    
    // Get the number for square root calculation
    if (!paranoid_input(&number)) {
        return 1;
    }
    
    // Compute square root
    result = safe_square_root(number);
    printf("[Result] The square root of %.2f is %.2f\n", number, result);

    // Get the multiplier value
    if (!paranoid_input(&multiplier)) {
        return 1;
    }

    // Multiply the square root by multiplier
    result *= multiplier;
    printf("[Result] The result after multiplying by %.2f is %.2f\n", multiplier, result);

    // Get numerator for division
    if (!paranoid_input(&numerator)) {
        return 1;
    }

    // Get denominator for division
    if (!paranoid_input(&denominator)) {
        return 1;
    }

    // Perform safe division
    result = safe_division(numerator, denominator);
    printf("[Result] The result of %.2f divided by %.2f is %.2f\n", numerator, denominator, result);

    // Final paranoia check
    paranoid_print("Thank you for using the Paranoid Math Program!");
    
    return 0;
}