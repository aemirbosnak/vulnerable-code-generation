//FormAI DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to clear the input buffer
void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// function to convert temperature from Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// function to convert temperature from Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// function to convert distance from meters to feet
float metersToFeet(float meters) {
    return meters * 3.281;
}

// function to convert distance from feet to meters
float feetToMeters(float feet) {
    return feet / 3.281;
}

// function to display the main menu
void displayMenu() {
    printf("\n===== Retro Unit Converter =====\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
}

int main() {
    int choice;
    float value, result;

    do {
        displayMenu();
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &value);
                clearBuffer();
                result = celsiusToFahrenheit(value);
                printf("%.2f Celsius = %.2f Fahrenheit\n", value, result);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &value);
                clearBuffer();
                result = fahrenheitToCelsius(value);
                printf("%.2f Fahrenheit = %.2f Celsius\n", value, result);
                break;

            case 3:
                printf("Enter distance in meters: ");
                scanf("%f", &value);
                clearBuffer();
                result = metersToFeet(value);
                printf("%.2f meters = %.2f feet\n", value, result);
                break;

            case 4:
                printf("Enter distance in feet: ");
                scanf("%f", &value);
                clearBuffer();
                result = feetToMeters(value);
                printf("%.2f feet = %.2f meters\n", value, result);
                break;

            case 5:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}