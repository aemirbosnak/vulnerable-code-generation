//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    char choice;
    float celsius, fahrenheit, kelvin;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter the temperature you want to convert:\n");
    printf("C for Celsius, F for Fahrenheit, K for Kelvin: ");
    scanf("%c", &choice);

    switch(choice) {

        case 'C':
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);

            // Convert Celsius to Fahrenheit
            fahrenheit = (celsius * 9/5) + 32;
            printf("\n%f degrees Celsius is equal to %f degrees Fahrenheit.\n", celsius, fahrenheit);

            // Convert Celsius to Kelvin
            kelvin = celsius + 273.15;
            printf("\n%f degrees Celsius is equal to %f Kelvin.\n", celsius, kelvin);

            break;

        case 'F':
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);

            // Convert Fahrenheit to Celsius
            celsius = (fahrenheit - 32) * 5/9;
            printf("\n%f degrees Fahrenheit is equal to %f degrees Celsius.\n", fahrenheit, celsius);

            // Convert Fahrenheit to Kelvin
            kelvin = (fahrenheit + 459.67) * 5/9;
            printf("\n%f degrees Fahrenheit is equal to %f Kelvin.\n", fahrenheit, kelvin);

            break;

        case 'K':
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &kelvin);

            // Convert Kelvin to Celsius
            celsius = kelvin - 273.15;
            printf("\n%f Kelvin is equal to %f degrees Celsius.\n", kelvin, celsius);

            // Convert Kelvin to Fahrenheit
            fahrenheit = (kelvin - 273.15) * 9/5 + 32;
            printf("\n%f Kelvin is equal to %f degrees Fahrenheit.\n", kelvin, fahrenheit);

            break;

        default:
            printf("Invalid input. Please enter C for Celsius, F for Fahrenheit, or K for Kelvin.\n");
    }

    return 0;
}