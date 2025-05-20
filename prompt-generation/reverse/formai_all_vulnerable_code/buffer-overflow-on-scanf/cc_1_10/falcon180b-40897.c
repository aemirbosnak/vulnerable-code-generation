//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to validate user input
int isValidInput(char *input) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

int main() {
    char input[100];
    float temperature;
    int choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter a temperature in Celsius or Fahrenheit: ");
    scanf("%s", input);

    // Validate user input
    if (!isValidInput(input)) {
        printf("Invalid input. Please enter a valid temperature.\n");
        return 0;
    }

    // Convert user input to float
    temperature = atof(input);

    // Ask user for conversion type
    printf("Please enter 1 for Celsius to Fahrenheit conversion or 2 for Fahrenheit to Celsius conversion: ");
    scanf("%d", &choice);

    // Convert temperature based on user choice
    switch (choice) {
        case 1:
            temperature = celsiusToFahrenheit(temperature);
            printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", temperature, temperature);
            break;
        case 2:
            temperature = fahrenheitToCelsius(temperature);
            printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", temperature, temperature);
            break;
        default:
            printf("Invalid choice. Please enter either 1 or 2.\n");
            return 0;
    }

    return 0;
}