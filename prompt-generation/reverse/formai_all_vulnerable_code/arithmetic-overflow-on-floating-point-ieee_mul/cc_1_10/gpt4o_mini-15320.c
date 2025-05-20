//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to display the menu
void displayMenu() {
    printf("\n============================\n");
    printf("    Temperature Converter    \n");
    printf("============================\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("============================\n");
    printf("Choose your option: ");
}

// Function to perform conversion based on user choice
void convertTemperature() {
    int choice;
    float temperature, convertedTemperature;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You chose to convert from Celsius to Fahrenheit!\n");
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("🎉 %0.2f °C is equal to %0.2f °F 🎉\n", temperature, convertedTemperature);
                break;

            case 2:
                printf("You chose to convert from Fahrenheit to Celsius!\n");
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("🎉 %0.2f °F is equal to %0.2f °C 🎉\n", temperature, convertedTemperature);
                break;

            case 3:
                printf("Thanks for using the Temperature Converter! Goodbye! 👋\n");
                exit(0);

            default:
                printf("❌ Invalid choice! Please select a valid option. ❌\n");
        }
    }
}

int main() {
    printf("🌡️ Welcome to the Super Exciting Temperature Converter! 🌡️\n");
    printf("Get ready to convert temperatures in a fun and easy way!\n");

    // Starting the temperature conversion process
    convertTemperature();

    return 0;
}