//FormAI DATASET v1.0 Category: Unit converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

/*
 * Donald Knuth style Unit Converter
 */

/*
 * Function to convert Fahrenheit to Celsius
 */
double fahrenheit_to_celsius(double fahrenheit) {
    double celsius;
    celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

/*
 * Function to convert Celsius to Fahrenheit
 */
double celsius_to_fahrenheit(double celsius) {
    double fahrenheit;
    fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

/*
 * Function to convert Miles to Kilometers
 */
double miles_to_kilometers(double miles) {
    double kilometers;
    kilometers = miles * 1.609344;
    return kilometers;
}

/*
 * Function to convert Kilometers to Miles
 */
double kilometers_to_miles(double kilometers) {
    double miles;
    miles = kilometers / 1.609344;
    return miles;
}

int main() {
    int choice;
    double value;

    while (1) {
        printf("\nWelcome to Donald Knuth's Unit Converter\n");
        printf("Please select an option from the following:\n");
        printf("1. Fahrenheit to Celsius\n");
        printf("2. Celsius to Fahrenheit\n");
        printf("3. Miles to Kilometers\n");
        printf("4. Kilometers to Miles\n");
        printf("5. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("\nThank you for using Donald Knuth's Unit Converter\n");
            break;
        }

        printf("Enter the value to be converted: ");
        scanf("%lf", &value);

        switch (choice) {
            case 1:
                printf("%.2lf Fahrenheit is equal to %.2lf Celsius\n", value, fahrenheit_to_celsius(value));
                break;
            case 2:
                printf("%.2lf Celsius is equal to %.2lf Fahrenheit\n", value, celsius_to_fahrenheit(value));
                break;
            case 3:
                printf("%.2lf Miles is equal to %.2lf Kilometers\n", value, miles_to_kilometers(value));
                break;
            case 4:
                printf("%.2lf Kilometers is equal to %.2lf Miles\n", value, kilometers_to_miles(value));
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}