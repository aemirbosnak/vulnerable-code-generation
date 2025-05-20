//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double celsius, fahrenheit, kelvin;
    char choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("----------------------------------------\n");
    printf("Please choose the unit you want to convert from:\n");
    printf("C - Celsius\n");
    printf("F - Fahrenheit\n");
    printf("K - Kelvin\n");
    scanf(" %c", &choice);

    switch(choice) {
        case 'C':
        case 'c':
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &celsius);

            // Convert Celsius to Fahrenheit
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahrenheit);

            // Convert Celsius to Kelvin
            kelvin = celsius + 273.15;
            printf("%.2lf degrees Celsius is equal to %.2lf Kelvin.\n", celsius, kelvin);
            break;

        case 'F':
        case 'f':
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf", &fahrenheit);

            // Convert Fahrenheit to Celsius
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, celsius);

            // Convert Fahrenheit to Kelvin
            kelvin = (fahrenheit + 459.67) * 5/9;
            printf("%.2lf degrees Fahrenheit is equal to %.2lf Kelvin.\n", fahrenheit, kelvin);
            break;

        case 'K':
        case 'k':
            printf("Enter the temperature in Kelvin: ");
            scanf("%lf", &kelvin);

            // Convert Kelvin to Celsius
            celsius = kelvin - 273.15;
            printf("%.2lf Kelvin is equal to %.2lf degrees Celsius.\n", kelvin, celsius);

            // Convert Kelvin to Fahrenheit
            fahrenheit = (kelvin * 9/5) - 459.67;
            printf("%.2lf Kelvin is equal to %.2lf degrees Fahrenheit.\n", kelvin, fahrenheit);
            break;

        default:
            printf("Invalid choice. Please choose C, F or K.\n");
    }

    return 0;
}