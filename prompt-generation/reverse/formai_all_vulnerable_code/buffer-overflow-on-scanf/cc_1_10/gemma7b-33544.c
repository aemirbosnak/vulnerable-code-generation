//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the conversion function
double convert_units(double value, char from_unit, char to_unit)
{
    switch (from_unit)
    {
        case 'm':
            switch (to_unit)
            {
                case 'kg':
                    return value * 1000;
                case 'g':
                    return value * 1000000;
                case 't':
                    return value * 1000000000;
            }
            break;
        case 'kg':
            switch (to_unit)
            {
                case 'm':
                    return value * 0.001;
                case 'g':
                    return value * 1000;
                case 't':
                    return value * 1000000;
            }
            break;
        case 'g':
            switch (to_unit)
            {
                case 'm':
                    return value * 0.000001;
                case 'kg':
                    return value * 0.001;
                case 't':
                    return value * 1000000;
            }
            break;
        case 't':
            switch (to_unit)
            {
                case 'm':
                    return value * 0.0000001;
                case 'kg':
                    return value * 0.000001;
                case 'g':
                    return value * 0.001;
            }
            break;
    }

    return -1;
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

    if (converted_value != -1)
    {
        printf("The converted value is: %.2lf %s", converted_value, to_unit);
    }
    else
    {
        printf("Error converting units");
    }

    return 0;
}