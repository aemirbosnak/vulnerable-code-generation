//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function declarations
double convert_fahrenheit_to_celsius(double fahrenheit);
double convert_celsius_to_fahrenheit(double celsius);
double convert_kelvin_to_celsius(double kelvin);
double convert_celsius_to_kelvin(double celsius);

// Function to convert Fahrenheit to Celsius
double convert_fahrenheit_to_celsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

// Function to convert Celsius to Fahrenheit
double convert_celsius_to_fahrenheit(double celsius) {
    double fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}

// Function to convert Kelvin to Celsius
double convert_kelvin_to_celsius(double kelvin) {
    double celsius = kelvin - 273.15;
    return celsius;
}

// Function to convert Celsius to Kelvin
double convert_celsius_to_kelvin(double celsius) {
    double kelvin = celsius + 273.15;
    return kelvin;
}

int main() {
    int choice;
    double temperature, converted_temperature;

    // Prompt user for temperature input
    printf("Enter the temperature in degrees Fahrenheit, Celsius, or Kelvin: ");
    scanf("%lf", &temperature);

    // Prompt user for conversion choice
    printf("\nEnter the conversion choice (1 for Fahrenheit to Celsius, 2 for Celsius to Fahrenheit, 3 for Celsius to Kelvin, 4 for Kelvin to Celsius): ");
    scanf("%d", &choice);

    // Convert temperature based on user choice
    switch(choice) {
        case 1:
            converted_temperature = convert_fahrenheit_to_celsius(temperature);
            printf("\n%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temperature, converted_temperature);
            break;
        case 2:
            converted_temperature = convert_celsius_to_fahrenheit(temperature);
            printf("\n%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, converted_temperature);
            break;
        case 3:
            converted_temperature = convert_celsius_to_kelvin(temperature);
            printf("\n%.2lf degrees Celsius is equal to %.2lf Kelvin.\n", temperature, converted_temperature);
            break;
        case 4:
            converted_temperature = convert_kelvin_to_celsius(temperature);
            printf("\n%.2lf Kelvin is equal to %.2lf degrees Celsius.\n", temperature, converted_temperature);
            break;
        default:
            printf("\nInvalid choice. Please choose a valid conversion option.\n");
            break;
    }

    return 0;
}