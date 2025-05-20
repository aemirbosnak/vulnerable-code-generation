//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    double celsius = (5 * (fahrenheit - 32)) / 9;
    return celsius;
}

// Function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    double celsius = kelvin - 273.15;
    return celsius;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    double kelvin = celsius + 273.15;
    return kelvin;
}

int main() {
    char choice;
    double input;

    printf("Welcome to the Temperature Converter!\n\n");

    do {
        printf("Please choose a conversion option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Kelvin to Celsius\n");
        printf("5. Exit\n");
        choice = toupper(getchar()); // Convert input to uppercase

        switch(choice) {
            case '1': // Celsius to Fahrenheit
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &input);
                printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n\n", input, celsiusToFahrenheit(input));
                break;
            case '2': // Fahrenheit to Celsius
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &input);
                printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n\n", input, fahrenheitToCelsius(input));
                break;
            case '3': // Celsius to Kelvin
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &input);
                printf("%.2lf Celsius is equal to %.2lf Kelvin.\n\n", input, kelvinToCelsius(input));
                break;
            case '4': // Kelvin to Celsius
                printf("Enter temperature in Kelvin: ");
                scanf("%lf", &input);
                printf("%.2lf Kelvin is equal to %.2lf Celsius.\n\n", input, celsiusToKelvin(input));
                break;
            case '5': // Exit
                printf("Thank you for using the Temperature Converter!\n");
                break;
            default: // Invalid input
                printf("Invalid option selected. Please try again.\n\n");
        }

    } while(choice!= '5'); // Continue loop until user chooses to exit

    return 0;
}