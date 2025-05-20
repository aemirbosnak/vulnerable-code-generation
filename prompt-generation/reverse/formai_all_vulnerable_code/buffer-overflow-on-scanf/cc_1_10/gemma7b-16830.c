//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void convert_units(float value, char from_unit, char to_unit)
{
    float conversion_factor;

    switch (from_unit)
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
        case 'L':
            conversion_factor = 1000;
            break;
        case 'ml':
            conversion_factor = 1000;
            break;
        default:
            printf("Invalid unit conversion.");
            exit(1);
    }

    switch (to_unit)
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
        case 'L':
            conversion_factor = 1000;
            break;
        case 'ml':
            conversion_factor = 1000;
            break;
        default:
            printf("Invalid unit conversion.");
            exit(1);
    }

    value *= conversion_factor;

    printf("%f %s converted to %f %s is %.2f", value, from_unit, to_unit, value * conversion_factor);
}

int main()
{
    float value;
    char from_unit;
    char to_unit;

    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the from unit: ");
    scanf(" %c", &from_unit);

    printf("Enter the to unit: ");
    scanf(" %c", &to_unit);

    convert_units(value, from_unit, to_unit);

    return 0;
}