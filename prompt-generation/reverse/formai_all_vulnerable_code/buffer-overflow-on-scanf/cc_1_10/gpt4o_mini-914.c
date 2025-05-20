//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: scientific
#include <stdio.h>

// Function prototypes
void printMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float celsiusToKelvin(float celsius);
float kelvinToCelsius(float kelvin);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToFahrenheit(float kelvin);

// Function to display the menu
void printMenu() {
    printf("Temperature Converter Menu\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
    printf("Select an option (1-7): ");
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

// Function to convert Fahrenheit to Kelvin
float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

// Function to convert Kelvin to Fahrenheit
float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}

// Main function to run the program
int main() {
    int option;
    float inputTemp, outputTemp;

    do {
        printMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &inputTemp);
                outputTemp = celsiusToFahrenheit(inputTemp);
                printf("Temperature in Fahrenheit: %.2f°F\n", outputTemp);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &inputTemp);
                outputTemp = fahrenheitToCelsius(inputTemp);
                printf("Temperature in Celsius: %.2f°C\n", outputTemp);
                break;
            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &inputTemp);
                outputTemp = celsiusToKelvin(inputTemp);
                printf("Temperature in Kelvin: %.2fK\n", outputTemp);
                break;
            case 4:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &inputTemp);
                outputTemp = kelvinToCelsius(inputTemp);
                printf("Temperature in Celsius: %.2f°C\n", outputTemp);
                break;
            case 5:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &inputTemp);
                outputTemp = fahrenheitToKelvin(inputTemp);
                printf("Temperature in Kelvin: %.2fK\n", outputTemp);
                break;
            case 6:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &inputTemp);
                outputTemp = kelvinToFahrenheit(inputTemp);
                printf("Temperature in Fahrenheit: %.2f°F\n", outputTemp);
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }

        // Optional separation line for clarity
        printf("---------------------------------\n");

    } while (option != 7);

    return 0;
}