//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: calm
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to display the menu
void displayMenu() {
    printf("\nTemperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Select an option (1-3): ");
}

// Function to handle the conversion process
void convertTemperature() {
    int option;
    
    while (1) {
        displayMenu();
        scanf("%d", &option);

        if (option == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        float temperature, convertedTemperature;

        switch (option) {
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius is equal to %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;
            case 2:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit is equal to %.2f Celsius\n", temperature, convertedTemperature);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

// Main function to run the program
int main() {
    printf("Welcome to the Temperature Converter\n");
    printf("This program will help you convert temperatures between Celsius and Fahrenheit.\n");
    convertTemperature();

    return 0;
}