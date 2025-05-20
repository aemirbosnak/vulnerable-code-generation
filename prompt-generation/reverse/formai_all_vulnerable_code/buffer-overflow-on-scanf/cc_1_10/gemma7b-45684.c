//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>
#include <math.h>

void convert_unit(double value, char from_unit, char to_unit)
{
    double conversion_factor;

    switch (from_unit)
    {
        case 'g':
            conversion_factor = 1000;
            break;
        case 'kg':
            conversion_factor = 1000;
            break;
        case 't':
            conversion_factor = 1000000;
            break;
        default:
            printf("Invalid unit conversion.\n");
            return;
    }

    switch (to_unit)
    {
        case 'g':
            conversion_factor = 1 / conversion_factor;
            break;
        case 'kg':
            conversion_factor = 1 / conversion_factor;
            break;
        case 't':
            conversion_factor = 1 / conversion_factor * 1000;
            break;
        default:
            printf("Invalid unit conversion.\n");
            return;
    }

    double converted_value = value * conversion_factor;

    printf("%f %s converted to %f %s is %f.\n", value, from_unit, to_unit, converted_value);
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

    convert_unit(value, from_unit, to_unit);

    return 0;
}