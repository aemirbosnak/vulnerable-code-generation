//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: accurate
#include <stdio.h>

// Function prototypes
void displayMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float kelvinToCelsius(float kelvin);
float celsiusToKelvin(float celsius);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToFahrenheit(float kelvin);
void clearInputBuffer();

int main() {
    int choice;
    float inputTemp, convertedTemp;

    while (1) {
        displayMenu();
        printf("Please enter your choice (1-6, or 0 to exit): ");
        scanf("%d", &choice);
        
        // Clear input buffer for further use
        clearInputBuffer();

        if (choice == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 6) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        printf("Enter the temperature value to convert: ");
        scanf("%f", &inputTemp);
        clearInputBuffer();

        switch (choice) {
            case 1:
                convertedTemp = celsiusToFahrenheit(inputTemp);
                printf("%.2f Celsius is %.2f Fahrenheit\n", inputTemp, convertedTemp);
                break;
            case 2:
                convertedTemp = fahrenheitToCelsius(inputTemp);
                printf("%.2f Fahrenheit is %.2f Celsius\n", inputTemp, convertedTemp);
                break;
            case 3:
                convertedTemp = kelvinToCelsius(inputTemp);
                printf("%.2f Kelvin is %.2f Celsius\n", inputTemp, convertedTemp);
                break;
            case 4:
                convertedTemp = celsiusToKelvin(inputTemp);
                printf("%.2f Celsius is %.2f Kelvin\n", inputTemp, convertedTemp);
                break;
            case 5:
                convertedTemp = fahrenheitToKelvin(inputTemp);
                printf("%.2f Fahrenheit is %.2f Kelvin\n", inputTemp, convertedTemp);
                break;
            case 6:
                convertedTemp = kelvinToFahrenheit(inputTemp);
                printf("%.2f Kelvin is %.2f Fahrenheit\n", inputTemp, convertedTemp);
                break;
            default:
                printf("Unexpected error!\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Temperature Converter Menu ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("0. Exit\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}

void clearInputBuffer() {
    // Clear stdin buffer to avoid unpredictable behavior for multiple scanf
    while (getchar() != '\n');
}