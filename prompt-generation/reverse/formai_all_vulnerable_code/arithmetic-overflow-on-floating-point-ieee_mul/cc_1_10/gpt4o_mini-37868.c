//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: safe
#include <stdio.h>

void displayMenu() {
    printf("\n================== Temperature Converter ==================\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
    printf("===========================================================\n");
    printf("Please choose an option (0-6): ");
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
    return celsiusToKelvin(fahrenheitToCelsius(fahrenheit));
}

float kelvinToFahrenheit(float kelvin) {
    return celsiusToFahrenheit(kelvinToCelsius(kelvin));
}

void handleConversion(int choice) {
    float input, result;

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input);
            result = celsiusToFahrenheit(input);
            printf("%.2f°C = %.2f°F\n", input, result);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);
            result = fahrenheitToCelsius(input);
            printf("%.2f°F = %.2f°C\n", input, result);
            break;
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input);
            result = celsiusToKelvin(input);
            printf("%.2f°C = %.2fK\n", input, result);
            break;
        case 4:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &input);
            result = kelvinToCelsius(input);
            printf("%.2fK = %.2f°C\n", input, result);
            break;
        case 5:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);
            result = fahrenheitToKelvin(input);
            printf("%.2f°F = %.2fK\n", input, result);
            break;
        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &input);
            result = kelvinToFahrenheit(input);
            printf("%.2fK = %.2f°F\n", input, result);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        if (choice >= 0 && choice <= 6) {
            if (choice != 0) {
                handleConversion(choice);
            }
        } else {
            printf("Please enter a valid option (0 to 6).\n");
        }

    } while (choice != 0);

    printf("Thank you for using the Temperature Converter! Goodbye!\n");
    return 0;
}