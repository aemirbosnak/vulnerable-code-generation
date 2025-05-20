//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    char choice;
    double celsius, fahrenheit, kelvin;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please choose a conversion method:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");

    scanf("%c", &choice);

    switch(choice) {
        case '1':
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", celsius, fahrenheit);
            break;
        case '2':
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &celsius);
            kelvin = celsius + 273.15;
            printf("%.2lf Celsius is equal to %.2lf Kelvin.\n", celsius, kelvin);
            break;
        case '3':
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", fahrenheit, celsius);
            break;
        case '4':
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &fahrenheit);
            kelvin = (fahrenheit + 459.67) * 5/9;
            printf("%.2lf Fahrenheit is equal to %.2lf Kelvin.\n", fahrenheit, kelvin);
            break;
        case '5':
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &kelvin);
            celsius = kelvin - 273.15;
            printf("%.2lf Kelvin is equal to %.2lf Celsius.\n", kelvin, celsius);
            break;
        case '6':
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &kelvin);
            fahrenheit = (kelvin * 9/5) - 459.67;
            printf("%.2lf Kelvin is equal to %.2lf Fahrenheit.\n", kelvin, fahrenheit);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }

    return 0;
}