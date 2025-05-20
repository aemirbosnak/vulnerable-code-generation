//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    return celsius;
}

// Function to get user input
double getUserInput(char *message, int min, int max) {
    double input;

    printf("%s", message);
    if (scanf("%lf", &input) == 1) {
        if (input < min || input > max) {
            printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
            return getUserInput(message, min, max);
        }
    } else {
        printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
        return getUserInput(message, min, max);
    }

    return input;
}

// Function to display menu and get user choice
int displayMenu() {
    int choice;

    printf("\n");
    printf("Temperature Converter Menu:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("\n");
    printf("Please enter your choice: ");

    if (scanf("%d", &choice)!= 1) {
        printf("Invalid input. Please enter a number between 1 and 3.\n");
        return getUserInput("Please enter your choice: ", 1, 3);
    }

    return choice;
}

int main() {
    int choice;
    double input;

    printf("Welcome to the Temperature Converter!\n\n");

    do {
        choice = displayMenu();

        switch (choice) {
            case 1:
                printf("Please enter the temperature in Celsius: ");
                input = getUserInput("", -273.15, 1000);
                printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", input, celsiusToFahrenheit(input));
                break;

            case 2:
                printf("Please enter the temperature in Fahrenheit: ");
                input = getUserInput("", -459.67, 1000);
                printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", input, fahrenheitToCelsius(input));
                break;

            case 3:
                printf("Thank you for using the Temperature Converter! Have a great day!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}