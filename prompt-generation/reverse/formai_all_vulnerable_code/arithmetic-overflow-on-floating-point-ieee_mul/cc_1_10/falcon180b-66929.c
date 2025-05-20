//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: excited
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

int main() {
    int choice;
    float temperature, convertedTemperature;

    // Welcome message
    printf("Welcome to the Temperature Converter!\n\n");

    // Menu
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n\n");

    // Get user choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Get input temperature
    printf("Enter the temperature to convert: ");
    scanf("%f", &temperature);

    // Convert temperature
    switch(choice) {
        case 1:
            // Celsius to Fahrenheit
            convertedTemperature = celsiusToFahrenheit(temperature);
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, convertedTemperature);
            break;
        case 2:
            // Fahrenheit to Celsius
            convertedTemperature = fahrenheitToCelsius(temperature);
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, convertedTemperature);
            break;
        case 3:
            // Exit
            printf("Thank you for using the Temperature Converter!\n");
            break;
        default:
            // Invalid choice
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}