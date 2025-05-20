//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: genius
#include <stdio.h>

// Function prototypes
void displayMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float celsiusToKelvin(float celsius);
float kelvinToCelsius(float kelvin);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToFahrenheit(float kelvin);
void handleUserChoice(int choice);

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-6) or 0 to exit: ");
        scanf("%d", &choice);
        handleUserChoice(choice);
    } while (choice != 0);

    printf("Thank you for using the Temperature Converter! Goodbye!\n");
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
    return (fahrenheitToCelsius(fahrenheit) + 273.15);
}

float kelvinToFahrenheit(float kelvin) {
    return (celsiusToFahrenheit(kelvinToCelsius(kelvin)));
}

void handleUserChoice(int choice) {
    float inputTemp, outputTemp;
    
    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &inputTemp);
            outputTemp = celsiusToFahrenheit(inputTemp);
            printf("%.2f Celsius = %.2f Fahrenheit\n", inputTemp, outputTemp);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &inputTemp);
            outputTemp = fahrenheitToCelsius(inputTemp);
            printf("%.2f Fahrenheit = %.2f Celsius\n", inputTemp, outputTemp);
            break;
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &inputTemp);
            outputTemp = celsiusToKelvin(inputTemp);
            printf("%.2f Celsius = %.2f Kelvin\n", inputTemp, outputTemp);
            break;
        case 4:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &inputTemp);
            outputTemp = kelvinToCelsius(inputTemp);
            printf("%.2f Kelvin = %.2f Celsius\n", inputTemp, outputTemp);
            break;
        case 5:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &inputTemp);
            outputTemp = fahrenheitToKelvin(inputTemp);
            printf("%.2f Fahrenheit = %.2f Kelvin\n", inputTemp, outputTemp);
            break;
        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &inputTemp);
            outputTemp = kelvinToFahrenheit(inputTemp);
            printf("%.2f Kelvin = %.2f Fahrenheit\n", inputTemp, outputTemp);
            break;
        case 0:
            // Do nothing, will exit the loop.
            break;
        default:
            printf("Invalid choice! Please select a valid option.\n");
    }
}