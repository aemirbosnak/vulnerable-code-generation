//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: synchronous
#include <stdio.h>

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

void displayMenu() {
    printf("\nTemperature Converter Menu:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Please select an option (1-3): ");
}

void handleConversion(int choice) {
    float inputTemp, convertedTemp;

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            if (scanf("%f", &inputTemp) != 1) {
                printf("Invalid input. Please enter a valid number.\n");
                // Clear the input buffer
                while(getchar() != '\n');
            } else {
                convertedTemp = celsiusToFahrenheit(inputTemp);
                printf("%.2f Celsius is %.2f Fahrenheit\n", inputTemp, convertedTemp);
            }
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            if (scanf("%f", &inputTemp) != 1) {
                printf("Invalid input. Please enter a valid number.\n");
                // Clear the input buffer
                while(getchar() != '\n');
            } else {
                convertedTemp = fahrenheitToCelsius(inputTemp);
                printf("%.2f Fahrenheit is %.2f Celsius\n", inputTemp, convertedTemp);
            }
            break;
        case 3:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid option. Please select a valid choice.\n");
            break;
    }
}

int main() {
    int userChoice = 0;

    while (userChoice != 3) {
        displayMenu();
        
        // Input validation for the choice
        if (scanf("%d", &userChoice) != 1) {
            printf("Invalid input. Please enter a number (1-3).\n");
            // Clear the input buffer
            while(getchar() != '\n');
            userChoice = 0; // Reset userChoice to avoid exiting
            continue;
        }

        handleConversion(userChoice);
    }

    return 0;
}