//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);

int main() {
    char choice;
    double temperature;

    printf("Welcome to the Sherlock Holmes Temperature Converter!\n");
    printf("Please choose an option:\n");
    printf("C) Convert from Celsius to Fahrenheit\n");
    printf("F) Convert from Fahrenheit to Celsius\n");
    printf("Q) Quit\n");

    scanf("%c", &choice);

    switch(choice) {
        case 'C':
        case 'c':
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &temperature);
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, celsius_to_fahrenheit(temperature));
            break;
        case 'F':
        case 'f':
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temperature, fahrenheit_to_celsius(temperature));
            break;
        case 'Q':
        case 'q':
            printf("Thank you for using the Sherlock Holmes Temperature Converter!\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}