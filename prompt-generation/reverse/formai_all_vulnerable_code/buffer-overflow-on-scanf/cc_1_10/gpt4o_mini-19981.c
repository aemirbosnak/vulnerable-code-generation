//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: minimalist
#include <stdio.h>

void displayMenu() {
    printf("\nTemperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

void convertTemperature() {
    int choice;
    float inputTemp, convertedTemp;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting the program...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &inputTemp);
                convertedTemp = celsiusToFahrenheit(inputTemp);
                printf("%.2f Celsius = %.2f Fahrenheit\n", inputTemp, convertedTemp);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &inputTemp);
                convertedTemp = fahrenheitToCelsius(inputTemp);
                printf("%.2f Fahrenheit = %.2f Celsius\n", inputTemp, convertedTemp);
                break;

            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    }
}

int main() {
    printf("Welcome to the Temperature Converter!\n");
    convertTemperature();
    return 0;
}