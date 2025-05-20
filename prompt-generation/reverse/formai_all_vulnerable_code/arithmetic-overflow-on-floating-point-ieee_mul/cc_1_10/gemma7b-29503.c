//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>
#include <math.h>

// Function to convert units
double unit_converter(double value, char from_unit, char to_unit)
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
                case 'hm':
                    conversion_factor = 100;
                    break;
                case 'dm':
                    conversion_factor = 10;
                    break;
                case 'cm':
                    conversion_factor = 1000;
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
            }
            break;
        case 's':
            switch (to_unit)
            {
                case 'min':
                    conversion_factor = 60;
                    break;
                case 'h':
                    conversion_factor = 3600;
                    break;
                case 'd':
                    conversion_factor = 86400;
                    break;
            }
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
    scanf("%c", &from_unit);

    printf("Enter the to unit: ");
    scanf("%c", &to_unit);

    double converted_value = unit_converter(value, from_unit, to_unit);

    printf("The converted value is: %.2lf %s", converted_value, to_unit);

    return 0;
}