//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayWelcomeScreen() {
    printf("\n=====================================\n");
    printf("      Welcome to the Cyberpunk       \n");
    printf("         Temperature Converter       \n");
    printf("=====================================\n");
    printf("Turning the heat of a neon-soaked city into numbers.\n");
    printf("What kind of conversion would you like to perform?\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit the Matrix\n");
    printf("=====================================\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

void performConversion(int choice) {
    float temperature, convertedTemperature;

    switch(choice) {
        case 1:
            printf("\nEnter the temperature in Celsius: ");
            scanf("%f", &temperature);
            convertedTemperature = celsiusToFahrenheit(temperature);
            printf("Converting %.2f °C -> %.2f °F\n", temperature, convertedTemperature);
            break;
        case 2:
            printf("\nEnter the temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            convertedTemperature = fahrenheitToCelsius(temperature);
            printf("Converting %.2f °F -> %.2f °C\n", temperature, convertedTemperature);
            break;
        case 3:
            printf("Shutting down the system... See you in the neon lights.\n");
            exit(0);
        default:
            printf("Invalid selection, please choose again.\n");
            break;
    }
}

void handleUserInput() {
    int choice;
    do {
        displayWelcomeScreen();
        printf("Your choice: ");
        scanf("%d", &choice);
        performConversion(choice);
    } while (choice != 3);
}

int main() {
    // The dark and gritty backdrop of a hyperconnected world
    printf("Booting up...\n");
    printf("Initializing cybernetic presence...\n");
    
    // Main execution for meteorological operations
    handleUserInput();

    printf("Closing connections...\n");
    printf("Exiting the system...\n");

    return 0;
}