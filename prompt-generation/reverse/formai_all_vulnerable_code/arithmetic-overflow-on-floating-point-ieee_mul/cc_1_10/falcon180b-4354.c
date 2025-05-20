//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 9.0) / 5.0 + 32.0;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    return celsius;
}

// Function to validate user input
int validateInput(char *input) {
    int isValid = 1;
    int i = 0;

    // Check if input is a valid number
    while (isdigit(input[i]) == 0 && i < strlen(input)) {
        if (input[i]!= '.') {
            isValid = 0;
            break;
        }
        i++;
    }

    // Check if input is a valid Celsius temperature
    if (isValid) {
        double celsius = atof(input);
        if (celsius < -273.15 || celsius > 1000.0) {
            isValid = 0;
        }
    }

    return isValid;
}

// Function to get user input
char *getInput(char *prompt) {
    char input[100];
    printf("%s", prompt);
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character from input
    return input;
}

// Function to display menu
void displayMenu() {
    printf("\n");
    printf("Celsius to Fahrenheit Conversion\n");
    printf("=================================\n");
    printf("Enter a Celsius temperature to convert to Fahrenheit:\n");
    printf("1. Enter a Celsius temperature\n");
    printf("2. Quit\n");
    printf("\n");
}

int main() {
    char choice;
    char input[100];

    do {
        displayMenu();
        choice = getchar();
        getchar(); // Consume newline character

        switch (choice) {
            case '1':
                printf("Enter a Celsius temperature: ");
                fgets(input, 100, stdin);
                if (validateInput(input)) {
                    double celsius = atof(input);
                    double fahrenheit = celsiusToFahrenheit(celsius);
                    printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, fahrenheit);
                } else {
                    printf("Invalid input. Please enter a valid Celsius temperature.\n");
                }
                break;
            case '2':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice!= '2');

    return 0;
}