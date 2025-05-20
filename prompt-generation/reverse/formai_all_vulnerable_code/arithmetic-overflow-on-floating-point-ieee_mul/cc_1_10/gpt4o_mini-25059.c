//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: excited
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to display the menu
void displayMenu() {
    printf("Welcome to the Temperature Converter! 🌡️\n");
    printf("What would you like to do today?\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Please enter your choice (1-3): ");
}

// Function to get valid temperature input
float getTemperature() {
    float temp;
    printf("Enter the temperature value: ");
    scanf("%f", &temp);
    return temp;
}

int main() {
    int choice;
    float temperature, convertedTemperature;

    while (1) {
        displayMenu();
        
        // Get user choice
        scanf("%d", &choice);
        
        // Handling user's choice
        switch (choice) {
            case 1:
                printf("You chose to convert Celsius to Fahrenheit! 🎉\n");
                temperature = getTemperature();
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2f°C is equal to %.2f°F.\n\n", temperature, convertedTemperature);
                break;
            case 2:
                printf("You chose to convert Fahrenheit to Celsius! 🎊\n");
                temperature = getTemperature();
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%.2f°F is equal to %.2f°C.\n\n", temperature, convertedTemperature);
                break;
            case 3:
                printf("Thank you for using the Temperature Converter! Goodbye! 👋🏼\n");
                return 0;
            default:
                printf("Oops! That was not a valid choice. Please try again! 🚫\n\n");
        }
    }

    return 0; // Although the loop should be infinite, we return 0 to maintain function integrity.
}