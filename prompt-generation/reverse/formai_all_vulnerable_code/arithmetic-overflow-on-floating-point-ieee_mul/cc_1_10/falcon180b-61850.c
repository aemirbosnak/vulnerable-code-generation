//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function declarations
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);
double kelvin_to_celsius(double kelvin);
double celsius_to_kelvin(double celsius);
double fahrenheit_to_kelvin(double fahrenheit);
double kelvin_to_fahrenheit(double kelvin);

// Main function
int main() {
    char choice;
    do {
        printf("Welcome to the Temperature Converter\n");
        printf("In a post-apocalyptic world, knowing the temperature is crucial.\n");
        printf("Please select the type of conversion you want to perform:\n");
        printf("C - Celsius to Fahrenheit\n");
        printf("F - Fahrenheit to Celsius\n");
        printf("K - Celsius to Kelvin\n");
        printf("Q - Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case 'C':
            case 'c':
                printf("Enter the temperature in Celsius: ");
                double celsius = atof(gets());
                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, celsius_to_fahrenheit(celsius));
                break;
            case 'F':
            case 'f':
                printf("Enter the temperature in Fahrenheit: ");
                double fahrenheit = atof(gets());
                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, fahrenheit_to_celsius(fahrenheit));
                break;
            case 'K':
            case 'k':
                printf("Enter the temperature in Kelvin: ");
                double kelvin = atof(gets());
                printf("%.2f Kelvin is equal to %.2f degrees Celsius.\n", kelvin, kelvin_to_celsius(kelvin));
                break;
            case 'Q':
            case 'q':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 'Q' && choice!= 'q'); // Continue until user chooses to quit

    return 0;
}

// Function definitions
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheit_to_kelvin(double fahrenheit) {
    return (fahrenheit + 459.67) * 5/9;
}

double kelvin_to_fahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}