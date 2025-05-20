//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: all-encompassing
#include <stdio.h>

// Function prototypes
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void displayMenu();
void convertTemperature();
void clearInputBuffer();

int main() {
    printf("Welcome to the Temperature Converter!\n");
    printf("-------------------------------------\n");
    
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertTemperature();
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 2);
    
    return 0;
}

// Function to display the menu options
void displayMenu() {
    printf("\nChoose an option:\n");
    printf("1. Convert Temperature\n");
    printf("2. Exit\n");
    printf("Enter your choice (1 or 2): ");
}

// Function to convert temperature based on user's input
void convertTemperature() {
    int conversionType;
    float inputTemp, convertedTemp;

    printf("\nTemperature Conversion Options:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Select conversion type (1 or 2): ");
    scanf("%d", &conversionType);

    if (conversionType == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &inputTemp);

        convertedTemp = celsiusToFahrenheit(inputTemp);
        printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", inputTemp, convertedTemp);
    } else if (conversionType == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &inputTemp);

        convertedTemp = fahrenheitToCelsius(inputTemp);
        printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", inputTemp, convertedTemp);
    } else {
        printf("Invalid conversion type selected.\n");
    }

    clearInputBuffer();
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}