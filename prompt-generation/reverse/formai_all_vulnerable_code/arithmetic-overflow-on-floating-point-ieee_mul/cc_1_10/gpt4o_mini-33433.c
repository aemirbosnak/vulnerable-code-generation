//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float kelvinToCelsius(float kelvin);
float celsiusToKelvin(float celsius);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToFahrenheit(float kelvin);
void getTemperatureInput();

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        printf("Select conversion type (1-5) or 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the temperature converter. Goodbye!\n");
            break;
        }
        
        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }
        
        getTemperatureInput(choice);
    }

    return 0;
}

void displayMenu() {
    printf("\n*** Temperature Converter ***\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Kelvin to Fahrenheit\n");
    printf("6. Fahrenheit to Kelvin\n");
    printf("\n");
}

void getTemperatureInput(int choice) {
    float tempInput, result;

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &tempInput);
            result = celsiusToFahrenheit(tempInput);
            printf("%.2f °C = %.2f °F\n", tempInput, result);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &tempInput);
            result = fahrenheitToCelsius(tempInput);
            printf("%.2f °F = %.2f °C\n", tempInput, result);
            break;
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &tempInput);
            result = celsiusToKelvin(tempInput);
            printf("%.2f °C = %.2f K\n", tempInput, result);
            break;
        case 4:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &tempInput);
            result = kelvinToCelsius(tempInput);
            printf("%.2f K = %.2f °C\n", tempInput, result);
            break;
        case 5:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &tempInput);
            result = kelvinToFahrenheit(tempInput);
            printf("%.2f K = %.2f °F\n", tempInput, result);
            break;
        case 6:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &tempInput);
            result = fahrenheitToKelvin(tempInput);
            printf("%.2f °F = %.2f K\n", tempInput, result);
            break;
        default:
            printf("An unexpected error occurred.\n");
            break;
    }
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}