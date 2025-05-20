//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char choice;
    double fahrenheit, celsius, kelvin;

    printf("Welcome to the Temperature Converter!\n\n");
    printf("Please choose a temperature unit:\n");
    printf("1. Fahrenheit\n");
    printf("2. Celsius\n");
    printf("3. Kelvin\n");
    scanf("%c", &choice);

    while (choice!= '1' && choice!= '2' && choice!= '3') {
        printf("Invalid input. Please enter a valid temperature unit:\n");
        printf("1. Fahrenheit\n");
        printf("2. Celsius\n");
        printf("3. Kelvin\n");
        scanf("%c", &choice);
    }

    switch (choice) {
        case '1':
            printf("Please enter the temperature in Fahrenheit:\n");
            scanf("%lf", &fahrenheit);

            celsius = (fahrenheit - 32) * 5 / 9;
            kelvin = (fahrenheit + 459.67) * 5 / 9;

            printf("%.2lf degrees Fahrenheit is equivalent to %.2lf degrees Celsius or %.2lf Kelvin.\n", fahrenheit, celsius, kelvin);

            break;

        case '2':
            printf("Please enter the temperature in Celsius:\n");
            scanf("%lf", &celsius);

            fahrenheit = (celsius * 9 / 5) + 32;
            kelvin = celsius + 273.15;

            printf("%.2lf degrees Celsius is equivalent to %.2lf degrees Fahrenheit or %.2lf Kelvin.\n", celsius, fahrenheit, kelvin);

            break;

        case '3':
            printf("Please enter the temperature in Kelvin:\n");
            scanf("%lf", &kelvin);

            celsius = kelvin - 273.15;
            fahrenheit = (kelvin - 273.15) * 9 / 5;

            printf("%.2lf Kelvin is equivalent to %.2lf degrees Celsius or %.2lf degrees Fahrenheit.\n", kelvin, celsius, fahrenheit);

            break;

        default:
            printf("Invalid input. Please enter a valid temperature unit.\n");
    }

    return 0;
}