//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}

int main() {
    char input[100];
    char unit;
    float temperature;
    int choice;

    // Display program introduction
    printf("Welcome to the Medieval Temperature Converter!\n");
    printf("Convert between Celsius and Fahrenheit with ease!\n");
    printf("Enter 'C' to convert from Celsius to Fahrenheit.\n");
    printf("Enter 'F' to convert from Fahrenheit to Celsius.\n");
    printf("Enter 'Q' to quit the program.\n");

    // Main program loop
    do {
        // Get user input
        printf("Enter your choice: ");
        fgets(input, 100, stdin);

        // Convert input to uppercase
        for (int i = 0; input[i]!= '\0'; i++) {
            input[i] = toupper(input[i]);
        }

        // Get temperature and unit of measurement
        if (sscanf(input, "%c %f", &unit, &temperature)!= 2) {
            printf("Invalid input. Please enter a valid temperature and unit.\n");
            continue;
        }

        // Convert temperature if valid input
        switch (unit) {
            case 'C':
                printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", temperature, celsiusToFahrenheit(temperature));
                break;
            case 'F':
                printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", temperature, fahrenheitToCelsius(temperature));
                break;
            default:
                printf("Invalid unit of measurement. Please enter either 'C' or 'F'.\n");
        }

    } while (choice!= 'Q');

    // Display program conclusion
    printf("Thank you for using the Medieval Temperature Converter!\n");

    return 0;
}