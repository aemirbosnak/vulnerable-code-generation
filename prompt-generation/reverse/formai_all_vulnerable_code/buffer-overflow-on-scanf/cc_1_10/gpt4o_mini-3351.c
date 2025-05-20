//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

enum TempScale {
    CELSIUS = 1,
    FAHRENHEIT,
    KELVIN,
    EXIT
};

void printMenu() {
    printf("Temperature Converter\n");
    printf("====================\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
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
    return (fahrenheit - 32.0) * 5.0 / 9.0 + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}

void performConversion(int choice) {
    float input, result;
    
    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input);
            result = celsiusToFahrenheit(input);
            printf("%.2f Celsius = %.2f Fahrenheit\n", input, result);
            break;
        case 2:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input);
            result = celsiusToKelvin(input);
            printf("%.2f Celsius = %.2f Kelvin\n", input, result);
            break;
        case 3:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);
            result = fahrenheitToCelsius(input);
            printf("%.2f Fahrenheit = %.2f Celsius\n", input, result);
            break;
        case 4:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);
            result = fahrenheitToKelvin(input);
            printf("%.2f Fahrenheit = %.2f Kelvin\n", input, result);
            break;
        case 5:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &input);
            result = kelvinToCelsius(input);
            printf("%.2f Kelvin = %.2f Celsius\n", input, result);
            break;
        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &input);
            result = kelvinToFahrenheit(input);
            printf("%.2f Kelvin = %.2f Fahrenheit\n", input, result);
            break;
        default:
            printf("Invalid option selected. Please try again.\n");
            break;
    }
}

int main() {
    int choice;

    while (1) {
        printMenu();
        printf("Select an option (1-7): ");
        scanf("%d", &choice);

        if (choice == EXIT) {
            printf("Exiting the Temperature Converter.\n");
            break;
        }
        
        performConversion(choice);
        printf("\n");
    }

    return 0;
}