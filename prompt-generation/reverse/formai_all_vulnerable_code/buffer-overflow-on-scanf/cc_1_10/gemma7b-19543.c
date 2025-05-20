//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void unit_converter(float value, int from_unit, int to_unit)
{
    switch (from_unit)
    {
        case 1:
            switch (to_unit)
            {
                case 2:
                    value *= 2.54;
                    break;
                case 3:
                    value *= 1.613;
                    break;
                case 4:
                    value *= 0.833;
                    break;
            }
            break;
        case 2:
            switch (to_unit)
            {
                case 1:
                    value *= 0.45359;
                    break;
                case 3:
                    value *= 1.613;
                    break;
                case 4:
                    value *= 0.833;
                    break;
            }
            break;
        case 3:
            switch (to_unit)
            {
                case 1:
                    value *= 0.625;
                    break;
                case 2:
                    value *= 0.625;
                    break;
                case 4:
                    value *= 0.833;
                    break;
            }
            break;
        case 4:
            switch (to_unit)
            {
                case 1:
                    value *= 1.166;
                    break;
                case 2:
                    value *= 1.166;
                    break;
                case 3:
                    value *= 1.166;
                    break;
            }
            break;
    }

    printf("The converted value is: %.2f", value);
}

int main()
{
    float value;
    int from_unit, to_unit;

    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the from unit (1, 2, 3, 4): ");
    scanf("%d", &from_unit);

    printf("Enter the to unit (1, 2, 3, 4): ");
    scanf("%d", &to_unit);

    unit_converter(value, from_unit, to_unit);

    return 0;
}