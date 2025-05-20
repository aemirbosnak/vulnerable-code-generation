//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    char choice;
    double celsius, fahrenheit, kelvin;

    printf("Welcome to the Ada Lovelace Temperature Converter!\n");
    printf("Please choose a temperature unit to convert to:\n");
    printf("C - Celsius\n");
    printf("F - Fahrenheit\n");
    printf("K - Kelvin\n");

    scanf("%c", &choice);

    printf("Please enter the temperature you would like to convert:\n");
    scanf("%lf", &celsius);

    switch (choice) {
        case 'C':
            fahrenheit = (celsius * 1.8) + 32;
            kelvin = celsius + 273.15;

            printf("%.2lf degrees Celsius is equal to:\n", celsius);
            printf("%.2lf degrees Fahrenheit\n", fahrenheit);
            printf("%.2lf Kelvins\n", kelvin);

            break;

        case 'F':
            celsius = (fahrenheit - 32) / 1.8;
            kelvin = (fahrenheit + 459.67) * 5/9;

            printf("%.2lf degrees Fahrenheit is equal to:\n", fahrenheit);
            printf("%.2lf degrees Celsius\n", celsius);
            printf("%.2lf Kelvins\n", kelvin);

            break;

        case 'K':
            celsius = kelvin - 273.15;
            fahrenheit = (celsius * 1.8) + 32;

            printf("%.2lf Kelvins is equal to:\n", kelvin);
            printf("%.2lf degrees Celsius\n", celsius);
            printf("%.2lf degrees Fahrenheit\n", fahrenheit);

            break;

        default:
            printf("Invalid choice. Please choose C, F, or K.\n");
    }

    return 0;
}