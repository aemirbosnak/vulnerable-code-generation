//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main()
{
    double celsius, fahrenheit, kelvin;
    char choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please select the temperature unit you want to convert from:\n");
    printf("C - Celsius\n");
    printf("F - Fahrenheit\n");
    printf("K - Kelvin\n");
    scanf("%c", &choice);

    switch(choice)
    {
        case 'C':
        case 'c':
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &celsius);

            fahrenheit = (celsius * 1.8) + 32;
            kelvin = celsius + 273.15;

            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit or %.2lf Kelvin.\n", celsius, fahrenheit, kelvin);
            break;

        case 'F':
        case 'f':
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf", &fahrenheit);

            celsius = (fahrenheit - 32) / 1.8;
            kelvin = (fahrenheit + 459.67) * 5/9;

            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius or %.2lf Kelvin.\n", fahrenheit, celsius, kelvin);
            break;

        case 'K':
        case 'k':
            printf("Enter the temperature in Kelvin: ");
            scanf("%lf", &kelvin);

            celsius = kelvin - 273.15;
            fahrenheit = (kelvin - 273.15) * 9/5 + 32;

            printf("%.2lf Kelvin is equal to %.2lf degrees Celsius or %.2lf degrees Fahrenheit.\n", kelvin, celsius, fahrenheit);
            break;

        default:
            printf("Invalid choice. Please select C, F or K.\n");
    }

    return 0;
}