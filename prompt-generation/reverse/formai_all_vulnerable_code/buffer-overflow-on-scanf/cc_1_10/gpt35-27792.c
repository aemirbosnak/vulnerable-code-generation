//FormAI DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Fahrenheit to Kelvin
double fahrenheitToKelvin(double fahrenheit) {
    return (5 * (fahrenheit - 32) / 9) + 273.15;
}

// Function to convert Kelvin to Fahrenheit
double kelvinToFahrenheit(double kelvin) {
    return (9 * (kelvin - 273.15) / 5) + 32;
}

int main() {
    int choice;
    double input;

    printf("Please choose from the following options:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    printf("Enter the input value: ");
    scanf("%lf", &input);

    double output;

    switch (choice) {
        case 1:
            output = celsiusToFahrenheit(input);
            printf("%.2f Celsius is equal to %.2f Fahrenheit\n", input, output);
            break;

        case 2:
            output = fahrenheitToCelsius(input);
            printf("%.2f Fahrenheit is equal to %.2f Celsius\n", input, output);
            break;

        case 3:
            output = celsiusToKelvin(input);
            printf("%.2f Celsius is equal to %.2f Kelvin\n", input, output);
            break;

        case 4:
            output = kelvinToCelsius(input);
            printf("%.2f Kelvin is equal to %.2f Celsius\n", input, output);
            break;

        case 5:
            output = fahrenheitToKelvin(input);
            printf("%.2f Fahrenheit is equal to %.2f Kelvin\n", input, output);
            break;

        case 6:
            output = kelvinToFahrenheit(input);
            printf("%.2f Kelvin is equal to %.2f Fahrenheit\n", input, output);
            break;

        default:
            printf("Invalid selection\n");
            return 1;
    }

    return 0;
}