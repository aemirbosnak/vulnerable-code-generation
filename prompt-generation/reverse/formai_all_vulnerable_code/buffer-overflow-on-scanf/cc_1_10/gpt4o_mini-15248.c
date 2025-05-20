//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void displayMenu();
int getUserChoice();
float getTemperature();
void performConversion(int choice, float temperature);

int main() {
    int userChoice;
    float temperature;
    char continueChoice;

    printf("\nWelcome to the Temperature Converter!\n");

    do {
        displayMenu();
        userChoice = getUserChoice();

        if (userChoice == 1 || userChoice == 2) {
            temperature = getTemperature();
            performConversion(userChoice, temperature);
        } else {
            printf("Invalid choice! Please select a valid option.\n");
        }

        printf("\nDo you want to perform another conversion? (y/n): ");
        scanf(" %c", &continueChoice);
    } while (continueChoice == 'y' || continueChoice == 'Y');

    printf("Thank you for using the Temperature Converter! Goodbye!\n");
    return 0;
}

// Function to display the conversion menu
void displayMenu() {
    printf("\nTemperature Conversion Menu:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice (1 or 2): ");
}

// Function to get user choice
int getUserChoice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Function to get the temperature from the user
float getTemperature() {
    float temperature;
    printf("Enter the temperature to convert: ");
    scanf("%f", &temperature);
    return temperature;
}

// Function to perform the conversion based on user choice
void performConversion(int choice, float temperature) {
    if (choice == 1) {
        float convertedTemperature = celsiusToFahrenheit(temperature);
        printf("%.2f Celsius is equal to %.2f Fahrenheit\n", temperature, convertedTemperature);
    } else if (choice == 2) {
        float convertedTemperature = fahrenheitToCelsius(temperature);
        printf("%.2f Fahrenheit is equal to %.2f Celsius\n", temperature, convertedTemperature);
    }
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}