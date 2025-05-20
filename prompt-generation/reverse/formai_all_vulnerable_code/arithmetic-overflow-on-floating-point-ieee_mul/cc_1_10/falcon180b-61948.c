//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Function prototypes
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);
double kelvin_to_celsius(double kelvin);
double celsius_to_kelvin(double celsius);

// Main function
int main() {
    char choice;
    double temperature;
    int valid_input = 0;

    printf("Welcome to the Temperature Converter!\n");

    // Loop until valid input is provided
    while (!valid_input) {
        printf("Please enter a temperature value followed by the unit (C, F, or K): ");
        if (scanf("%lf%c", &temperature, &choice)!= 2) {
            printf("Invalid input. Please try again.\n");
        } else {
            switch (choice) {
                case 'C':
                case 'c':
                    printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, celsius_to_fahrenheit(temperature));
                    valid_input = 1;
                    break;
                case 'F':
                case 'f':
                    printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temperature, fahrenheit_to_celsius(temperature));
                    valid_input = 1;
                    break;
                case 'K':
                case 'k':
                    printf("%.2lf degrees Celsius is equal to %.2lf Kelvin.\n", temperature, kelvin_to_celsius(temperature));
                    valid_input = 1;
                    break;
                default:
                    printf("Invalid unit. Please try again.\n");
            }
        }
    }

    return 0;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}

// Function to convert Celsius to Kelvin
double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}