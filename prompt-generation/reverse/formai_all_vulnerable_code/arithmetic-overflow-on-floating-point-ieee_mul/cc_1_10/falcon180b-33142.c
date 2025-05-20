//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);
double kelvin_to_celsius(double kelvin);
double celsius_to_kelvin(double celsius);

int main() {
    int choice;
    double temperature;

    printf("Welcome to the Surrealist Temperature Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, celsius_to_fahrenheit(temperature));
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temperature, fahrenheit_to_celsius(temperature));
            break;
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            printf("%.2lf degrees Celsius is equal to %.2lf Kelvin.\n", temperature, celsius_to_kelvin(temperature));
            break;
        case 4:
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &temperature);
            printf("%.2lf Kelvin is equal to %.2lf degrees Celsius.\n", temperature, kelvin_to_celsius(temperature));
            break;
        default:
            printf("Invalid choice! Please choose a valid option.\n");
    }

    return 0;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    double fahrenheit;

    fahrenheit = (celsius * 1.8) + 32;

    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    double celsius;

    celsius = (fahrenheit - 32) / 1.8;

    return celsius;
}

// Function to convert Celsius to Kelvin
double celsius_to_kelvin(double celsius) {
    double kelvin;

    kelvin = celsius + 273.15;

    return kelvin;
}

// Function to convert Kelvin to Celsius
double kelvin_to_celsius(double kelvin) {
    double celsius;

    celsius = kelvin - 273.15;

    return celsius;
}