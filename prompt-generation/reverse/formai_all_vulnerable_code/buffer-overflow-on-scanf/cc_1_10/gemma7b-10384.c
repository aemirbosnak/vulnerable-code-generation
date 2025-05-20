//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: cheerful
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
        case 'L':
            conversion_factor = 1000;
            break;
        case 'g':
            conversion_factor = 1000;
            break;
        case 'h':
            conversion_factor = 24;
            break;
        case 's':
            conversion_factor = 60;
            break;
        default:
            printf("Invalid unit conversion.\n");
            return;
    }

    switch (to_unit)
    {
        case 'm':
            conversion_factor = 1 / conversion_factor;
            break;
        case 'kg':
            conversion_factor = 1 / conversion_factor;
            break;
        case 'L':
            conversion_factor = 1 / conversion_factor;
            break;
        case 'g':
            conversion_factor = 1 / conversion_factor;
            break;
        case 'h':
            conversion_factor = 24 * conversion_factor;
            break;
        case 's':
            conversion_factor = 60 * conversion_factor;
            break;
        default:
            printf("Invalid unit conversion.\n");
            return;
    }

    value *= conversion_factor;

    printf("Converted value: %.2f %s\n", value, to_unit);
}

int main()
{
    float value;
    char from_unit, to_unit;

    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the from unit: ");
    scanf(" %c", &from_unit);

    printf("Enter the to unit: ");
    scanf(" %c", &to_unit);

    convert_units(value, from_unit, to_unit);

    return 0;
}