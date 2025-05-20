//FormAI DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    double fahrenheit;
    fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    double celsius;
    celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    double kelvin;
    kelvin = celsius + 273.15;
    return kelvin;
}

// Function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    double celsius;
    celsius = kelvin - 273.15;
    return celsius;
}

int main() {
    int choice;
    double value, result;
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the Celsius value: ");
            scanf("%lf", &value);
            result = celsiusToFahrenheit(value);
            printf("%.2lf Celsius = %.2lf Fahrenheit", value, result);
            break;
        case 2:
            printf("Enter the Fahrenheit value: ");
            scanf("%lf", &value);
            result = fahrenheitToCelsius(value);
            printf("%.2lf Fahrenheit = %.2lf Celsius", value, result);
            break;
        case 3:
            printf("Enter the Celsius value: ");
            scanf("%lf", &value);
            result = celsiusToKelvin(value);
            printf("%.2lf Celsius = %.2lf Kelvin", value, result);
            break;
        case 4:
            printf("Enter the Kelvin value: ");
            scanf("%lf", &value);
            result = kelvinToCelsius(value);
            printf("%.2lf Kelvin = %.2lf Celsius", value, result);
            break;
        default:
            printf("Invalid choice");
            break;
    }

    return 0;
}