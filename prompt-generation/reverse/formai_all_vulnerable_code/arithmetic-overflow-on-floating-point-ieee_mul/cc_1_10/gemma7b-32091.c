//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: multivariable
#include <stdio.h>
#include <math.h>

void unit_converter(double value, int from_unit, int to_unit)
{
    double conversion_factor;

    switch (from_unit)
    {
        case 1:
            conversion_factor = 1;
            break;
        case 2:
            conversion_factor = 1000;
            break;
        case 3:
            conversion_factor = 16;
            break;
        case 4:
            conversion_factor = 2.208;
            break;
        default:
            printf("Invalid unit conversion.\n");
            return;
    }

    switch (to_unit)
    {
        case 1:
            conversion_factor = 1;
            break;
        case 2:
            conversion_factor = 1000;
            break;
        case 3:
            conversion_factor = 16;
            break;
        case 4:
            conversion_factor = 2.208;
            break;
        default:
            printf("Invalid unit conversion.\n");
            return;
    }

    double converted_value = value * conversion_factor;

    printf("Converted value: %.2lf %s to %.2lf %s is %.2lf.\n", value, from_unit, to_unit, converted_value);
}

int main()
{
    double value;
    int from_unit, to_unit;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the unit conversion from: ");
    scanf("%d", &from_unit);

    printf("Enter the unit conversion to: ");
    scanf("%d", &to_unit);

    unit_converter(value, from_unit, to_unit);

    return 0;
}