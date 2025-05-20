//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    return celsius;
}

int main() {
    float celsius, fahrenheit;
    char choice;

    // Get user input for temperature in Celsius
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit
    fahrenheit = celsiusToFahrenheit(celsius);

    // Display temperature in Celsius and Fahrenheit
    printf("Temperature in Celsius: %.2f\n", celsius);
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);

    // Get user input for conversion
    printf("Enter choice for conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%c", &choice);

    // Convert temperature based on user input
    switch (choice) {
        case '1':
            fahrenheit = celsiusToFahrenheit(celsius);
            printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
            break;
        case '2':
            celsius = fahrenheitToCelsius(fahrenheit);
            printf("Temperature in Celsius: %.2f\n", celsius);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}