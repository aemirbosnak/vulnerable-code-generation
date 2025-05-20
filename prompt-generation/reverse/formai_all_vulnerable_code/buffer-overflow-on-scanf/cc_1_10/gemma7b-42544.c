//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: immersive
#include <stdio.h>
#include <math.h>

// Define the conversion function
double convert_units(double value, char from_unit, char to_unit)
{
    double conversion_factor = 1;

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
        case 'km':
            conversion_factor = 1000;
            break;
        case 'h':
            conversion_factor = 3600;
            break;
        case 'min':
            conversion_factor = 60;
            break;
    }

    switch (to_unit)
    {
        case 'm':
            conversion_factor = 1 / 1000;
            break;
        case 'kg':
            conversion_factor = 1 / 1000;
            break;
        case 'L':
            conversion_factor = 1 / 1000;
            break;
        case 'km':
            conversion_factor = 1 / 1000;
            break;
        case 'h':
            conversion_factor = 1 / 3600;
            break;
        case 'min':
            conversion_factor = 1 / 60;
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

    double converted_value = convert_units(value, from_unit, to_unit);

    printf("The converted value is: %.2lf %s", converted_value, to_unit);

    return 0;
}