//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit)
{
    double celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius)
{
    double fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

int main()
{
    double temperature;
    char unit;
    char conversion_unit;

    printf("Enter the temperature: ");
    scanf("%lf", &temperature);

    printf("Enter the unit of temperature (F/C): ");
    scanf(" %c", &unit);

    printf("Enter the conversion unit (F/C): ");
    scanf(" %c", &conversion_unit);

    switch (unit)
    {
        case 'F':
            conversion_unit = 'C';
            temperature = fahrenheit_to_celsius(temperature);
            break;
        case 'C':
            conversion_unit = 'F';
            temperature = celsius_to_fahrenheit(temperature);
            break;
        default:
            printf("Invalid unit of temperature.\n");
            return 1;
    }

    printf("The converted temperature is: %.2lf %c.\n", temperature, conversion_unit);

    return 0;
}