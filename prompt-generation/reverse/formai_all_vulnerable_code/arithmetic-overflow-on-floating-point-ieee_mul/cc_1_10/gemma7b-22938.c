//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the unit converter function
double unit_converter(double value, char from_unit, char to_unit)
{
    double conversion_factor = 1.0;
    switch (from_unit)
    {
        case 'm':
            conversion_factor = 1000.0;
            break;
        case 'kg':
            conversion_factor = 1000.0;
            break;
        case 'l':
            conversion_factor = 1000.0;
            break;
        case 'km':
            conversion_factor = 1000.0;
            break;
        case 'g':
            conversion_factor = 0.001;
            break;
        case 'h':
            conversion_factor = 24.0;
            break;
        case 'min':
            conversion_factor = 60.0;
            break;
        case 's':
            conversion_factor = 1.0;
            break;
    }

    switch (to_unit)
    {
        case 'm':
            conversion_factor = 1.0 / 1000.0;
            break;
        case 'kg':
            conversion_factor = 1.0 / 1000.0;
            break;
        case 'l':
            conversion_factor = 1.0 / 1000.0;
            break;
        case 'km':
            conversion_factor = 1.0 / 1000.0;
            break;
        case 'g':
            conversion_factor = 1000.0;
            break;
        case 'h':
            conversion_factor = 1.0 / 24.0;
            break;
        case 'min':
            conversion_factor = 1.0 / 60.0;
            break;
        case 's':
            conversion_factor = 1.0;
            break;
    }

    return value * conversion_factor;
}

int main()
{
    double value;
    char from_unit;
    char to_unit;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the from unit: ");
    scanf(" %c", &from_unit);

    printf("Enter the to unit: ");
    scanf(" %c", &to_unit);

    double converted_value = unit_converter(value, from_unit, to_unit);

    printf("The converted value is: %.2lf %s", converted_value, to_unit);

    return 0;
}