//FormAI DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Function to convert temperature from Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert temperature from Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to convert length from meters to feet
double metersToFeet(double meters) {
    return meters * 3.281;
}

// Function to convert length from feet to meters
double feetToMeters(double feet) {
    return feet / 3.281;
}

// Function to convert weight from kilograms to pounds
double kilogramsToPounds(double kilograms) {
    return kilograms * 2.205;
}

// Function to convert weight from pounds to kilograms
double poundsToKilograms(double pounds) {
    return pounds / 2.205;
}

int main() {
    int choice;
    double value, result;

    printf("Welcome to the Peaceful Unit Converter!\n\n");

    while (1) {
        // Display the menu
        printf("Which conversion would you like to perform?\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Meters to Feet\n");
        printf("4. Feet to Meters\n");
        printf("5. Kilograms to Pounds\n");
        printf("6. Pounds to Kilograms\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        // Perform the selected conversion
        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &value);
                result = celsiusToFahrenheit(value);
                printf("%.2f degrees Celsius = %.2f degrees Fahrenheit\n\n", value, result);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &value);
                result = fahrenheitToCelsius(value);
                printf("%.2f degrees Fahrenheit = %.2f degrees Celsius\n\n", value, result);
                break;
            case 3:
                printf("Enter length in meters: ");
                scanf("%lf", &value);
                result = metersToFeet(value);
                printf("%.2f meters = %.2f feet\n\n", value, result);
                break;
            case 4:
                printf("Enter length in feet: ");
                scanf("%lf", &value);
                result = feetToMeters(value);
                printf("%.2f feet = %.2f meters\n\n", value, result);
                break;
            case 5:
                printf("Enter weight in kilograms: ");
                scanf("%lf", &value);
                result = kilogramsToPounds(value);
                printf("%.2f kilograms = %.2f pounds\n\n", value, result);
                break;
            case 6:
                printf("Enter weight in pounds: ");
                scanf("%lf", &value);
                result = poundsToKilograms(value);
                printf("%.2f pounds = %.2f kilograms\n\n", value, result);
                break;
            case 7:
                printf("Thank you for using the Peaceful Unit Converter!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n\n");
        }
    }

    return 0;
}