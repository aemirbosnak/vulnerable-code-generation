//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: inquisitive
#include <stdio.h>

void displayMenu() {
    printf("Welcome to the Temperature Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void executeConversion(int choice) {
    float temperature, convertedTemperature;

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            convertedTemperature = celsiusToFahrenheit(temperature);
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, convertedTemperature);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            convertedTemperature = fahrenheitToCelsius(temperature);
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, convertedTemperature);
            break;
        case 3:
            printf("Thank you for using the Temperature Converter. Goodbye!\n");
            break;
        default:
            printf("Invalid choice! Please choose 1, 2, or 3.\n");
            break;
    }
}

int main() {
    int choice = 0;

    while (choice != 3) {
        displayMenu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        executeConversion(choice);
        printf("\n");
    }

    return 0;
}