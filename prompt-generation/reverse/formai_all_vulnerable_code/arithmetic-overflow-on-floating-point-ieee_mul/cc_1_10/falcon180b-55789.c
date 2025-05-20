//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (5.0/9.0) * (fahrenheit - 32);
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (9.0/5.0) * celsius + 32;
}

// Function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

int main() {

    // Prompt user for temperature input
    double temperature;
    printf("Enter temperature: ");
    scanf("%lf", &temperature);

    // Prompt user for temperature unit input
    char unit;
    printf("Enter temperature unit (F/C/K): ");
    scanf(" %c", &unit);

    // Convert temperature based on user input
    switch (unit) {
        case 'F':
            printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius.\n", temperature, fahrenheitToCelsius(temperature));
            break;
        case 'C':
            printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit.\n", temperature, celsiusToFahrenheit(temperature));
            break;
        case 'K':
            printf("%.2lf degrees Celsius is %.2lf Kelvin.\n", temperature, kelvinToCelsius(temperature));
            break;
        default:
            printf("Invalid temperature unit.\n");
            break;
    }

    return 0;
}