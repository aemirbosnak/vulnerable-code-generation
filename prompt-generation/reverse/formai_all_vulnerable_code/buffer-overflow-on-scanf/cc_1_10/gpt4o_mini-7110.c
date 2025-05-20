//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

void menu();
float celsiusToFahrenheit(float celsius);
float celsiusToKelvin(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToCelsius(float kelvin);
float kelvinToFahrenheit(float kelvin);

int main() {
    int choice = 0;
    float temperature, convertedTemperature;

    printf("Welcome to the Temperature Converter Adventure!\n");
    printf("Explore the realms of temperatures between Celsius, Fahrenheit, and Kelvin.\n");

    while (choice != 5) {
        menu();
        printf("Choose your path (1-5): ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("You have chosen the path of Celsius to Fahrenheit.\n");
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &temperature);
            convertedTemperature = celsiusToFahrenheit(temperature);
            printf("The temperature in Fahrenheit is: %.2f°F\n", convertedTemperature);
        } 
        else if (choice == 2) {
            printf("You have chosen the path of Celsius to Kelvin.\n");
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &temperature);
            convertedTemperature = celsiusToKelvin(temperature);
            printf("The temperature in Kelvin is: %.2fK\n", convertedTemperature);
        } 
        else if (choice == 3) {
            printf("You have chosen the path of Fahrenheit to Celsius.\n");
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            convertedTemperature = fahrenheitToCelsius(temperature);
            printf("The temperature in Celsius is: %.2f°C\n", convertedTemperature);
        } 
        else if (choice == 4) {
            printf("You have chosen the path of Kelvin to Celsius.\n");
            printf("Enter the temperature in Kelvin: ");
            scanf("%f", &temperature);
            convertedTemperature = kelvinToCelsius(temperature);
            printf("The temperature in Celsius is: %.2f°C\n", convertedTemperature);
        } 
        else if (choice == 5) {
            printf("Farewell, brave traveler! Until we meet again in the world of temperatures!\n");
        } 
        else {
            printf("Alas! That is not a valid path. Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}

void menu() {
    printf("\n--- Temperature Conversion Menu ---\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Celsius to Kelvin\n");
    printf("3. Convert Fahrenheit to Celsius\n");
    printf("4. Convert Kelvin to Celsius\n");
    printf("5. Exit\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float fahrenheitToKelvin(float fahrenheit) {
    return ((fahrenheit - 32) * 5.0 / 9.0) + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}