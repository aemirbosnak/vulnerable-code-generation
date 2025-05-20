//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: innovative
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}

// Function to convert Kelvin to Celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// Function to convert Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

int main() {
    int choice;
    float temperature, result;

    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            result = celsius_to_fahrenheit(temperature);
            printf("%.2f Celsius is equal to %.2f Fahrenheit\n", temperature, result);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            result = fahrenheit_to_celsius(temperature);
            printf("%.2f Fahrenheit is equal to %.2f Celsius\n", temperature, result);
            break;
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            result = kelvin_to_celsius(temperature);
            printf("%.2f Celsius is equal to %.2f Kelvin\n", temperature, result);
            break;
        case 4:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            result = celsius_to_kelvin(temperature);
            printf("%.2f Celsius is equal to %.2f Kelvin\n", temperature, result);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}