//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* function prototypes */
double celsiusToFahrenheit(double);
double fahrenheitToCelsius(double);
double kelvinToCelsius(double);
double celsiusToKelvin(double);

int main() {
    double temperature, convertedTemperature;
    char choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter the temperature you want to convert: ");
    scanf("%lf", &temperature);

    printf("Please choose the unit of measurement you want to convert from:\n");
    printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n");
    scanf(" %c", &choice);

    switch (choice) {
        case '1':
            printf("You entered %.2lf degrees Celsius.\n", temperature);
            convertedTemperature = celsiusToFahrenheit(temperature);
            printf("That's %.2lf degrees Fahrenheit.\n", convertedTemperature);
            break;
        case '2':
            printf("You entered %.2lf degrees Fahrenheit.\n", temperature);
            convertedTemperature = fahrenheitToCelsius(temperature);
            printf("That's %.2lf degrees Celsius.\n", convertedTemperature);
            break;
        case '3':
            printf("You entered %.2lf degrees Kelvin.\n", temperature);
            convertedTemperature = kelvinToCelsius(temperature);
            printf("That's %.2lf degrees Celsius.\n", convertedTemperature);
            break;
        default:
            printf("Invalid choice. Please choose from 1, 2, or 3.\n");
            break;
    }

    return 0;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}