//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void unit_converter(double value, char unit_from, char unit_to)
{
    double conversion_factor = 0;
    switch (unit_from)
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

    switch (unit_to)
    {
        case 'm':
            value *= conversion_factor;
            break;
        case 'kg':
            value *= conversion_factor;
            break;
        case 'L':
            value *= conversion_factor;
            break;
        case 'g':
            value *= conversion_factor;
            break;
        case 'h':
            value /= conversion_factor;
            break;
        case 'min':
            value /= conversion_factor;
            break;
        case 's':
            value *= conversion_factor;
            break;
    }

    printf("%lf %s converted to %lf %s is %lf", value, unit_from, unit_to, conversion_factor, value * conversion_factor);
}

int main()
{
    double value;
    char unit_from;
    char unit_to;

    printf("Enter the value:");
    scanf("%lf", &value);

    printf("Enter the unit of the value:");
    scanf(" %c", &unit_from);

    printf("Enter the unit you want to convert to:");
    scanf(" %c", &unit_to);

    unit_converter(value, unit_from, unit_to);

    return 0;
}