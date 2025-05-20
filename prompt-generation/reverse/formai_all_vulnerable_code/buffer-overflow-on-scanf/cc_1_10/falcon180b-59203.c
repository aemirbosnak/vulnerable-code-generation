//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);
double kelvin_to_celsius(double kelvin);
double celsius_to_kelvin(double celsius);

int main() {
    int choice;
    double temperature;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            printf("%.2lf Celsius is %.2lf Fahrenheit.\n", temperature, celsius_to_fahrenheit(temperature));
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            printf("%.2lf Fahrenheit is %.2lf Celsius.\n", temperature, fahrenheit_to_celsius(temperature));
            break;
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            printf("%.2lf Celsius is %.2lf Kelvin.\n", temperature, celsius_to_kelvin(temperature));
            break;
        case 4:
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &temperature);
            printf("%.2lf Kelvin is %.2lf Celsius.\n", temperature, kelvin_to_celsius(temperature));
            break;
        case 5:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid option selected.\n");
            break;
    }

    return 0;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}