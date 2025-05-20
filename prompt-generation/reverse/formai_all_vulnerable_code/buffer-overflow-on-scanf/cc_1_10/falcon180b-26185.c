//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 1.8) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) / 1.8;
}

// Function to get user input
float getUserInput(char* prompt) {
    float input;
    printf("%s", prompt);
    if (scanf("%f", &input)!= 1) {
        printf("Invalid input. Please enter a number.\n");
        exit(1);
    }
    return input;
}

int main() {
    char choice;
    do {
        printf("Please choose an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Quit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("Enter temperature in Celsius: ");
                float celsius = getUserInput("Celsius");
                float fahrenheit = celsiusToFahrenheit(celsius);
                printf("%.2f Celsius is %.2f Fahrenheit.\n", celsius, fahrenheit);
                break;
            case '2':
                printf("Enter temperature in Fahrenheit: ");
                float fahrenheitInput = getUserInput("Fahrenheit");
                float celsiusResult = fahrenheitToCelsius(fahrenheitInput);
                printf("%.2f Fahrenheit is %.2f Celsius.\n", fahrenheitInput, celsiusResult);
                break;
            case '3':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '3');
    return 0;
}