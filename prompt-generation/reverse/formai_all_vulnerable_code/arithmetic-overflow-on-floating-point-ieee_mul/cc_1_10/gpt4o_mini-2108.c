//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: calm
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
void handleConversion(int choice);

int main() {
    int choice;
    printf("Welcome to the Temperature Converter!\n");
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // clear invalid input
            continue; // restart loop
        }

        if (choice < 1 || choice > 6) {
            printf("Please choose a valid option (1-6).\n");
        } else if (choice != 6) {
            handleConversion(choice);
        }
    } while (choice != 6);

    printf("Thank you for using the Temperature Converter. Goodbye!\n");
    return 0;
}

// Function to display the conversion menu
void displayMenu() {
    printf("\nTemperature Conversion Options:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

// Function to convert Fahrenheit to Kelvin
float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

// Function to convert Kelvin to Fahrenheit
float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}

// Function to handle the conversion process
void handleConversion(int choice) {
    float inputTemp, resultTemp;

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &inputTemp);
            resultTemp = celsiusToFahrenheit(inputTemp);
            printf("%.2f Celsius is %.2f Fahrenheit.\n", inputTemp, resultTemp);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &inputTemp);
            resultTemp = fahrenheitToCelsius(inputTemp);
            printf("%.2f Fahrenheit is %.2f Celsius.\n", inputTemp, resultTemp);
            break;
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &inputTemp);
            resultTemp = celsiusToKelvin(inputTemp);
            printf("%.2f Celsius is %.2f Kelvin.\n", inputTemp, resultTemp);
            break;
        case 4:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &inputTemp);
            resultTemp = kelvinToCelsius(inputTemp);
            printf("%.2f Kelvin is %.2f Celsius.\n", inputTemp, resultTemp);
            break;
        case 5:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &inputTemp);
            resultTemp = fahrenheitToKelvin(inputTemp);
            printf("%.2f Fahrenheit is %.2f Kelvin.\n", inputTemp, resultTemp);
            break;
        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &inputTemp);
            resultTemp = kelvinToFahrenheit(inputTemp);
            printf("%.2f Kelvin is %.2f Fahrenheit.\n", inputTemp, resultTemp);
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
}