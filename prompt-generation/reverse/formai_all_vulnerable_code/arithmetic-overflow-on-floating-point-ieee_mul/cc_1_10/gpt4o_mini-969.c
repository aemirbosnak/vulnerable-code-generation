//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: curious
#include <stdio.h>

void displayMenu() {
    printf("\n*** Welcome to the Temperature Converter ***\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Please choose an option (1-3): ");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void handleConversion(int choice) {
    float temperature, convertedTemperature;

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        convertedTemperature = celsiusToFahrenheit(temperature);
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, convertedTemperature);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        convertedTemperature = fahrenheitToCelsius(temperature);
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, convertedTemperature);
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

int main() {
    int userChoice = 0;

    while (userChoice != 3) {
        displayMenu();
        scanf("%d", &userChoice);

        if (userChoice == 3) {
            printf("Thank you for using the Temperature Converter! Goodbye!\n");
            break;
        }
        handleConversion(userChoice);
    }
    
    return 0;
}