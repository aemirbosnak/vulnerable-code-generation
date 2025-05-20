//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: Romeo and Juliet
#include <stdio.h>

// Define the two lovers, Romeo and Juliet
#define ROMEO 0
#define JULIET 1

// Define the temperature units
#define CELSIUS 0
#define FAHRENHEIT 1

// Define the conversion functions
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);

// Define the main function
int main() {
    // Declare the variables
    double temperature;
    int unit;
    char lover;

    // Get the user input
    printf("Enter the temperature: ");
    scanf("%lf", &temperature);
    printf("Enter the unit (C for Celsius, F for Fahrenheit): ");
    scanf(" %c", &lover);

    // Convert the temperature to the other unit
    switch (lover) {
        case 'C':
            temperature = celsius_to_fahrenheit(temperature);
            unit = FAHRENHEIT;
            break;
        case 'F':
            temperature = fahrenheit_to_celsius(temperature);
            unit = CELSIUS;
            break;
        default:
            printf("Invalid unit");
            return 1;
    }

    // Print the result
    printf("The temperature in the other unit is: %.2f %s\n", temperature, unit == CELSIUS ? "Celsius" : "Fahrenheit");

    return 0;
}

// Define the conversion functions
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}