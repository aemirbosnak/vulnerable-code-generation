//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void convertTemperature();

// Helper function to clear the screen
void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the screen
}

int main() {
    clearScreen();
    printf("Welcome to the Temperature Converter!\n");
    printf("=======================================\n");
    convertTemperature();
    return 0;
}

void convertTemperature() {
    int choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice (1-3 or 0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting... Goodbye!\n");
            break;
        } else if (choice == 1) {
            float celsius;
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            float fahrenheit = celsiusToFahrenheit(celsius);
            printf("%.2f Celsius is equivalent to %.2f Fahrenheit\n", celsius, fahrenheit);
        } else if (choice == 2) {
            float fahrenheit;
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            float celsius = fahrenheitToCelsius(fahrenheit);
            printf("%.2f Fahrenheit is equivalent to %.2f Celsius\n", fahrenheit, celsius);
        } else if (choice == 3) {
            printf("You chose to see the temperature scale conversion!\n");
            printf("Celsius to Fahrenheit:     F = (C * 1.8) + 32\n");
            printf("Fahrenheit to Celsius:     C = (F - 32) / 1.8\n");
            printf("Use this formula to compute temperatures.\n");
        } else {
            printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    }
}

void displayMenu() {
    printf("Temperature Conversion Menu:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Show Conversion Formula\n");
    printf("0. Exit\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}