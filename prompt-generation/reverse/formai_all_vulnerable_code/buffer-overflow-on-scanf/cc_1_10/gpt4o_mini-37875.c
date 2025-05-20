//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("*****************************************\n");
    printf("*            Temperature Converter      *\n");
    printf("*****************************************\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("*****************************************\n");
    printf("Please select an option (1-3): ");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void convertTemperature() {
    int choice;
    float temperature, convertedTemp;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            convertedTemp = celsiusToFahrenheit(temperature);
            printf("%.2f Celsius is equal to %.2f Fahrenheit\n", temperature, convertedTemp);
        } else if (choice == 2) {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            convertedTemp = fahrenheitToCelsius(temperature);
            printf("%.2f Fahrenheit is equal to %.2f Celsius\n", temperature, convertedTemp);
        } else if (choice == 3) {
            printf("Thank you for using the Temperature Converter!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }

        printf("\nPress Enter to continue...");
        getchar(); // To capture the newline character after entering choice
        getchar(); // Wait for user to press Enter
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Temperature Converter!\n");
    printf("A simple tool to convert temperatures peacefully.\n");
    printf("Let's begin our journey through temperature scales...\n\n");
    
    convertTemperature();

    printf("Goodbye and may your temperatures always feel just right!\n");
    return 0;
}