//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototypes
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
double kelvinToCelsius(double kelvin);
double celsiusToKelvin(double celsius);

int main() {
    char choice;
    double temperature;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please choose a temperature unit:\n");
    printf("C - Celsius\n");
    printf("F - Fahrenheit\n");
    printf("K - Kelvin\n");
    scanf(" %c", &choice);

    printf("Enter a temperature value: ");
    scanf("%lf", &temperature);

    switch (choice) {
        case 'C':
        case 'c':
            printf("%.2lf degrees Celsius is equal to:\n", temperature);
            printf("%.2lf degrees Fahrenheit\n", celsiusToFahrenheit(temperature));
            printf("%.2lf degrees Kelvin\n", celsiusToKelvin(temperature));
            break;
        case 'F':
        case 'f':
            printf("%.2lf degrees Fahrenheit is equal to:\n", temperature);
            printf("%.2lf degrees Celsius\n", fahrenheitToCelsius(temperature));
            printf("%.2lf degrees Kelvin\n", (temperature + 459.67) * 5/9);
            break;
        case 'K':
        case 'k':
            printf("%.2lf degrees Kelvin is equal to:\n", temperature);
            printf("%.2lf degrees Celsius\n", kelvinToCelsius(temperature));
            printf("%.2lf degrees Fahrenheit\n", (temperature - 273.15) * 9/5);
            break;
        default:
            printf("Invalid temperature unit.\n");
    }

    return 0;
}

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