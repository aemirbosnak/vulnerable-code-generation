//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool is_valid_temperature(double temp) {
    return temp >= -273.15 && temp <= 1000;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

int main() {
    double temperature;
    char unit;

    printf("Enter a temperature in Celsius, Fahrenheit, or Kelvin: ");
    scanf("%lf %c", &temperature, &unit);

    // Convert temperature to Celsius
    switch (unit) {
        case 'C':
        case 'c':
            break;
        case 'F':
        case 'f':
            temperature = celsius_to_fahrenheit(temperature);
            printf("%.2lf degrees Celsius is equivalent to %.2lf degrees Fahrenheit.\n", temperature, temperature);
            break;
        case 'K':
        case 'k':
            temperature = kelvin_to_celsius(temperature);
            printf("%.2lf degrees Celsius is equivalent to %.2lf Kelvin.\n", temperature, temperature);
            break;
        default:
            printf("Invalid unit. Please enter Celsius, Fahrenheit, or Kelvin.\n");
            return 1;
    }

    // Convert Celsius to other units
    printf("%.2lf degrees Celsius is equivalent to:\n", temperature);
    printf("- %.2lf degrees Fahrenheit\n", fahrenheit_to_celsius(temperature));
    printf("- %.2lf Kelvin\n", celsius_to_kelvin(temperature));

    return 0;
}