//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void unit_converter(int unit_from, int unit_to, float value)
{
    switch (unit_from)
    {
        case 1: // Liters
            switch (unit_to)
            {
                case 2: // Cubic meters
                    value *= 1000;
                    break;
                case 3: // Cubic decimeters
                    value *= 1000;
                    break;
                case 4: // Cubic centimeters
                    value *= 1000000;
                    break;
            }
            break;
        case 2: // Cubic meters
            switch (unit_to)
            {
                case 1: // Liters
                    value *= 0.001;
                    break;
                case 3: // Cubic decimeters
                    value *= 1000;
                    break;
                case 4: // Cubic centimeters
                    value *= 1000000;
                    break;
            }
            break;
        case 3: // Cubic decimeters
            switch (unit_to)
            {
                case 1: // Liters
                    value *= 0.001;
                    break;
                case 2: // Cubic meters
                    value *= 1000;
                    break;
                case 4: // Cubic centimeters
                    value *= 1000000;
                    break;
            }
            break;
        case 4: // Cubic centimeters
            switch (unit_to)
            {
                case 1: // Liters
                    value *= 0.000001;
                    break;
                case 2: // Cubic meters
                    value *= 0.000001;
                    break;
                case 3: // Cubic decimeters
                    value *= 0.001;
                    break;
            }
            break;
    }

    printf("The converted value is: %.2f", value);
}

int main()
{
    int unit_from, unit_to;
    float value;

    printf("Enter the unit you want to convert from: ");
    scanf("%d", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%d", &unit_to);

    printf("Enter the value: ");
    scanf("%f", &value);

    unit_converter(unit_from, unit_to, value);

    return 0;
}