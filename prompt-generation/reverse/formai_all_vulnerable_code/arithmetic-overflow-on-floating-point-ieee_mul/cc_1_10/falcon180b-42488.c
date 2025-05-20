//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
    double celsius, fahrenheit;
    char choice;

    // Loop until user chooses to exit
    while (1) {
        // Display menu
        printf("\nTemperature Converter\n");
        printf("------------------------\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("------------------------\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        // Convert choice to uppercase
        choice = toupper(choice);

        // Perform conversion based on user's choice
        switch (choice) {
            case '1':
                // Celsius to Fahrenheit
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &celsius);
                printf("%.2lf Celsius = %.2lf Fahrenheit\n", celsius, celsiusToFahrenheit(celsius));
                break;
            case '2':
                // Fahrenheit to Celsius
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &fahrenheit);
                printf("%.2lf Fahrenheit = %.2lf Celsius\n", fahrenheit, fahrenheitToCelsius(fahrenheit));
                break;
            case '3':
                // Exit
                printf("Exiting program...\n");
                exit(0);
            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}