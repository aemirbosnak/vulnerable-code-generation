//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: rigorous
/*
 * Temperature Converter
 *
 * This program converts temperature values between Celsius and Fahrenheit.
 *
 * Compile with:
 *
 *   gcc -Wall -Wextra -pedantic -std=c11 temperature_converter.c -o temperature_converter
 */

#include <stdio.h>
#include <stdlib.h>

// Constants
const double CELSIUS_TO_FAHRENHEIT_MULTIPLIER = 1.8;
const double FAHRENHEIT_TO_CELSIUS_MULTIPLIER = 0.5555555555555556;

// Function prototypes
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);

int main(void) {
    // Declare variables
    double temperature;
    char unit;

    // Get the temperature and unit from the user
    printf("Enter the temperature and unit (C for Celsius, F for Fahrenheit): ");
    scanf("%lf %c", &temperature, &unit);

    // Convert the temperature to the other unit
    switch (unit) {
        case 'C':
            temperature = celsius_to_fahrenheit(temperature);
            unit = 'F';
            break;
        case 'F':
            temperature = fahrenheit_to_celsius(temperature);
            unit = 'C';
            break;
        default:
            printf("Invalid unit. Please enter C for Celsius or F for Fahrenheit.\n");
            return EXIT_FAILURE;
    }

    // Print the converted temperature
    printf("The converted temperature is %.2lf %c.\n", temperature, unit);

    return EXIT_SUCCESS;
}

// Convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return celsius * CELSIUS_TO_FAHRENHEIT_MULTIPLIER + 32.0;
}

// Convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * FAHRENHEIT_TO_CELSIUS_MULTIPLIER;
}