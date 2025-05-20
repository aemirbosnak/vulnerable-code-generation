//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double celsius, fahrenheit, kelvin;
    char choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please choose a temperature unit:\n");
    printf("C for Celsius\n");
    printf("F for Fahrenheit\n");
    printf("K for Kelvin\n");
    scanf("%c", &choice);

    switch(choice) {
        case 'C':
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            kelvin = celsius + 273.15;

            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit or %.2lf Kelvin.\n", celsius, fahrenheit, kelvin);
            break;

        case 'F':
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            kelvin = (fahrenheit + 459.67) * 5/9;

            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius or %.2lf Kelvin.\n", fahrenheit, celsius, kelvin);
            break;

        case 'K':
            printf("Enter the temperature in Kelvin: ");
            scanf("%lf", &kelvin);
            celsius = kelvin - 273.15;
            fahrenheit = (kelvin - 273.15) * 9/5 + 32;

            printf("%.2lf Kelvin is equal to %.2lf degrees Celsius or %.2lf degrees Fahrenheit.\n", kelvin, celsius, fahrenheit);
            break;

        default:
            printf("Invalid choice, please choose a valid temperature unit.\n");
            break;
    }

    return 0;
}