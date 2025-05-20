//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: safe
#include <stdio.h>

// Function declarations
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void displayMenu();
void performConversion(int choice);

// Main function
int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-3, or 0 to exit): ");
        scanf("%d", &choice);

        if (choice < 0 || choice > 3) {
            printf("Invalid choice. Please select a valid option.\n");
        } else if (choice != 0) {
            performConversion(choice);
        }
    } while (choice != 0);

    printf("Thank you for using the Temperature Converter!\n");

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nTemperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

// Function to perform the conversion based on user's choice
void performConversion(int choice) {
    float temperature, convertedTemperature;

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            convertedTemperature = celsiusToFahrenheit(temperature);
            printf("Temperature in Fahrenheit: %.2f\n", convertedTemperature);
            break;
        
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            convertedTemperature = fahrenheitToCelsius(temperature);
            printf("Temperature in Celsius: %.2f\n", convertedTemperature);
            break;

        default:
            printf("Exiting the program...\n");
    }
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0/5.0) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0/9.0;
}