//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>
#include <math.h>

void unit_converter(double value, char from_unit, char to_unit)
{
    double conversion_factor;
    switch (from_unit)
    {
        case 'm':
            switch (to_unit)
            {
                case 'km':
                    conversion_factor = 1000;
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
                case 'g':
                    conversion_factor = 1000;
                    break;
                case 't':
                    conversion_factor = 1000000;
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
            }
            break;
    }

    double converted_value = value * conversion_factor;

    printf("%lf %s converted to %lf %s is %lf", value, from_unit, to_unit, converted_value);
    printf("\n");
}

int main()
{
    unit_converter(10, 'm', 'km');
    unit_converter(20, 'kg', 'g');
    unit_converter(50, 'L', 'ml');

    return 0;
}