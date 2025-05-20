//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Alan Turing
#include <stdio.h>

void displayMenu() {
    printf("\nTemperature Converter\n");
    printf("======================\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Select an option (1-3): ");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void processConversion(int choice) {
    float temperature, convertedTemp;

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        convertedTemp = celsiusToFahrenheit(temperature);
        printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, convertedTemp);
    } 
    else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        convertedTemp = fahrenheitToCelsius(temperature);
        printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, convertedTemp);
    } 
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear screen
}

int main() {
    int userChoice;

    do {
        clearScreen();
        displayMenu();
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
            case 2:
                processConversion(userChoice);
                break;
            case 3:
                printf("Exiting the Temperature Converter. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please select a valid option.\n");
        }
        printf("Press Enter to continue...");
        getchar(); // To consume the newline character after scanf
        getchar(); // Wait for user to press Enter
    } while (userChoice != 3);

    return 0;
}