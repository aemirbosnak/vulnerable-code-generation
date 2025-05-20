//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n--- Temperature Converter ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
    printf("-----------------------------\n");
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

void performConversion(int choice) {
    float input = 0.0, result = 0.0;

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input);
            result = celsiusToFahrenheit(input);
            printf("Temperature in Fahrenheit: %.2f\n", result);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);
            result = fahrenheitToCelsius(input);
            printf("Temperature in Celsius: %.2f\n", result);
            break;
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input);
            result = celsiusToKelvin(input);
            printf("Temperature in Kelvin: %.2f\n", result);
            break;
        case 4:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &input);
            result = kelvinToCelsius(input);
            printf("Temperature in Celsius: %.2f\n", result);
            break;
        case 5:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);
            result = fahrenheitToKelvin(input);
            printf("Temperature in Kelvin: %.2f\n", result);
            break;
        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &input);
            result = kelvinToFahrenheit(input);
            printf("Temperature in Fahrenheit: %.2f\n", result);
            break;
        case 7:
            printf("Exiting the program. Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option (1-7): ");
        scanf("%d", &choice);
        performConversion(choice);
    }

    return 0;
}