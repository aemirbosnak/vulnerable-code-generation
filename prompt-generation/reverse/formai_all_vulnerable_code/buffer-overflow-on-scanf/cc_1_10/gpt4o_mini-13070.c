//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>

void displayWelcomeMessage() {
    printf("*************************************************************\n");
    printf("*         Welcome to the Awesome Temperature Converter!     *\n");
    printf("*************************************************************\n");
    printf("\n");
}

void displayMenu() {
    printf("Please choose an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
    printf("Your choice: ");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}

void handleConversion(int choice) {
    float inputTemperature, outputTemperature;

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &inputTemperature);
            outputTemperature = celsiusToFahrenheit(inputTemperature);
            printf("Result: %.2f Celsius is %.2f Fahrenheit\n", inputTemperature, outputTemperature);
            break;
        case 2:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &inputTemperature);
            outputTemperature = celsiusToKelvin(inputTemperature);
            printf("Result: %.2f Celsius is %.2f Kelvin\n", inputTemperature, outputTemperature);
            break;
        case 3:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &inputTemperature);
            outputTemperature = fahrenheitToCelsius(inputTemperature);
            printf("Result: %.2f Fahrenheit is %.2f Celsius\n", inputTemperature, outputTemperature);
            break;
        case 4:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &inputTemperature);
            outputTemperature = fahrenheitToKelvin(inputTemperature);
            printf("Result: %.2f Fahrenheit is %.2f Kelvin\n", inputTemperature, outputTemperature);
            break;
        case 5:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &inputTemperature);
            outputTemperature = kelvinToCelsius(inputTemperature);
            printf("Result: %.2f Kelvin is %.2f Celsius\n", inputTemperature, outputTemperature);
            break;
        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &inputTemperature);
            outputTemperature = kelvinToFahrenheit(inputTemperature);
            printf("Result: %.2f Kelvin is %.2f Fahrenheit\n", inputTemperature, outputTemperature);
            break;
        case 7:
            printf("Thank you for using the Awesome Temperature Converter! Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice! Please select a valid option.\n");
    }
}

int main() {
    int userChoice;

    displayWelcomeMessage();

    while (1) {
        displayMenu();
        scanf("%d", &userChoice);
        handleConversion(userChoice);
        printf("\n");
    }

    return 0;
}