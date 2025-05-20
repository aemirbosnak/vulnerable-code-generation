//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void convert_celsius_to_fahrenheit(double celsius);
void convert_fahrenheit_to_celsius(double fahrenheit);
void convert_celsius_to_kelvin(double celsius);
void convert_kelvin_to_celsius(double kelvin);

int main() {
    int choice;
    double temperature;

    printf("Welcome to the Temperature Converter!\n\n");
    printf("Please enter your choice:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    scanf("%d", &choice);

    printf("Please enter the temperature: ");
    scanf("%lf", &temperature);

    switch (choice) {
        case 1:
            convert_celsius_to_fahrenheit(temperature);
            break;
        case 2:
            convert_fahrenheit_to_celsius(temperature);
            break;
        case 3:
            convert_celsius_to_kelvin(temperature);
            break;
        case 4:
            convert_kelvin_to_celsius(temperature);
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    return 0;
}

// Function to convert Celsius to Fahrenheit
void convert_celsius_to_fahrenheit(double celsius) {
    double fahrenheit;

    fahrenheit = (celsius * 9/5) + 32;

    printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", celsius, fahrenheit);
}

// Function to convert Fahrenheit to Celsius
void convert_fahrenheit_to_celsius(double fahrenheit) {
    double celsius;

    celsius = (fahrenheit - 32) * 5/9;

    printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", fahrenheit, celsius);
}

// Function to convert Celsius to Kelvin
void convert_celsius_to_kelvin(double celsius) {
    double kelvin;

    kelvin = celsius + 273.15;

    printf("%.2lf Celsius is equal to %.2lf Kelvin.\n", celsius, kelvin);
}

// Function to convert Kelvin to Celsius
void convert_kelvin_to_celsius(double kelvin) {
    double celsius;

    celsius = kelvin - 273.15;

    printf("%.2lf Kelvin is equal to %.2lf Celsius.\n", kelvin, celsius);
}