//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function prototypes
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);
double kelvin_to_celsius(double kelvin);
double celsius_to_kelvin(double celsius);

int main() {
    char* input = NULL;
    char* unit = NULL;
    double value = 0;
    double converted_value = 0;
    char* converted_unit = NULL;

    printf("Temperature Converter\n");
    printf("Enter temperature value followed by unit (C/F/K): ");

    // Get user input
    if (fgets(input, 100, stdin) == NULL) {
        printf("Error: Failed to read input.\n");
        exit(1);
    }

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Parse input
    value = strtod(input, &unit);

    // Check if input is valid
    if (value <= 0) {
        printf("Error: Invalid input.\n");
        exit(1);
    }

    // Convert temperature
    if (unit[0] == 'C' || unit[0] == 'c') {
        converted_value = celsius_to_fahrenheit(value);
        converted_unit = "F";
    } else if (unit[0] == 'F' || unit[0] == 'f') {
        converted_value = fahrenheit_to_celsius(value);
        converted_unit = "C";
    } else if (unit[0] == 'K' || unit[0] == 'k') {
        converted_value = kelvin_to_celsius(value);
        converted_unit = "C";
    } else {
        printf("Error: Invalid unit.\n");
        exit(1);
    }

    // Print result
    printf("%.2f %c = %.2f %c\n", value, unit[0], converted_value, converted_unit[0]);

    return 0;
}

// Convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Convert Celsius to Kelvin
double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

// Convert Kelvin to Celsius
double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}