//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void convertTemperature();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float celsiusToKelvin(float celsius);
float kelvinToCelsius(float kelvin);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToFahrenheit(float kelvin);
void handleInput(int choice);

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Exiting the Temperature Converter. Goodbye!\n");
            break;
        }

        handleInput(choice);
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Temperature Converter ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
}

void handleInput(int choice) {
    float input, output;

    printf("Enter the temperature you want to convert: ");
    scanf("%f", &input);

    switch (choice) {
        case 1:
            output = celsiusToFahrenheit(input);
            printf("%.2f Celsius = %.2f Fahrenheit\n", input, output);
            break;
        case 2:
            output = fahrenheitToCelsius(input);
            printf("%.2f Fahrenheit = %.2f Celsius\n", input, output);
            break;
        case 3:
            output = celsiusToKelvin(input);
            printf("%.2f Celsius = %.2f Kelvin\n", input, output);
            break;
        case 4:
            output = kelvinToCelsius(input);
            printf("%.2f Kelvin = %.2f Celsius\n", input, output);
            break;
        case 5:
            output = fahrenheitToKelvin(input);
            printf("%.2f Fahrenheit = %.2f Kelvin\n", input, output);
            break;
        case 6:
            output = kelvinToFahrenheit(input);
            printf("%.2f Kelvin = %.2f Fahrenheit\n", input, output);
            break;
        default:
            printf("Invalid choice! Please select a valid option.\n");
            break;
    }
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

float fahrenheitToKelvin(float fahrenheit) {
    float celsius = fahrenheitToCelsius(fahrenheit);
    return celsiusToKelvin(celsius);
}

float kelvinToFahrenheit(float kelvin) {
    float celsius = kelvinToCelsius(kelvin);
    return celsiusToFahrenheit(celsius);
}