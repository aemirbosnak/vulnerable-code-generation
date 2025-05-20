//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    double value;
    int from_unit, to_unit;

    // Get the value, from unit, and to unit
    printf("Enter the value: ");
    scanf("%lf", &value);
    printf("Enter the from unit (e.g. kg, g, lb): ");
    scanf("%d", &from_unit);
    printf("Enter the to unit (e.g. kg, g, lb): ");
    scanf("%d", &to_unit);

    // Convert the value
    double conversion_factor = 1;
    switch (from_unit)
    {
        case 1: // kg
            switch (to_unit)
            {
                case 1: // kg
                    conversion_factor = 1;
                    break;
                case 2: // g
                    conversion_factor = 1000;
                    break;
                case 3: // lb
                    conversion_factor = 2.20462;
                    break;
            }
            break;
        case 2: // g
            switch (to_unit)
            {
                case 1: // kg
                    conversion_factor = 0.001;
                    break;
                case 2: // g
                    conversion_factor = 1;
                    break;
                case 3: // lb
                    conversion_factor = 2.20462 / 1000;
                    break;
            }
            break;
        case 3: // lb
            switch (to_unit)
            {
                case 1: // kg
                    conversion_factor = 0.453592;
                    break;
                case 2: // g
                    conversion_factor = 1000 / 2.20462;
                    break;
                case 3: // lb
                    conversion_factor = 1;
                    break;
            }
            break;
    }

    // Convert the value
    double converted_value = value * conversion_factor;

    // Print the converted value
    printf("The converted value is: %.2lf %s", converted_value, to_unit);

    return 0;
}