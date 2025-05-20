//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char unit_from, unit_to;
    float temperature;

    printf("Welcome to the post-apocalyptic temperature converter.\n");
    printf("Please enter the unit of temperature you want to convert from: (F/C/K)\n");
    scanf("%c", &unit_from);

    printf("Please enter the temperature: ");
    scanf("%f", &temperature);

    switch (unit_from)
    {
        case 'F':
            unit_to = 'C';
            temperature = (temperature - 32) * 5 / 9;
            break;
        case 'C':
            unit_to = 'F';
            temperature = (temperature * 9 / 5) + 32;
            break;
        case 'K':
            unit_to = 'C';
            temperature = temperature - 273.15;
            break;
        default:
            printf("Invalid unit of temperature.\n");
            return;
    }

    printf("Please enter the unit of temperature you want to convert to: (F/C/K)\n");
    scanf("%c", &unit_to);

    switch (unit_to)
    {
        case 'F':
            printf("The temperature is: %.2f degrees Fahrenheit.\n", temperature);
            break;
        case 'C':
            printf("The temperature is: %.2f degrees Celsius.\n", temperature);
            break;
        case 'K':
            printf("The temperature is: %.2f degrees Kelvin.\n", temperature);
            break;
        default:
            printf("Invalid unit of temperature.\n");
            return;
    }
}