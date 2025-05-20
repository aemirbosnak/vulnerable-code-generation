//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

void convert_units(float value, char from_unit, char to_unit);

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

void convert_units(float value, char from_unit, char to_unit)
{
    switch (from_unit)
    {
        case 'm':
            switch (to_unit)
            {
                case 'km':
                    value *= 1000;
                    break;
                case 'cm':
                    value *= 100;
                    break;
                case 'mm':
                    value *= 1000;
                    break;
            }
            break;
        case 'kg':
            switch (to_unit)
            {
                case 'g':
                    value *= 1000;
                    break;
                case 't':
                    value *= 1000;
                    break;
            }
            break;
        case 'L':
            switch (to_unit)
            {
                case 'ml':
                    value *= 1000;
                    break;
                case 'dl':
                    value *= 1000;
                    break;
            }
            break;
    }

    printf("The converted value is: %.2f %s", value, to_unit);
}