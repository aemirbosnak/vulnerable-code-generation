//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    char choice;
    double num;
    int base;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please select a temperature unit to convert from:\n");
    printf("Celsius: c\n");
    printf("Fahrenheit: f\n");
    printf("Kelvin: k\n");
    printf("Please enter your choice: ");
    scanf(" %c", &choice);

    switch(choice)
    {
        case 'c':
        case 'C':
            printf("Please enter the temperature in Celsius: ");
            scanf("%lf", &num);
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit and %.2lf Kelvin.\n", num, (num*(9.0/5.0))+32, num+273.15);
            break;

        case 'f':
        case 'F':
            printf("Please enter the temperature in Fahrenheit: ");
            scanf("%lf", &num);
            printf("%.2lf Fahrenheit is equal to %.2lf Celsius and %.2lf Kelvin.\n", (num-32)*(5.0/9.0), (num-32)*(5.0/9.0)+273.15, num*(5.0/9.0)+273.15);
            break;

        case 'k':
        case 'K':
            printf("Please enter the temperature in Kelvin: ");
            scanf("%lf", &num);
            printf("%.2lf Kelvin is equal to %.2lf Celsius and %.2lf Fahrenheit.\n", num-273.15, num-273.15*(9.0/5.0), num*(9.0/5.0)-459.67);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}