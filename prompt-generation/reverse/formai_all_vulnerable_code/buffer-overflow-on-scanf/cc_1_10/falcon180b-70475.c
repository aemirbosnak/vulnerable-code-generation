//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Fahrenheit to Kelvin
double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit + 459.67) * 5/9;
}

// Function to convert Kelvin to Fahrenheit
double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}

int main() {
    double celsius, fahrenheit, kelvin;
    char choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please choose the temperature unit you want to convert from:\n");
    printf("C - Celsius\n");
    printf("F - Fahrenheit\n");
    printf("K - Kelvin\n");
    scanf("%c", &choice);

    switch(choice) {
        case 'C':
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &celsius);

            printf("The temperature in Fahrenheit is: %.2lf\n", celsiusToFahrenheit(celsius));
            printf("The temperature in Kelvin is: %.2lf\n", celsiusToKelvin(celsius));

            break;

        case 'F':
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf", &fahrenheit);

            printf("The temperature in Celsius is: %.2lf\n", fahrenheitToCelsius(fahrenheit));
            printf("The temperature in Kelvin is: %.2lf\n", fahrenheitToKelvin(fahrenheit));

            break;

        case 'K':
            printf("Enter the temperature in Kelvin: ");
            scanf("%lf", &kelvin);

            printf("The temperature in Celsius is: %.2lf\n", kelvinToCelsius(kelvin));
            printf("The temperature in Fahrenheit is: %.2lf\n", kelvinToFahrenheit(kelvin));

            break;

        default:
            printf("Invalid choice!\n");
            exit(0);
    }

    return 0;
}