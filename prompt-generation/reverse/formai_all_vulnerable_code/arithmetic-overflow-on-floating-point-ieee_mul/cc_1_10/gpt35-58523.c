//FormAI DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>

// function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// function to convert Fahrenheit to Kelvin
double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit + 459.67) * 5 / 9;
}

// function to convert Kelvin to Fahrenheit
double kelvinToFahrenheit(double kelvin) {
    return (kelvin * 9 / 5) - 459.67;
}

int main() {
    int option;
    double value, result;

    printf("Unit Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("Enter option: ");
    scanf("%d", &option);

    printf("Enter value: ");
    scanf("%lf", &value);

    switch(option) {
        case 1:
            result = celsiusToFahrenheit(value);
            printf("%.2f Celsius = %.2f Fahrenheit", value, result);
            break;
        case 2:
            result = fahrenheitToCelsius(value);
            printf("%.2f Fahrenheit = %.2f Celsius", value, result);
            break;
        case 3:
            result = celsiusToKelvin(value);
            printf("%.2f Celsius = %.2f Kelvin", value, result);
            break;
        case 4:
            result = kelvinToCelsius(value);
            printf("%.2f Kelvin = %.2f Celsius", value, result);
            break;
        case 5:
            result = fahrenheitToKelvin(value);
            printf("%.2f Fahrenheit = %.2f Kelvin", value, result);
            break;
        case 6:
            result = kelvinToFahrenheit(value);
            printf("%.2f Kelvin = %.2f Fahrenheit", value, result);
            break;
        default:
            printf("Invalid option selected");
    }

    return 0;
}