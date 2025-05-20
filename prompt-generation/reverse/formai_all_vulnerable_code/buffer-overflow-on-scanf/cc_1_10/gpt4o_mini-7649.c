//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void showMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void performConversion(int choice);

int main() {
    int userChoice;

    while (1) {
        showMenu();
        printf("Please enter your choice (1-4): ");
        int result = scanf("%d", &userChoice);

        // Handle invalid input
        if (result != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }

        // Process user choice
        switch (userChoice) {
            case 1:
            case 2:
                performConversion(userChoice);
                break;
            case 3:
                printf("Exiting the Temperature Converter. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    }
}

// Function to display the menu
void showMenu() {
    printf("\n----------------------\n");
    printf("   Temperature Menu   \n");
    printf("----------------------\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("----------------------\n");
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to perform the selected conversion
void performConversion(int choice) {
    float inputTemp, outputTemp;

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        if (scanf("%f", &inputTemp) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while(getchar() != '\n'); // Clear the input buffer
            return;
        }
        outputTemp = celsiusToFahrenheit(inputTemp);
        printf("%.2f Celsius is %.2f Fahrenheit.\n", inputTemp, outputTemp);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        if (scanf("%f", &inputTemp) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while(getchar() != '\n'); // Clear the input buffer
            return;
        }
        outputTemp = fahrenheitToCelsius(inputTemp);
        printf("%.2f Fahrenheit is %.2f Celsius.\n", inputTemp, outputTemp);
    }
}