//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

int main() {
    char choice;
    float temp;

    // Welcome message
    printf("Welcome to Temperature Converter!\n");

    // Loop until user chooses to exit
    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Convert Fahrenheit to Celsius\n");
        printf("2. Convert Celsius to Fahrenheit\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        // Convert choice to uppercase
        choice = toupper(choice);

        // Convert temperature based on user's choice
        switch (choice) {
            case '1':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temp);
                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temp, fahrenheitToCelsius(temp));
                break;
            case '2':
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temp);
                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temp, celsiusToFahrenheit(temp));
                break;
            case '3':
                printf("Thank you for using Temperature Converter!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice!= '3');

    return 0;
}