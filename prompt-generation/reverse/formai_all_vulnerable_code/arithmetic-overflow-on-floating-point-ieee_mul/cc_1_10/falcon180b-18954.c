//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

int main() {
    char choice;
    double temperature;

    do {
        printf("Welcome to the Temperature Converter!\n\n");
        printf("Please enter your choice:\n");
        printf("C - Convert Celsius to Fahrenheit\n");
        printf("F - Convert Fahrenheit to Celsius\n");
        printf("Q - Quit\n");
        scanf("%c", &choice);

        switch(choice) {
            case 'C':
            case 'c':
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, celsiusToFahrenheit(temperature));
                break;

            case 'F':
            case 'f':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temperature, fahrenheitToCelsius(temperature));
                break;

            case 'Q':
            case 'q':
                printf("Thank you for using the Temperature Converter!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\nDo you want to continue? (Y/N): ");
        scanf(" %c", &choice);
    } while(choice == 'Y' || choice == 'y');

    return 0;
}