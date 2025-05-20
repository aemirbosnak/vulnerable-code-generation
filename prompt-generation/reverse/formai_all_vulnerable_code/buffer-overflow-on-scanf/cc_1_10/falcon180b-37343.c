//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    double fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

// Function to convert Celsius to Kelvin
double celsius_to_kelvin(double celsius) {
    double kelvin = celsius + 273.15;
    return kelvin;
}

// Function to convert Fahrenheit to Kelvin
double fahrenheit_to_kelvin(double fahrenheit) {
    double celsius = fahrenheit_to_celsius(fahrenheit);
    double kelvin = celsius + 273.15;
    return kelvin;
}

// Function to convert Kelvin to Celsius
double kelvin_to_celsius(double kelvin) {
    double celsius = kelvin - 273.15;
    return celsius;
}

// Function to convert Kelvin to Fahrenheit
double kelvin_to_fahrenheit(double kelvin) {
    double celsius = kelvin - 273.15;
    double fahrenheit = celsius_to_fahrenheit(celsius);
    return fahrenheit;
}

int main() {
    double temperature;
    char input_unit[10], output_unit[10];

    // Get user input for temperature and units
    printf("Enter the temperature: ");
    scanf("%lf", &temperature);
    printf("Enter the input units (C/F/K): ");
    scanf("%s", input_unit);

    // Convert temperature based on input units
    if (strcmp(input_unit, "C") == 0) {
        printf("%.2lf Celsius is %.2lf Fahrenheit and %.2lf Kelvin.\n", temperature, celsius_to_fahrenheit(temperature), celsius_to_kelvin(temperature));
    } else if (strcmp(input_unit, "F") == 0) {
        printf("%.2lf Fahrenheit is %.2lf Celsius and %.2lf Kelvin.\n", temperature, fahrenheit_to_celsius(temperature), fahrenheit_to_kelvin(temperature));
    } else if (strcmp(input_unit, "K") == 0) {
        printf("%.2lf Kelvin is %.2lf Celsius and %.2lf Fahrenheit.\n", temperature, kelvin_to_celsius(temperature), kelvin_to_fahrenheit(temperature));
    } else {
        printf("Invalid input units.\n");
    }

    return 0;
}