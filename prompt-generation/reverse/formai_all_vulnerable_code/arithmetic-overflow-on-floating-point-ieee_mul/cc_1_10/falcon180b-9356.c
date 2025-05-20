//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double celsius, fahrenheit, kelvin;
    char choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please select the unit you want to convert from:\n");
    printf("C: Celsius\n");
    printf("F: Fahrenheit\n");
    printf("K: Kelvin\n");
    scanf("%c", &choice);

    if(choice == 'C' || choice == 'c') {
        printf("Enter the temperature in Celsius: ");
        scanf("%lf", &celsius);

        fahrenheit = (celsius * 9/5) + 32;
        kelvin = celsius + 273.15;

        printf("\nTemperature Conversion:\n");
        printf("Celsius: %.2lf\n", celsius);
        printf("Fahrenheit: %.2lf\n", fahrenheit);
        printf("Kelvin: %.2lf\n", kelvin);
    }
    else if(choice == 'F' || choice == 'f') {
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%lf", &fahrenheit);

        celsius = (fahrenheit - 32) * 5/9;
        kelvin = (fahrenheit + 459.67) * 5/9;

        printf("\nTemperature Conversion:\n");
        printf("Fahrenheit: %.2lf\n", fahrenheit);
        printf("Celsius: %.2lf\n", celsius);
        printf("Kelvin: %.2lf\n", kelvin);
    }
    else if(choice == 'K' || choice == 'k') {
        printf("Enter the temperature in Kelvin: ");
        scanf("%lf", &kelvin);

        celsius = kelvin - 273.15;
        fahrenheit = (kelvin - 273.15) * 9/5 - 459.67;

        printf("\nTemperature Conversion:\n");
        printf("Kelvin: %.2lf\n", kelvin);
        printf("Celsius: %.2lf\n", celsius);
        printf("Fahrenheit: %.2lf\n", fahrenheit);
    }
    else {
        printf("Invalid input. Please enter C, F or K.\n");
    }

    return 0;
}