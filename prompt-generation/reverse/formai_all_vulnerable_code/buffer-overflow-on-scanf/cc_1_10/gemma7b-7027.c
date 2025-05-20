//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: secure
#include <stdio.h>

#include <stdlib.h>

void convert_fahrenheit_to_celsius(float f)
{
    float c = (f - 32) * 5 / 9;
    printf("Celsius: %.2f\n", c);
}

void convert_celsius_to_kelvin(float c)
{
    float k = c + 273.15;
    printf("Kelvin: %.2f\n", k);
}

void convert_fahrenheit_to_kelvin(float f)
{
    float c = (f - 32) * 5 / 9;
    float k = c + 273.15;
    printf("Celsius: %.2f\n", c);
    printf("Kelvin: %.2f\n", k);
}

int main()
{
    float temp;
    char unit;

    printf("Enter the temperature: ");
    scanf("%f", &temp);

    printf("Enter the unit (F/C/K): ");
    scanf(" %c", &unit);

    switch (unit)
    {
        case 'F':
            convert_fahrenheit_to_celsius(temp);
            break;
        case 'C':
            convert_celsius_to_kelvin(temp);
            break;
        case 'K':
            convert_fahrenheit_to_kelvin(temp);
            break;
        default:
            printf("Invalid unit.\n");
            break;
    }

    return 0;
}