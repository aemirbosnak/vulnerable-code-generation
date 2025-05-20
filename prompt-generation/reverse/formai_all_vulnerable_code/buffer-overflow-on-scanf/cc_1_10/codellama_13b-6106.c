//Code Llama-13B DATASET v1.0 Category: Temperature Converter ; Style: sophisticated
/*
 * Temperature Converter Example Program
 *
 * This program converts temperature values from one scale to another.
 * Supported scales: Celsius, Fahrenheit, and Kelvin.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the temperature scales
enum TemperatureScale {
    CELSIUS,
    FAHRENHEIT,
    KELVIN
};

// Define the temperature conversion functions
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Define the main function
int main() {
    // Declare variables
    double temperature;
    enum TemperatureScale scale;

    // Get the temperature and scale from the user
    printf("Enter the temperature: ");
    scanf("%lf", &temperature);
    printf("Enter the temperature scale (C, F, or K): ");
    scanf("%c", &scale);

    // Convert the temperature to the desired scale
    switch (scale) {
        case CELSIUS:
            temperature = celsiusToFahrenheit(temperature);
            break;
        case FAHRENHEIT:
            temperature = fahrenheitToCelsius(temperature);
            break;
        case KELVIN:
            temperature = kelvinToCelsius(temperature);
            break;
        default:
            printf("Invalid scale entered.\n");
            return 1;
    }

    // Print the converted temperature
    printf("The temperature is %f degrees Celsius.\n", temperature);

    return 0;
}