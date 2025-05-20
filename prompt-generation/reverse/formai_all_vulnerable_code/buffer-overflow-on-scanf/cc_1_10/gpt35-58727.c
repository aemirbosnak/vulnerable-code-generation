//FormAI DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>

/* Function to convert Celsius to Fahrenheit */
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

/* Function to convert Fahrenheit to Celsius */
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

/* Function to convert Celsius to Kelvin */
float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

/* Function to convert Kelvin to Celsius */
float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

/* Function to convert Fahrenheit to Kelvin */
float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit + 459.67) * 5/9;
}

/* Function to convert Kelvin to Fahrenheit */
float kelvinToFahrenheit(float kelvin) {
    return (kelvin * 9/5) - 459.67;
}

int main() {
    float temperature;
    int option;

    printf("Welcome to the Temperature Converter\n");
    printf("-----------------------------------\n");
    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    printf("\nSelect an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("Enter option: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("\n%.2f Celsius = %.2f Fahrenheit\n", temperature, celsiusToFahrenheit(temperature));
            break;
        case 2:
            printf("\n%.2f Fahrenheit = %.2f Celsius\n", temperature, fahrenheitToCelsius(temperature));
            break;
        case 3:
            printf("\n%.2f Celsius = %.2f Kelvin\n", temperature, celsiusToKelvin(temperature));
            break;
        case 4:
            printf("\n%.2f Kelvin = %.2f Celsius\n", temperature, kelvinToCelsius(temperature));
            break;
        case 5:
            printf("\n%.2f Fahrenheit = %.2f Kelvin\n", temperature, fahrenheitToKelvin(temperature));
            break;
        case 6:
            printf("\n%.2f Kelvin = %.2f Fahrenheit\n", temperature, kelvinToFahrenheit(temperature));
            break;
        default:
            printf("\nInvalid option selected\n");
    }

    return 0;
}