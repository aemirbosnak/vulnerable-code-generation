//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float celsiusToKelvin(float celsius);
float kelvinToCelsius(float kelvin);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToFahrenheit(float kelvin);

int main() {
    int choice;
    float temperature, result;
    
    printf("🌈 Welcome to the Mind-Bending Temperature Converter! 🌈\n");
    printf("✨ Enter '0' to exit at any point. ✨\n");

    do {
        displayMenu();
        printf("\nChoose a conversion option (1-6): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("🚪 Exiting... Stay Cool! Goodbye! 🚪\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("🔼 Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                result = celsiusToFahrenheit(temperature);
                printf("🌡️ %.2f°C is equal to %.2f°F.\n", temperature, result);
                break;
            case 2:
                printf("🔼 Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                result = fahrenheitToCelsius(temperature);
                printf("🌡️ %.2f°F is equal to %.2f°C.\n", temperature, result);
                break;
            case 3:
                printf("🔼 Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                result = celsiusToKelvin(temperature);
                printf("🌡️ %.2f°C is equal to %.2fK.\n", temperature, result);
                break;
            case 4:
                printf("🔼 Enter temperature in Kelvin: ");
                scanf("%f", &temperature);
                result = kelvinToCelsius(temperature);
                printf("🌡️ %.2fK is equal to %.2f°C.\n", temperature, result);
                break;
            case 5:
                printf("🔼 Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                result = fahrenheitToKelvin(temperature);
                printf("🌡️ %.2f°F is equal to %.2fK.\n", temperature, result);
                break;
            case 6:
                printf("🔼 Enter temperature in Kelvin: ");
                scanf("%f", &temperature);
                result = kelvinToFahrenheit(temperature);
                printf("🌡️ %.2fK is equal to %.2f°F.\n", temperature, result);
                break;
            default:
                printf("⚠️ Invalid option! Please choose a valid conversion.\n");
        }
        
        printf("🌟 Ready for another conversion? 🌟\n\n");
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n===== Temperature Conversion Choices =====\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
    printf("==========================================\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
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