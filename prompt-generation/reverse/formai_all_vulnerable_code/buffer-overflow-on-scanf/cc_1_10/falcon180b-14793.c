//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float celsius, fahrenheit, kelvin;
    char choice;

    // Prompt user for temperature unit
    printf("Enter the temperature unit (C/F/K): ");
    scanf("%c", &choice);

    // Convert Celsius to Fahrenheit and Kelvin
    if (choice == 'C' || choice == 'c') {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);

        fahrenheit = (celsius * 1.8) + 32;
        printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);

        kelvin = celsius + 273.15;
        printf("%.2f Celsius is equal to %.2f Kelvin.\n", celsius, kelvin);
    }

    // Convert Fahrenheit to Celsius and Kelvin
    else if (choice == 'F' || choice == 'f') {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);

        celsius = (fahrenheit - 32) / 1.8;
        printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, celsius);

        kelvin = (fahrenheit + 459.67) * 5/9;
        printf("%.2f Fahrenheit is equal to %.2f Kelvin.\n", fahrenheit, kelvin);
    }

    // Convert Kelvin to Celsius and Fahrenheit
    else if (choice == 'K' || choice == 'k') {
        printf("Enter temperature in Kelvin: ");
        scanf("%f", &kelvin);

        celsius = kelvin - 273.15;
        printf("%.2f Kelvin is equal to %.2f Celsius.\n", kelvin, celsius);

        fahrenheit = (kelvin - 273.15) * 9/5 + 32;
        printf("%.2f Kelvin is equal to %.2f Fahrenheit.\n", kelvin, fahrenheit);
    }

    // Invalid temperature unit
    else {
        printf("Invalid temperature unit. Please enter C, F or K.\n");
    }

    return 0;
}