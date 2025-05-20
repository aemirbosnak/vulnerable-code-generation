//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float celsiusToKelvin(float celsius);
float kelvinToCelsius(float kelvin);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToFahrenheit(float kelvin);
void performConversion(int choice);

int main() {
    int userChoice;
    
    do {
        displayMenu();
        printf("Enter your choice (1-6 to convert, 0 to exit): ");
        scanf("%d", &userChoice);
        
        if (userChoice < 0 || userChoice > 6) {
            printf("Invalid choice! Please try again.\n");
        } else if (userChoice > 0) {
            performConversion(userChoice);
        }
        
    } while (userChoice != 0);
    
    printf("Exiting the program. Goodbye!\n");
    return 0;
}

// Function to display the conversion options
void displayMenu() {
    printf("\nTemperature Converter Menu:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
}

// Functions for temperature conversions
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
    return (fahrenheit - 32.0) * 5.0 / 9.0 + 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}

// Function to perform the conversion based on user's choice
void performConversion(int choice) {
    float inputTemp, outputTemp;

    printf("Enter the temperature to convert: ");
    scanf("%f", &inputTemp);
    
    switch (choice) {
        case 1:
            outputTemp = celsiusToFahrenheit(inputTemp);
            printf("%.2f Celsius = %.2f Fahrenheit\n", inputTemp, outputTemp);
            break;
        case 2:
            outputTemp = fahrenheitToCelsius(inputTemp);
            printf("%.2f Fahrenheit = %.2f Celsius\n", inputTemp, outputTemp);
            break;
        case 3:
            outputTemp = celsiusToKelvin(inputTemp);
            printf("%.2f Celsius = %.2f Kelvin\n", inputTemp, outputTemp);
            break;
        case 4:
            outputTemp = kelvinToCelsius(inputTemp);
            printf("%.2f Kelvin = %.2f Celsius\n", inputTemp, outputTemp);
            break;
        case 5:
            outputTemp = fahrenheitToKelvin(inputTemp);
            printf("%.2f Fahrenheit = %.2f Kelvin\n", inputTemp, outputTemp);
            break;
        case 6:
            outputTemp = kelvinToFahrenheit(inputTemp);
            printf("%.2f Kelvin = %.2f Fahrenheit\n", inputTemp, outputTemp);
            break;
        default:
            printf("Invalid conversion choice.\n");
            break;
    }
}