//Code Llama-13B DATASET v1.0 Category: Temperature Converter ; Style: multiplayer
/*
 * Temperature Converter - Multiplayer
 *
 * This program allows users to convert temperatures between
 * Celsius, Fahrenheit, and Kelvin in a multiplayer style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the temperature conversions
typedef struct {
    char input_unit[10];
    double input_value;
    char output_unit[10];
    double output_value;
} conversion_t;

// Function to convert temperatures between Celsius and Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert temperatures between Celsius and Kelvin
double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert temperatures between Fahrenheit and Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to convert temperatures between Fahrenheit and Kelvin
double fahrenheit_to_kelvin(double fahrenheit) {
    return (fahrenheit + 459.67) * 5.0 / 9.0;
}

// Function to convert temperatures between Kelvin and Celsius
double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert temperatures between Kelvin and Fahrenheit
double kelvin_to_fahrenheit(double kelvin) {
    return (kelvin * 9.0 / 5.0) - 459.67;
}

// Function to convert temperatures from one unit to another
double convert_temperature(double input_value, char *input_unit, char *output_unit) {
    if (strcmp(input_unit, "C") == 0) {
        if (strcmp(output_unit, "F") == 0) {
            return celsius_to_fahrenheit(input_value);
        } else if (strcmp(output_unit, "K") == 0) {
            return celsius_to_kelvin(input_value);
        } else {
            return input_value;
        }
    } else if (strcmp(input_unit, "F") == 0) {
        if (strcmp(output_unit, "C") == 0) {
            return fahrenheit_to_celsius(input_value);
        } else if (strcmp(output_unit, "K") == 0) {
            return fahrenheit_to_kelvin(input_value);
        } else {
            return input_value;
        }
    } else if (strcmp(input_unit, "K") == 0) {
        if (strcmp(output_unit, "C") == 0) {
            return kelvin_to_celsius(input_value);
        } else if (strcmp(output_unit, "F") == 0) {
            return kelvin_to_fahrenheit(input_value);
        } else {
            return input_value;
        }
    } else {
        return input_value;
    }
}

// Main function
int main() {
    // Initialize the conversion structure
    conversion_t conversion;

    // Get the input temperature and unit
    printf("Enter the temperature: ");
    scanf("%lf", &conversion.input_value);
    printf("Enter the unit (C, F, or K): ");
    scanf("%s", conversion.input_unit);

    // Get the output unit
    printf("Enter the output unit (C, F, or K): ");
    scanf("%s", conversion.output_unit);

    // Convert the temperature
    conversion.output_value = convert_temperature(conversion.input_value, conversion.input_unit, conversion.output_unit);

    // Print the result
    printf("The temperature in %s is %f %s.\n", conversion.output_unit, conversion.output_value, conversion.output_unit);

    return 0;
}