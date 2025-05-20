//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);

int main() {
    double temperature, converted_temperature;
    int choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter 1 to convert Celsius to Fahrenheit.\n");
    printf("Enter 2 to convert Fahrenheit to Celsius.\n");
    printf("Enter 3 to exit.\n");

    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the temperature in Celsius: ");
        scanf("%lf", &temperature);
        converted_temperature = celsius_to_fahrenheit(temperature);
        printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, converted_temperature);
    } else if (choice == 2) {
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%lf", &temperature);
        converted_temperature = fahrenheit_to_celsius(temperature);
        printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temperature, converted_temperature);
    } else if (choice == 3) {
        printf("Exiting program...\n");
    } else {
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}

// Converts Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    double fahrenheit;

    fahrenheit = (celsius * 9/5) + 32;

    return fahrenheit;
}

// Converts Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    double celsius;

    celsius = (fahrenheit - 32) * 5/9;

    return celsius;
}