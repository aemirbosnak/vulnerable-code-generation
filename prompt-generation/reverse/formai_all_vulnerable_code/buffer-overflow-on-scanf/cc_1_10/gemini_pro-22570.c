//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define conversion functions
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Define temperature ranges
#define MIN_TEMPERATURE -273.15
#define MAX_TEMPERATURE 5000.00

// Define unit conversion ratios
#define CELSIUS_TO_KELVIN 273.15
#define FAHRENHEIT_TO_KELVIN 459.67

// Main function
int main() {
    // Display program title
    printf("\nTemperature Converter\n");
    printf("=======================\n\n");

    // Get input from user
    double temperature;
    char unit;
    char target_unit;

    printf("Enter temperature: ");
    scanf("%lf", &temperature);

    printf("Enter unit (C/F/K): ");
    scanf(" %c", &unit);

    printf("Convert to unit (C/F/K): ");
    scanf(" %c", &target_unit);

    // Check if input is valid
    if (temperature < MIN_TEMPERATURE || temperature > MAX_TEMPERATURE) {
        printf("Invalid temperature. Please enter a temperature between -273.15 and 5000.00.\n");
        return EXIT_FAILURE;
    }

    if (unit != 'C' && unit != 'F' && unit != 'K') {
        printf("Invalid unit. Please enter C for Celsius, F for Fahrenheit, or K for Kelvin.\n");
        return EXIT_FAILURE;
    }

    if (target_unit != 'C' && target_unit != 'F' && target_unit != 'K') {
        printf("Invalid target unit. Please enter C for Celsius, F for Fahrenheit, or K for Kelvin.\n");
        return EXIT_FAILURE;
    }

    // Convert temperature to target unit
    double converted_temperature;

    switch (unit) {
        case 'C':
            switch (target_unit) {
                case 'C':
                    converted_temperature = temperature;
                    break;
                case 'F':
                    converted_temperature = fahrenheit_to_celsius(temperature);
                    break;
                case 'K':
                    converted_temperature = temperature + CELSIUS_TO_KELVIN;
                    break;
            }
            break;
        case 'F':
            switch (target_unit) {
                case 'C':
                    converted_temperature = celsius_to_fahrenheit(temperature);
                    break;
                case 'F':
                    converted_temperature = temperature;
                    break;
                case 'K':
                    converted_temperature = temperature + FAHRENHEIT_TO_KELVIN;
                    break;
            }
            break;
        case 'K':
            switch (target_unit) {
                case 'C':
                    converted_temperature = temperature - CELSIUS_TO_KELVIN;
                    break;
                case 'F':
                    converted_temperature = celsius_to_fahrenheit(temperature - CELSIUS_TO_KELVIN);
                    break;
                case 'K':
                    converted_temperature = temperature;
                    break;
            }
            break;
    }

    // Display converted temperature
    printf("Converted temperature: %.2f %c\n", converted_temperature, target_unit);

    return EXIT_SUCCESS;
}