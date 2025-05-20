//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double celsius, fahrenheit, kelvin;
    char choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please choose a temperature unit to convert from:\n");
    printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n");
    scanf("%c", &choice);

    switch(choice)
    {
        case '1':
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &celsius);

            fahrenheit = (celsius * 9/5) + 32;
            kelvin = celsius + 273.15;

            printf("\n%lf degrees Celsius is:\n", celsius);
            printf("%.2lf degrees Fahrenheit\n", fahrenheit);
            printf("%.2lf Kelvin\n", kelvin);
            break;

        case '2':
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &fahrenheit);

            celsius = (fahrenheit - 32) * 5/9;
            kelvin = (fahrenheit + 459.67) * 5/9;

            printf("\n%lf degrees Fahrenheit is:\n", fahrenheit);
            printf("%.2lf degrees Celsius\n", celsius);
            printf("%.2lf Kelvin\n", kelvin);
            break;

        case '3':
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &kelvin);

            celsius = kelvin - 273.15;
            fahrenheit = (kelvin - 273.15) * 9/5 + 32;

            printf("\n%lf Kelvin is:\n", kelvin);
            printf("%.2lf degrees Celsius\n", celsius);
            printf("%.2lf degrees Fahrenheit\n", fahrenheit);
            break;

        default:
            printf("Invalid choice.\n");
            exit(0);
    }

    return 0;
}