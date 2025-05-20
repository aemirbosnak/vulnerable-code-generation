//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    int choice;
    double temperature, converted_temperature;

    // Display menu options
    printf("Welcome to the Temperature Converter!\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    printf("5. Exit\n");

    // Get user choice
    scanf("%d", &choice);

    // Convert Celsius to Fahrenheit
    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%lf", &temperature);
        converted_temperature = (temperature * 9/5) + 32;
        printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, converted_temperature);
    }

    // Convert Fahrenheit to Celsius
    else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%lf", &temperature);
        converted_temperature = (temperature - 32) * 5/9;
        printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temperature, converted_temperature);
    }

    // Convert Kelvin to Celsius
    else if (choice == 3) {
        printf("Enter temperature in Kelvin: ");
        scanf("%lf", &temperature);
        converted_temperature = temperature - 273.15;
        printf("%.2lf Kelvin is equal to %.2lf degrees Celsius.\n", temperature, converted_temperature);
    }

    // Convert Celsius to Kelvin
    else if (choice == 4) {
        printf("Enter temperature in Celsius: ");
        scanf("%lf", &temperature);
        converted_temperature = temperature + 273.15;
        printf("%.2lf degrees Celsius is equal to %.2lf Kelvin.\n", temperature, converted_temperature);
    }

    // Exit program
    else if (choice == 5) {
        printf("Exiting program...\n");
    }

    // Invalid choice
    else {
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}