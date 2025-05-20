//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function to convert Celsius to Fahrenheit */
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

/* Function to convert Fahrenheit to Celsius */
float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

/* Function to convert Kelvin to Celsius */
float kelvin_to_celsius(float kelvin) {
    float celsius = kelvin - 273.15;
    return celsius;
}

/* Function to convert Celsius to Kelvin */
float celsius_to_kelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

/* Function to convert Kelvin to Fahrenheit */
float kelvin_to_fahrenheit(float kelvin) {
    float fahrenheit = (kelvin - 273.15) * 9/5 + 32;
    return fahrenheit;
}

/* Function to convert Fahrenheit to Kelvin */
float fahrenheit_to_kelvin(float fahrenheit) {
    float kelvin = (fahrenheit + 459.67) * 5/9;
    return kelvin;
}

int main() {
    float celsius, fahrenheit, kelvin;
    char choice;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    printf("Enter the unit of temperature you want to convert to:\n");
    printf("C for Celsius\n");
    printf("F for Fahrenheit\n");
    printf("K for Kelvin\n");
    scanf(" %c", &choice);

    switch(choice) {
        case 'C':
        case 'c':
            printf("The temperature in Celsius is: %.2f\n", celsius);
            break;
        case 'F':
        case 'f':
            printf("The temperature in Fahrenheit is: %.2f\n", celsius_to_fahrenheit(celsius));
            break;
        case 'K':
        case 'k':
            printf("The temperature in Kelvin is: %.2f\n", celsius_to_kelvin(celsius));
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}