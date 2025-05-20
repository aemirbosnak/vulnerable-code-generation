//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);
double kelvin_to_celsius(double kelvin);
double celsius_to_kelvin(double celsius);

int main() {
    char choice;
    double temperature;

    printf("Enter temperature unit to convert from (c/f/k): ");
    scanf("%c", &choice);

    printf("Enter temperature: ");
    scanf("%lf", &temperature);

    switch(choice) {
        case 'c':
        case 'C':
            printf("%.2lf Celsius is %.2lf Fahrenheit\n", temperature, celsius_to_fahrenheit(temperature));
            printf("%.2lf Celsius is %.2lf Kelvin\n", temperature, kelvin_to_celsius(temperature));
            break;
        case 'f':
        case 'F':
            printf("%.2lf Fahrenheit is %.2lf Celsius\n", temperature, fahrenheit_to_celsius(temperature));
            printf("%.2lf Fahrenheit is %.2lf Kelvin\n", temperature, (temperature + 459.67));
            break;
        case 'k':
        case 'K':
            printf("%.2lf Kelvin is %.2lf Celsius\n", temperature, kelvin_to_celsius(temperature));
            printf("%.2lf Kelvin is %.2lf Fahrenheit\n", temperature, (temperature - 273.15));
            break;
        default:
            printf("Invalid temperature unit\n");
    }

    return 0;
}

// Converts Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Converts Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Converts Celsius to Kelvin
double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

// Converts Kelvin to Celsius
double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}