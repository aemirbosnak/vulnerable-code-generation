//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    double temperature, converted_temperature;
    char choice;
    int valid_input = 0;

    // Cyberpunk intro
    printf("Welcome to the Cyberpunk Temperature Converter.\n");
    printf("In a world where technology reigns supreme,\n");
    printf("we bring you the power to convert temperatures\n");
    printf("between Celsius and Fahrenheit.\n\n");

    // Loop until valid input is provided
    while (!valid_input) {
        printf("Enter the temperature you want to convert: ");
        if (scanf("%lf", &temperature) == 1) {
            valid_input = 1;
        } else {
            printf("Invalid input. Please enter a valid temperature.\n");
            fflush(stdin);
        }
    }

    // Ask the user which conversion they want
    printf("Choose the conversion you want:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf(" %c", &choice);

    // Convert the temperature based on user choice
    switch (choice) {
        case '1':
            converted_temperature = celsius_to_fahrenheit(temperature);
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, converted_temperature);
            break;
        case '2':
            converted_temperature = fahrenheit_to_celsius(temperature);
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temperature, converted_temperature);
            break;
        default:
            printf("Invalid choice. Please enter 1 or 2.\n");
    }

    return 0;
}