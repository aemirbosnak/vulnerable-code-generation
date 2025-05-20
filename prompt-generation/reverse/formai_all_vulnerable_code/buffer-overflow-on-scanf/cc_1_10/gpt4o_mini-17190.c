//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: real-life
#include <stdio.h>

// Function declarations
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void displayMenu();

int main() {
    int choice;
    float temperature, convertedTemperature;
    
    // Welcome message
    printf("Welcome to Caffeine Haven Café!\n");
    printf("We are pleased to offer you a temperature converter for your drinks.\n");
    
    // Display menu and get user choice
    displayMenu();
    printf("Please enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Handling the user's choice
    if (choice == 1) {
        // Celsius to Fahrenheit
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        convertedTemperature = celsiusToFahrenheit(temperature);
        printf("The temperature in Fahrenheit is: %.2f°F\n", convertedTemperature);
    } else if (choice == 2) {
        // Fahrenheit to Celsius
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        convertedTemperature = fahrenheitToCelsius(temperature);
        printf("The temperature in Celsius is: %.2f°C\n", convertedTemperature);
    } else {
        printf("Invalid choice! Please run the program again and select 1 or 2.\n");
        return 1; // Exit with an error code
    }

    // Goodbye message
    printf("Thank you for using our temperature converter!\n");
    printf("Enjoy your drink at the right temperature! ☕\n");
    
    return 0; // Successful completion
}

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
    printf("Temperature Converter Menu:\n");
    printf("1) Convert Celsius to Fahrenheit\n");
    printf("2) Convert Fahrenheit to Celsius\n");
}