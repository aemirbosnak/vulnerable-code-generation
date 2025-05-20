//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: calm
#include <stdio.h>
#include <math.h>

void main()
{
    float temperature, conversion_factor;
    char unit, target_unit;

    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    printf("Enter the unit of the temperature (C/F/K): ");
    scanf(" %c", &unit);

    printf("Enter the target unit of the temperature (C/F/K): ");
    scanf(" %c", &target_unit);

    switch (unit)
    {
        case 'C':
            conversion_factor = 1;
            break;
        case 'F':
            conversion_factor = 1.8 + 0.0;
            break;
        case 'K':
            conversion_factor = 1.8 + 0.0;
            break;
        default:
            printf("Invalid unit.\n");
            return;
    }

    switch (target_unit)
    {
        case 'C':
            temperature = (temperature - 32) * conversion_factor;
            break;
        case 'F':
            temperature = (temperature * conversion_factor) + 32;
            break;
        case 'K':
            temperature = temperature + 273.15;
            break;
        default:
            printf("Invalid target unit.\n");
            return;
    }

    printf("The converted temperature is: %.2f %s.\n", temperature, target_unit);
}