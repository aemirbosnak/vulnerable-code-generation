//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>
#include <math.h>

void convert_units(double value, char from_unit, char to_unit)
{
    double factor = 1.0;
    switch (from_unit)
    {
        case 'm':
            switch (to_unit)
            {
                case 'kg':
                    factor = 1000.0;
                    break;
                case 'g':
                    factor = 1000.0 / 1000.0;
                    break;
                case 't':
                    factor = 1000.0 * 1000.0;
                    break;
            }
            break;
        case 'kg':
            switch (to_unit)
            {
                case 'm':
                    factor = 1000.0;
                    break;
                case 'g':
                    factor = 1000.0 / 1000.0;
                    break;
                case 't':
                    factor = 1000.0 * 1000.0;
                    break;
            }
            break;
        case 'g':
            switch (to_unit)
            {
                case 'm':
                    factor = 1000.0 / 1000.0;
                    break;
                case 'kg':
                    factor = 1000.0;
                    break;
                case 't':
                    factor = 1000.0 * 1000.0;
                    break;
            }
            break;
        case 't':
            switch (to_unit)
            {
                case 'm':
                    factor = 1000.0 * 1000.0;
                    break;
                case 'kg':
                    factor = 1000.0 / 1000.0;
                    break;
                case 'g':
                    factor = 1000.0 / 1000.0;
                    break;
            }
            break;
    }

    value *= factor;

    switch (to_unit)
    {
        case 'm':
            printf("%f meters\n", value);
            break;
        case 'kg':
            printf("%f kilograms\n", value);
            break;
        case 'g':
            printf("%f grams\n", value);
            break;
        case 't':
            printf("%f tons\n", value);
            break;
    }
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

    convert_units(value, from_unit, to_unit);

    return 0;
}