//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void convert_units(double value, char from_unit, char to_unit)
{
    double conversion_factor;

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
        case 'min':
            conversion_factor = 60;
            break;
        case 's':
            conversion_factor = 1;
            break;
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
            conversion_factor = 1 / conversion_factor;
            break;
        case 'min':
            conversion_factor = 1 / conversion_factor;
            break;
        case 's':
            conversion_factor = 1;
            break;
    }

    value *= conversion_factor;

    printf("%f %s converted to %f %s is %f", value, from_unit, to_unit, conversion_factor, value * conversion_factor);
}

int main()
{
    double value;
    char from_unit;
    char to_unit;

    printf("Enter the value:");
    scanf("%lf", &value);

    printf("Enter the from unit:");
    scanf(" %c", &from_unit);

    printf("Enter the to unit:");
    scanf(" %c", &to_unit);

    convert_units(value, from_unit, to_unit);

    return 0;
}