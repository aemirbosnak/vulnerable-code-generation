//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);
double kelvin_to_celsius(double kelvin);
double celsius_to_kelvin(double celsius);

int main() {
    int choice;
    double temperature;

    printf("Enter 1 to convert Celsius to Fahrenheit\n");
    printf("Enter 2 to convert Fahrenheit to Celsius\n");
    printf("Enter 3 to convert Celsius to Kelvin\n");
    printf("Enter 4 to convert Kelvin to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the temperature: ");
    scanf("%lf", &temperature);

    switch (choice) {
        case 1:
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit\n", temperature, celsius_to_fahrenheit(temperature));
            break;
        case 2:
            printf("%.2lf Fahrenheit is equal to %.2lf Celsius\n", temperature, fahrenheit_to_celsius(temperature));
            break;
        case 3:
            printf("%.2lf Celsius is equal to %.2lf Kelvin\n", temperature, kelvin_to_celsius(temperature));
            break;
        case 4:
            printf("%.2lf Kelvin is equal to %.2lf Celsius\n", temperature, celsius_to_kelvin(temperature));
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}