//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Function to display menu options
void displayMenu() {
    printf("Temperature Converter Menu:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

// Function to get user input
int getInput() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Main function
int main() {
    int choice;
    float temperature, convertedTemperature;

    do {
        displayMenu();
        choice = getInput();

        switch(choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, convertedTemperature);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, convertedTemperature);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 3);

    return 0;
}