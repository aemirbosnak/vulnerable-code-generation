//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: recursive
#include <stdio.h>
#include <math.h>

void convert_unit(double value, char from_unit, char to_unit)
{
    double conversion_factor;
    char unit_symbol[20];

    // Get the conversion factor
    switch (from_unit)
    {
        case 'kg':
            conversion_factor = 1000;
            break;
        case 'g':
            conversion_factor = 1000;
            break;
        case 't':
            conversion_factor = 1000000;
            break;
        default:
            printf("Error: Invalid unit conversion.");
            return;
    }

    // Convert the value
    double converted_value = value * conversion_factor;

    // Get the unit symbol
    switch (to_unit)
    {
        case 'kg':
            strcpy(unit_symbol, "kg");
            break;
        case 'g':
            strcpy(unit_symbol, "g");
            break;
        case 't':
            strcpy(unit_symbol, "t");
            break;
        default:
            printf("Error: Invalid unit conversion.");
            return;
    }

    // Print the converted value
    printf("%f %s", converted_value, unit_symbol);
}

int main()
{
    double value;
    char from_unit;
    char to_unit;

    // Get the value, from unit, and to unit
    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the from unit: ");
    scanf(" %c", &from_unit);

    printf("Enter the to unit: ");
    scanf(" %c", &to_unit);

    // Convert the unit
    convert_unit(value, from_unit, to_unit);

    return 0;
}