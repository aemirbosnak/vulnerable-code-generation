//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265359

int main() {
    double temperature;
    double celsius;
    double fahrenheit;
    double kelvin;
    char choice;

    printf("Welcome to the Temperature Monitor!\n");
    printf("Please select a temperature unit:\n");
    printf("C) Celsius\n");
    printf("F) Fahrenheit\n");
    printf("K) Kelvin\n");
    scanf("%c", &choice);

    while (choice!= 'C' && choice!= 'F' && choice!= 'K') {
        printf("Invalid input. Please select a temperature unit:\n");
        printf("C) Celsius\n");
        printf("F) Fahrenheit\n");
        printf("K) Kelvin\n");
        scanf("%c", &choice);
    }

    switch (choice) {
        case 'C':
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);

            celsius = temperature;
            fahrenheit = (celsius * 9.0 / 5.0) + 32;
            kelvin = celsius + 273.15;

            printf("Temperature in Celsius: %.2lf\n", celsius);
            printf("Temperature in Fahrenheit: %.2lf\n", fahrenheit);
            printf("Temperature in Kelvin: %.2lf\n", kelvin);

            break;

        case 'F':
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temperature);

            celsius = (temperature - 32) * 5.0 / 9.0;
            fahrenheit = temperature;
            kelvin = (celsius + 273.15) * 9.0 / 5.0 + 32;

            printf("Temperature in Celsius: %.2lf\n", celsius);
            printf("Temperature in Fahrenheit: %.2lf\n", fahrenheit);
            printf("Temperature in Kelvin: %.2lf\n", kelvin);

            break;

        case 'K':
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &temperature);

            celsius = temperature - 273.15;
            fahrenheit = (celsius * 9.0 / 5.0) + 32;

            printf("Temperature in Celsius: %.2lf\n", celsius);
            printf("Temperature in Fahrenheit: %.2lf\n", fahrenheit);

            break;

        default:
            printf("Invalid input. Please select a temperature unit:\n");
            printf("C) Celsius\n");
            printf("F) Fahrenheit\n");
            printf("K) Kelvin\n");
            break;
    }

    return 0;
}