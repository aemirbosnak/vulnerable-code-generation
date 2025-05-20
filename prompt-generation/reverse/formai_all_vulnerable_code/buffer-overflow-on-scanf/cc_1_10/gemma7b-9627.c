//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>
#include <math.h>

void UnitConverter(float value, char unit_from, char unit_to)
{
    float conversion_factor = 1;
    switch (unit_from)
    {
        case 'm':
            conversion_factor = 1000;
            break;
        case 'kg':
            conversion_factor = 1000;
            break;
        case 'g':
            conversion_factor = 1000;
            break;
        case 'l':
            conversion_factor = 1000;
            break;
        case 'km':
            conversion_factor = 1000;
            break;
    }

    switch (unit_to)
    {
        case 'm':
            conversion_factor = 1;
            break;
        case 'kg':
            conversion_factor = 1000;
            break;
        case 'g':
            conversion_factor = 1000;
            break;
        case 'l':
            conversion_factor = 1000;
            break;
        case 'km':
            conversion_factor = 1000;
            break;
    }

    float converted_value = value * conversion_factor;

    printf("The converted value is: %.2f %s\n", converted_value, unit_to);
}

int main()
{
    float value;
    char unit_from;
    char unit_to;

    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the unit of the value: ");
    scanf(" %c", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf(" %c", &unit_to);

    UnitConverter(value, unit_from, unit_to);

    return 0;
}