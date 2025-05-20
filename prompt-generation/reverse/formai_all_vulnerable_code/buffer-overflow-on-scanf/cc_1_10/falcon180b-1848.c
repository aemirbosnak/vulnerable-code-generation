//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_CELSIUS 1000
#define MIN_CELSIUS -273.15

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return ((celsius * 9.0) / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return ((fahrenheit - 32.0) * 5.0) / 9.0;
}

// Function to validate Celsius input
int validateCelsius(float celsius) {
    if (celsius < MIN_CELSIUS || celsius > MAX_CELSIUS) {
        printf("Invalid Celsius temperature. Please enter a temperature between %0.2f and %0.2f.\n", MIN_CELSIUS, MAX_CELSIUS);
        return FALSE;
    }
    return TRUE;
}

// Function to validate Fahrenheit input
int validateFahrenheit(float fahrenheit) {
    if (fahrenheit < -459.67 || fahrenheit > 1000) {
        printf("Invalid Fahrenheit temperature. Please enter a temperature between %0.2f and %0.2f.\n", -459.67, 1000);
        return FALSE;
    }
    return TRUE;
}

int main() {
    float celsius, fahrenheit;
    char choice;

    do {
        printf("Enter temperature in Celsius: ");
        if (scanf("%f", &celsius)!= 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (!validateCelsius(celsius)) {
            continue;
        }

        printf("Enter temperature in Fahrenheit: ");
        if (scanf("%f", &fahrenheit)!= 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (!validateFahrenheit(fahrenheit)) {
            continue;
        }

        printf("Enter your choice:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, celsiusToFahrenheit(celsius));
                break;
            case '2':
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, fahrenheitToCelsius(fahrenheit));
                break;
            default:
                printf("Invalid choice. Please enter 1 or 2.\n");
                break;
        }

    } while (TRUE);

    return 0;
}