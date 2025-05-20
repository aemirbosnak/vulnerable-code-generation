//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: mind-bending
#include <stdio.h>

// Function prototypes
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void displayMenu();
void handleUserChoice(int choice);
void processTemperatureConversion(int choice);

// Entry point for the program
int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("\nEnter your choice (1-3) or 0 to exit: ");
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        }
        handleUserChoice(choice);
    }
    printf("Thanks for using the Temperature Converter! Goodbye!\n");
    return 0;
}

// Function to display menu options
void displayMenu() {
    printf("\n===========================\n");
    printf("   Temperature Converter    \n");
    printf("===========================\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Both ways conversion\n");
    printf("===========================\n");
}

// Function to handle user's choice
void handleUserChoice(int choice) {
    switch (choice) {
        case 1: {
            float celsius;
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            float fahrenheit = celsiusToFahrenheit(celsius);
            printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);
            break;
        }
        case 2: {
            float fahrenheit;
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            float celsius = fahrenheitToCelsius(fahrenheit);
            printf("%.2f Fahrenheit is equal to %.2f Celsius\n", fahrenheit, celsius);
            break;
        }
        case 3: {
            float celsius, fahrenheit;
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = celsiusToFahrenheit(celsius);
            printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);

            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = fahrenheitToCelsius(fahrenheit);
            printf("%.2f Fahrenheit is equal to %.2f Celsius\n", fahrenheit, celsius);
            break;
        }
        default: {
            printf("Invalid choice! Please enter a number between 1 and 3.\n");
            break;
        }
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