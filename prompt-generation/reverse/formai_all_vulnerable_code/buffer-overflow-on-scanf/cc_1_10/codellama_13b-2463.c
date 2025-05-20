//Code Llama-13B DATASET v1.0 Category: Temperature Converter ; Style: Linus Torvalds
/*
 * A unique C Temperature Converter example program in a Linus Torvalds style
 *
 * This program is a simple temperature converter that converts between
 * Celsius, Fahrenheit, and Kelvin. It uses a function to perform the
 * conversion and accepts input from the user in the form of a string.
 */

#include <stdio.h>

// Function to convert temperature from Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert temperature from Celsius to Kelvin
double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert temperature from Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Function to convert temperature from Fahrenheit to Kelvin
double fahrenheit_to_kelvin(double fahrenheit) {
    return ((fahrenheit - 32) / 1.8) + 273.15;
}

// Function to convert temperature from Kelvin to Celsius
double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert temperature from Kelvin to Fahrenheit
double kelvin_to_fahrenheit(double kelvin) {
    return ((kelvin - 273.15) * 1.8) + 32;
}

// Main function
int main() {
    char input[100];
    double temperature;

    // Prompt the user for input
    printf("Enter a temperature (in Celsius, Fahrenheit, or Kelvin): ");
    scanf("%s", input);

    // Convert the input to a double
    temperature = atof(input);

    // Perform the conversion
    if (strcmp(input, "C") == 0) {
        printf("Temperature in Fahrenheit: %.2f\n", celsius_to_fahrenheit(temperature));
        printf("Temperature in Kelvin: %.2f\n", celsius_to_kelvin(temperature));
    } else if (strcmp(input, "F") == 0) {
        printf("Temperature in Celsius: %.2f\n", fahrenheit_to_celsius(temperature));
        printf("Temperature in Kelvin: %.2f\n", fahrenheit_to_kelvin(temperature));
    } else if (strcmp(input, "K") == 0) {
        printf("Temperature in Celsius: %.2f\n", kelvin_to_celsius(temperature));
        printf("Temperature in Fahrenheit: %.2f\n", kelvin_to_fahrenheit(temperature));
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}