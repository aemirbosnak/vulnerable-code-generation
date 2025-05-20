//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>
#include <math.h>

// Define the Unit Conversion Function
double unit_conversion(double value, int from_unit, int to_unit)
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
            conversion_factor = 2.2046;
            break;
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
            conversion_factor = 2.2046;
            break;
    }

    return value * conversion_factor;
}

int main()
{
    double value;
    int from_unit, to_unit;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the from unit (1, 2, 3, 4): ");
    scanf("%d", &from_unit);

    printf("Enter the to unit (1, 2, 3, 4): ");
    scanf("%d", &to_unit);

    double converted_value = unit_conversion(value, from_unit, to_unit);

    printf("The converted value is: %.2lf", converted_value);

    return 0;
}