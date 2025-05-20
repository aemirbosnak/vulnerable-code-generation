//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (5.0 * (fahrenheit - 32.0)) / 9.0;
}

// Function to convert Celsius to Kelvin
double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Celsius to Rankine
double celsius_to_rankine(double celsius) {
    return celsius + 459.67;
}

// Function to convert Rankine to Celsius
double rankine_to_celsius(double rankine) {
    return rankine - 459.67;
}

int main() {
    double celsius, fahrenheit, kelvin, rankine;
    int choice;

    // Get user input for temperature type
    printf("Enter the temperature type:\n");
    printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n4. Rankine\n");
    scanf("%d", &choice);

    // Get user input for temperature value
    printf("Enter the temperature value:\n");
    scanf("%lf", &celsius);

    // Convert Celsius to other temperature scales
    switch(choice) {
        case 1:
            // Do nothing, since the input temperature is already in Celsius
            break;
        case 2:
            fahrenheit = celsius_to_fahrenheit(celsius);
            printf("%.2lf Celsius is equivalent to %.2lf Fahrenheit.\n", celsius, fahrenheit);
            break;
        case 3:
            kelvin = celsius_to_kelvin(celsius);
            printf("%.2lf Celsius is equivalent to %.2lf Kelvin.\n", celsius, kelvin);
            break;
        case 4:
            rankine = celsius_to_rankine(celsius);
            printf("%.2lf Celsius is equivalent to %.2lf Rankine.\n", celsius, rankine);
            break;
        default:
            printf("Invalid temperature type!\n");
    }

    return 0;
}