//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function prototypes
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);
double kelvin_to_celsius(double kelvin);
double celsius_to_kelvin(double celsius);
double rankine_to_celsius(double rankine);
double celsius_to_rankine(double celsius);

// Main function
int main() {
    char choice;
    double temperature;

    // Prompt user to select temperature conversion type
    printf("Select a temperature conversion type:\n");
    printf("C - Celsius to Fahrenheit\n");
    printf("F - Fahrenheit to Celsius\n");
    printf("K - Celsius to Kelvin\n");
    printf("R - Celsius to Rankine\n");
    scanf("%c", &choice);

    // Convert temperature based on user selection
    switch (choice) {
        case 'C':
        case 'c':
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit.\n", temperature, celsius_to_fahrenheit(temperature));
            break;
        case 'F':
        case 'f':
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius.\n", temperature, fahrenheit_to_celsius(temperature));
            break;
        case 'K':
        case 'k':
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            printf("%.2lf degrees Celsius is %.2lf Kelvin.\n", temperature, kelvin_to_celsius(temperature));
            break;
        case 'R':
        case 'r':
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            printf("%.2lf degrees Celsius is %.2lf Rankine.\n", temperature, rankine_to_celsius(temperature));
            break;
        default:
            printf("Invalid temperature conversion type.\n");
    }

    return 0;
}

// Celsius to Fahrenheit conversion function
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Fahrenheit to Celsius conversion function
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Celsius to Kelvin conversion function
double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

// Kelvin to Celsius conversion function
double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

// Celsius to Rankine conversion function
double celsius_to_rankine(double celsius) {
    return celsius + 459.67;
}

// Rankine to Celsius conversion function
double rankine_to_celsius(double rankine) {
    return rankine - 459.67;
}