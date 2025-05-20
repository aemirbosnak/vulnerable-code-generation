//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Ephemeral constants
#define KELVIN_OFFSET 273.15
#define FAHRENHEIT_CONSTANT 32
#define FAHRENHEIT_OFFSET 1.8

// Ephemeral function declarations
void showMenu();
float convertCelsiusToFahrenheit(float celsius);
float convertFahrenheitToCelsius(float fahrenheit);
float convertCelsiusToKelvin(float celsius);
float convertKelvinToCelsius(float kelvin);

int main() {
    // Ephemeral variables
    char choice;
    float temperature;

    while (1) {
        showMenu();
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("Enter temperature in Celsius: ");
                scanf(" %f", &temperature);
                printf("Temperature in Fahrenheit: %.2f\n", convertCelsiusToFahrenheit(temperature));
                break;
            case '2':
                printf("Enter temperature in Fahrenheit: ");
                scanf(" %f", &temperature);
                printf("Temperature in Celsius: %.2f\n", convertFahrenheitToCelsius(temperature));
                break;
            case '3':
                printf("Enter temperature in Celsius: ");
                scanf(" %f", &temperature);
                printf("Temperature in Kelvin: %.2f\n", convertCelsiusToKelvin(temperature));
                break;
            case '4':
                printf("Enter temperature in Kelvin: ");
                scanf(" %f", &temperature);
                printf("Temperature in Celsius: %.2f\n", convertKelvinToCelsius(temperature));
                break;
            case '5':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void showMenu() {
    printf("\nTemperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

float convertCelsiusToFahrenheit(float celsius) {
    return (celsius * FAHRENHEIT_OFFSET) + FAHRENHEIT_CONSTANT;
}

float convertFahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - FAHRENHEIT_CONSTANT) / FAHRENHEIT_OFFSET;
}

float convertCelsiusToKelvin(float celsius) {
    return celsius + KELVIN_OFFSET;
}

float convertKelvinToCelsius(float kelvin) {
    return kelvin - KELVIN_OFFSET;
}