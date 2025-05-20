//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: unmistakable
#include <stdio.h>

// Function prototypes
void displayMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float celsiusToKelvin(float celsius);
float kelvinToCelsius(float kelvin);
void invalidOption();

int main() {
    int choice;
    float temperature, convertedTemperature;

    printf("============================================\n");
    printf("      Welcome to the Temperature Converter   \n");
    printf("============================================\n");

    do {
        displayMenu();
        printf("Please select an option (1-5) or 0 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, convertedTemperature);
                break;
            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToKelvin(temperature);
                printf("%.2f Celsius = %.2f Kelvin\n", temperature, convertedTemperature);
                break;
            case 4:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &temperature);
                convertedTemperature = kelvinToCelsius(temperature);
                printf("%.2f Kelvin = %.2f Celsius\n", temperature, convertedTemperature);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                invalidOption();
                break;
        }

    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n--- Temperature Conversion Menu ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("0. Exit\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

void invalidOption() {
    printf("Invalid option! Please choose a valid menu item.\n");
}