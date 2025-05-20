//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: lively
#include <stdio.h>

// Function prototypes
void displayWelcome();
void displayMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void performConversion(int choice);

// Main function
int main() {
    displayWelcome();
    int choice = 0;

    // Loop until the user chooses to exit
    while (choice != 3) {
        displayMenu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user's choice
        if (choice == 1 || choice == 2) {
            performConversion(choice);
        } else if (choice != 3) {
            printf("Invalid option! Please try again.\n");
        }
    }

    printf("Thank you for using the Temperature Converter! Goodbye!\n");
    return 0;
}

// Function to display a welcome message
void displayWelcome() {
    printf("***************************\n");
    printf("*     Temperature Converter  *\n");
    printf("***************************\n");
    printf("Welcome to the Temperature Converter! 🌡️\n");
    printf("Convert temperatures between Celsius and Fahrenheit with ease!\n");
}

// Function to display the conversion menu
void displayMenu() {
    printf("\nConversion Options:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to perform the conversion based on user's choice
void performConversion(int choice) {
    float inputTemp, convertedTemp;

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &inputTemp);
        convertedTemp = celsiusToFahrenheit(inputTemp);
        printf("%.2f Celsius is equal to %.2f Fahrenheit! 🎉\n", inputTemp, convertedTemp);
    } 
    else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &inputTemp);
        convertedTemp = fahrenheitToCelsius(inputTemp);
        printf("%.2f Fahrenheit is equal to %.2f Celsius! 🎊\n", inputTemp, convertedTemp);
    } 
}

// Additional functions for extended functionality

// Function to validate input temperature
int isValidTemperature(float temperature) {
    // In this simple example, we don't impose any restrictions
    // Additional checks can be added for specific ranges
    return 1; // Always return valid for simplicity
}

// Function to ask if the user wants to perform another conversion
int askAgain() {
    char response;

    printf("Would you like to perform another conversion? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        return 1; // User wants to continue
    }
    return 0; // User wants to exit
}