//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char choice;
    double celsius, fahrenheit, kelvin;

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter 'C' to convert from Celsius to Fahrenheit and Kelvin.\n");
    printf("Enter 'F' to convert from Fahrenheit to Celsius and Kelvin.\n");
    printf("Enter 'K' to convert from Kelvin to Celsius and Fahrenheit.\n");
    scanf("%c", &choice);

    switch(choice) {
        case 'C':
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &celsius);

            fahrenheit = celsius * 9/5 + 32;
            printf("Temperature in Fahrenheit: %.2lf\n", fahrenheit);

            kelvin = celsius + 273.15;
            printf("Temperature in Kelvin: %.2lf\n", kelvin);
            break;

        case 'F':
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &fahrenheit);

            celsius = (fahrenheit - 32) * 5/9;
            printf("Temperature in Celsius: %.2lf\n", celsius);

            kelvin = (fahrenheit + 459.67) * 5/9;
            printf("Temperature in Kelvin: %.2lf\n", kelvin);
            break;

        case 'K':
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &kelvin);

            celsius = kelvin - 273.15;
            printf("Temperature in Celsius: %.2lf\n", celsius);

            fahrenheit = celsius * 9/5 + 32;
            printf("Temperature in Fahrenheit: %.2lf\n", fahrenheit);
            break;

        default:
            printf("Invalid choice!\n");
            exit(0);
    }

    return 0;
}