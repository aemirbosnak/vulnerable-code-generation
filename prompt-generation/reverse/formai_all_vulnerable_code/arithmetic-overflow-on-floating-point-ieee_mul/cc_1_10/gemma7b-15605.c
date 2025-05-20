//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <math.h>

void unit_converter(double value, int from_unit, int to_unit)
{
    switch (from_unit)
    {
        case 1: // Meter
            switch (to_unit)
            {
                case 2: // Centimeter
                    value *= 100;
                    break;
                case 3: // Kilometer
                    value *= 1000;
                    break;
            }
            break;
        case 2: // Centimeter
            switch (to_unit)
            {
                case 1: // Meter
                    value /= 100;
                    break;
                case 3: // Kilometer
                    value *= 1000;
                    break;
            }
            break;
        case 3: // Kilometer
            switch (to_unit)
            {
                case 1: // Meter
                    value *= 1000;
                    break;
                case 2: // Centimeter
                    value /= 1000;
                    break;
            }
            break;
    }

    printf("The converted value is: %.2lf", value);
}

int main()
{
    double value;
    int from_unit, to_unit;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the from unit (1 - Meter, 2 - Centimeter, 3 - Kilometer): ");
    scanf("%d", &from_unit);

    printf("Enter the to unit (1 - Meter, 2 - Centimeter, 3 - Kilometer): ");
    scanf("%d", &to_unit);

    unit_converter(value, from_unit, to_unit);

    return 0;
}