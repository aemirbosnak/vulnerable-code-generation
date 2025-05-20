//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the unit conversion function
double unit_conversion(double value, char from_unit, char to_unit)
{
    double conversion_factor = 0;
    switch (from_unit)
    {
        case 'm':
            switch (to_unit)
            {
                case 'km':
                    conversion_factor = 1000;
                    break;
                case 'hm':
                    conversion_factor = 100;
                    break;
                case 'dm':
                    conversion_factor = 10;
                    break;
                case 'cm':
                    conversion_factor = 100;
                    break;
                case 'mm':
                    conversion_factor = 1000;
                    break;
            }
            break;
        case 'kg':
            switch (to_unit)
            {
                case 't':
                    conversion_factor = 1000;
                    break;
                case 'g':
                    conversion_factor = 1000;
                    break;
                case 'lb':
                    conversion_factor = 2.2046;
                    break;
                case 'oz':
                    conversion_factor = 32.15;
                    break;
            }
            break;
        case 'L':
            switch (to_unit)
            {
                case 'ml':
                    conversion_factor = 1000;
                    break;
                case 'dl':
                    conversion_factor = 1000;
                    break;
                case 'gal':
                    conversion_factor = 3.785;
                    break;
            }
            break;
    }

    return value * conversion_factor;
}

int main()
{
    double value = 0;
    char from_unit = '\0';
    char to_unit = '\0';

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the from unit (e.g. m, kg, L): ");
    scanf(" %c", &from_unit);

    printf("Enter the to unit (e.g. km, t, gal): ");
    scanf(" %c", &to_unit);

    double converted_value = unit_conversion(value, from_unit, to_unit);

    printf("The converted value is: %.2lf %s", converted_value, to_unit);

    return 0;
}