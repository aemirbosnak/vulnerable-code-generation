//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Function to convert Celsius to Kelvin
double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Fahrenheit to Kelvin
double fahrenheit_to_kelvin(double fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

// Function to convert Kelvin to Fahrenheit
double kelvin_to_fahrenheit(double kelvin) {
    return kelvin_to_celsius(kelvin) * 1.8 + 32;
}

int main() {
    char choice;
    double value;

    // Prompt user to enter temperature value and unit of measurement
    printf("Enter temperature value and unit of measurement (e.g. 25 C): ");
    scanf("%lf %c", &value, &choice);

    // Convert uppercase input to lowercase for case-insensitive comparison
    choice = tolower(choice);

    // Check if input is valid
    if (value <= 0) {
        printf("Invalid temperature value.\n");
        return 1;
    }
    if (choice!= 'c' && choice!= 'f' && choice!= 'k') {
        printf("Invalid unit of measurement.\n");
        return 1;
    }

    // Convert temperature based on user's choice
    switch (choice) {
        case 'c':
            printf("%.2lf C = %.2lf F = %.2lf K\n", value, celsius_to_fahrenheit(value), celsius_to_kelvin(value));
            break;
        case 'f':
            printf("%.2lf F = %.2lf C = %.2lf K\n", value, fahrenheit_to_celsius(value), fahrenheit_to_kelvin(value));
            break;
        case 'k':
            printf("%.2lf K = %.2lf C = %.2lf F\n", value, celsius_to_kelvin(value), kelvin_to_fahrenheit(value));
            break;
        default:
            printf("Invalid unit of measurement.\n");
            return 1;
    }

    return 0;
}