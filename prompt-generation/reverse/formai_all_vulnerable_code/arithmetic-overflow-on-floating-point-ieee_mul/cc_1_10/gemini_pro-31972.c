//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

// Function to get a valid input from the user
double getValidInput(char *prompt) {
    char input[MAX_INPUT_LENGTH];
    double value;

    while (1) {
        printf("%s", prompt);
        fgets(input, MAX_INPUT_LENGTH, stdin);

        // Check if the input is a valid number
        if (sscanf(input, "%lf", &value) == 1) {
            return value;
        } else {
            printf("Invalid input. Please enter a valid number.\n");
        }
    }
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Main function
int main() {
    // Declare variables
    char input[MAX_INPUT_LENGTH];
    double temperature;
    int conversionType;

    // Get the input from the user
    printf("Enter the temperature to be converted: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    temperature = atof(input);

    // Get the conversion type from the user
    printf("Enter the conversion type (1 for Celsius to Fahrenheit, 2 for Fahrenheit to Celsius): ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    conversionType = atoi(input);

    // Perform the conversion
    if (conversionType == 1) {
        temperature = celsiusToFahrenheit(temperature);
    } else if (conversionType == 2) {
        temperature = fahrenheitToCelsius(temperature);
    } else {
        printf("Invalid conversion type. Please enter 1 for Celsius to Fahrenheit or 2 for Fahrenheit to Celsius.\n");
        return EXIT_FAILURE;
    }

    // Print the result
    printf("The converted temperature is: %.2f\n", temperature);

    return EXIT_SUCCESS;
}