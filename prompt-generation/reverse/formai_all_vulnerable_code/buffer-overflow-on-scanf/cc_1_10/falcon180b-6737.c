//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
#include <stdio.h>

/* Function prototypes */
float celsiusToFahrenheit(float);
float fahrenheitToCelsius(float);

int main() {
    float temperature, convertedTemperature;
    int choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter your choice:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        convertedTemperature = celsiusToFahrenheit(temperature);
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, convertedTemperature);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        convertedTemperature = fahrenheitToCelsius(temperature);
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, convertedTemperature);
    } else {
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}

/* Function to convert Celsius to Fahrenheit */
float celsiusToFahrenheit(float celsius) {
    float fahrenheit;

    fahrenheit = (celsius * 9/5) + 32;

    return fahrenheit;
}

/* Function to convert Fahrenheit to Celsius */
float fahrenheitToCelsius(float fahrenheit) {
    float celsius;

    celsius = (fahrenheit - 32) * 5/9;

    return celsius;
}