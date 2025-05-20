//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}

int main() {
    // Declare variables
    double celsius, fahrenheit;
    char choice;

    // Initialize variables
    celsius = 0.0;
    fahrenheit = 0.0;
    choice = 'y';

    // Main loop
    while (choice == 'y' || choice == 'Y') {
        // Display menu
        printf("\n");
        printf("Enter choice:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Quit\n");
        printf("> ");
        scanf("%c", &choice);

        // Perform conversion
        switch (choice) {
            case '1':
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &celsius);
                printf("%.2lf Celsius is %.2lf Fahrenheit.\n", celsius, celsiusToFahrenheit(celsius));
                break;
            case '2':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &fahrenheit);
                printf("%.2lf Fahrenheit is %.2lf Celsius.\n", fahrenheit, fahrenheitToCelsius(fahrenheit));
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}