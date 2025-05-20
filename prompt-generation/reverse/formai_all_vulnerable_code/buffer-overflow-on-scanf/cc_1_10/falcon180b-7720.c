//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to display the menu
void displayMenu() {
    printf("\nTemperature Converter Menu:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

// Function to get user input
float getUserInput() {
    float input;
    printf("Enter the temperature: ");
    scanf("%f", &input);
    return input;
}

// Function to get user choice
int getUserChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Main function
int main() {
    float input, output;
    int choice;

    do {
        displayMenu();
        choice = getUserChoice();

        switch (choice) {
            case 1:
                input = getUserInput();
                output = celsiusToFahrenheit(input);
                printf("%.2f Celsius is %.2f Fahrenheit.\n", input, output);
                break;
            case 2:
                input = getUserInput();
                output = fahrenheitToCelsius(input);
                printf("%.2f Fahrenheit is %.2f Celsius.\n", input, output);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}