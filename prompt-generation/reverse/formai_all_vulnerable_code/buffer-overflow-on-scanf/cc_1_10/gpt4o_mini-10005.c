//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: beginner-friendly
#include <stdio.h>

// Function prototypes
void displayMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float celsiusToKelvin(float celsius);
float kelvinToCelsius(float kelvin);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToFahrenheit(float kelvin);

int main() {
    int choice;
    float temperature, convertedTemperature;

    // Display a welcome message
    printf("Welcome to the Temperature Converter!\n");
    printf("This program allows you to convert temperatures between Celsius, Fahrenheit, and Kelvin.\n");

    while (1) {
        // Display the menu
        displayMenu();
        printf("Please enter your choice (1-5, or 0 to exit): ");
        scanf("%d", &choice);

        // Exit the program
        if (choice == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Validate choice
        if (choice < 1 || choice > 5) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        // Get the temperature from the user
        printf("Enter the temperature: ");
        scanf("%f", &temperature);

        // Convert based on the user's choice
        switch (choice) {
            case 1:
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, convertedTemperature);
                break;
            case 2:
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, convertedTemperature);
                break;
            case 3:
                convertedTemperature = celsiusToKelvin(temperature);
                printf("%.2f Celsius is equal to %.2f Kelvin.\n", temperature, convertedTemperature);
                break;
            case 4:
                convertedTemperature = kelvinToCelsius(temperature);
                printf("%.2f Kelvin is equal to %.2f Celsius.\n", temperature, convertedTemperature);
                break;
            case 5:
                convertedTemperature = fahrenheitToKelvin(temperature);
                printf("%.2f Fahrenheit is equal to %.2f Kelvin.\n", temperature, convertedTemperature);
                break;
            default:
                printf("Unexpected error occurred!\n");
        }
    }

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nTemperature Conversion Options:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("0. Exit\n");
}

// Function implementations for conversions
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheitToKelvin(float fahrenheit) {
    float celsius = fahrenheitToCelsius(fahrenheit);
    return celsiusToKelvin(celsius);
}

float kelvinToFahrenheit(float kelvin) {
    float celsius = kelvinToCelsius(kelvin);
    return celsiusToFahrenheit(celsius);
}