//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: ephemeral
#include <stdio.h>
#include <math.h>

int main() {
    double celsius, fahrenheit, kelvin;
    char choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter 'C' for Celsius to Fahrenheit/Kelvin conversion,\n");
    printf("'F' for Fahrenheit to Celsius/Kelvin conversion,\n");
    printf("'K' for Kelvin to Celsius/Fahrenheit conversion:\n");
    scanf("%c", &choice);

    switch(choice) {
        case 'C':
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &celsius);

            fahrenheit = celsius * 9/5 + 32;
            printf("%lf degrees Celsius is equal to %lf degrees Fahrenheit.\n", celsius, fahrenheit);

            kelvin = celsius + 273.15;
            printf("%lf degrees Celsius is equal to %lf Kelvin.\n", celsius, kelvin);

            break;

        case 'F':
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &fahrenheit);

            celsius = (fahrenheit - 32) * 5/9;
            printf("%lf degrees Fahrenheit is equal to %lf degrees Celsius.\n", fahrenheit, celsius);

            kelvin = (fahrenheit + 459.67) * 5/9;
            printf("%lf degrees Fahrenheit is equal to %lf Kelvin.\n", fahrenheit, kelvin);

            break;

        case 'K':
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &kelvin);

            celsius = kelvin - 273.15;
            printf("%lf Kelvin is equal to %lf degrees Celsius.\n", kelvin, celsius);

            fahrenheit = kelvin * 9/5 - 459.67;
            printf("%lf Kelvin is equal to %lf degrees Fahrenheit.\n", kelvin, fahrenheit);

            break;

        default:
            printf("Invalid input. Please enter 'C', 'F' or 'K'.\n");
    }

    return 0;
}