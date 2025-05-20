//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n-------------------------------\n");
    printf("  C Temperature Converter      \n");
    printf("-------------------------------\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
    printf("-------------------------------\n");
    printf("Select an option: ");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheitToKelvin(float fahrenheit) {
    return celsiusToKelvin(fahrenheitToCelsius(fahrenheit));
}

float kelvinToFahrenheit(float kelvin) {
    return celsiusToFahrenheit(kelvinToCelsius(kelvin));
}

void getUserInput(float* temperature) {
    printf("Enter the temperature value: ");
    scanf("%f", temperature);
}

void performConversion(int choice) {
    float temperature, convertedTemperature;

    switch(choice) {
        case 1:
            getUserInput(&temperature);
            convertedTemperature = celsiusToFahrenheit(temperature);
            printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, convertedTemperature);
            break;
        case 2:
            getUserInput(&temperature);
            convertedTemperature = fahrenheitToCelsius(temperature);
            printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, convertedTemperature);
            break;
        case 3:
            getUserInput(&temperature);
            convertedTemperature = celsiusToKelvin(temperature);
            printf("%.2f Celsius = %.2f Kelvin\n", temperature, convertedTemperature);
            break;
        case 4:
            getUserInput(&temperature);
            convertedTemperature = kelvinToCelsius(temperature);
            printf("%.2f Kelvin = %.2f Celsius\n", temperature, convertedTemperature);
            break;
        case 5:
            getUserInput(&temperature);
            convertedTemperature = fahrenheitToKelvin(temperature);
            printf("%.2f Fahrenheit = %.2f Kelvin\n", temperature, convertedTemperature);
            break;
        case 6:
            getUserInput(&temperature);
            convertedTemperature = kelvinToFahrenheit(temperature);
            printf("%.2f Kelvin = %.2f Fahrenheit\n", temperature, convertedTemperature);
            break;
        case 7:
            printf("Exiting the program...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
            break;
    }
}

int main() {
    int userChoice;

    while(1) {
        displayMenu();
        scanf("%d", &userChoice);
        performConversion(userChoice);
    }

    return 0;
}