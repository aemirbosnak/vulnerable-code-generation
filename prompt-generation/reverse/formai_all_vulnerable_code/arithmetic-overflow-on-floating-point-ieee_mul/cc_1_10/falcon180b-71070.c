//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}

// Function to get user input for temperature and unit
double getTemperature(char unit) {
    double temperature;
    printf("Enter the temperature in %c: ", unit);
    if (scanf("%lf", &temperature)!= 1) {
        printf("Invalid input. Please enter a valid number.\n");
        exit(1);
    }
    return temperature;
}

int main() {
    char unit;

    // Ask user for temperature and unit
    printf("Welcome to the Sherlock Holmes Temperature Converter!\n");
    printf("Please enter the temperature you wish to convert and its unit (C or F): ");
    scanf(" %c", &unit);

    // Convert temperature
    double temperature = getTemperature(unit);
    double result;

    if (unit == 'C' || unit == 'c') {
        result = celsiusToFahrenheit(temperature);
        printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, result);
    } else if (unit == 'F' || unit == 'f') {
        result = fahrenheitToCelsius(temperature);
        printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temperature, result);
    } else {
        printf("Invalid unit. Please enter C or F.\n");
        exit(1);
    }

    return 0;
}