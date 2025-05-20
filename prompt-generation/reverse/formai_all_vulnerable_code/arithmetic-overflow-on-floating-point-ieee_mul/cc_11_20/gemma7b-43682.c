//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void unit_converter(float value, int from_unit, int to_unit)
{
    switch (from_unit)
    {
        case 0:
            switch (to_unit)
            {
                case 0:
                    printf("The same value: %.2f", value);
                    break;
                case 1:
                    printf("Converted value: %.2f kg", value * 1000);
                    break;
                case 2:
                    printf("Converted value: %.2f g", value * 1000000);
                    break;
                case 3:
                    printf("Converted value: %.2f mg", value * 1000000000);
                    break;
            }
            break;
        case 1:
            switch (to_unit)
            {
                case 0:
                    printf("Converted value: %.2f g", value / 1000);
                    break;
                case 1:
                    printf("The same value: %.2f", value);
                    break;
                case 2:
                    printf("Converted value: %.2f mg", value * 1000);
                    break;
                case 3:
                    printf("Converted value: %.2f ng", value * 1000000);
                    break;
            }
            break;
        case 2:
            switch (to_unit)
            {
                case 0:
                    printf("Converted value: %.2f mg", value / 1000000);
                    break;
                case 1:
                    printf("Converted value: %.2f g", value / 1000);
                    break;
                case 2:
                    printf("The same value: %.2f", value);
                    break;
                case 3:
                    printf("Converted value: %.2f ng", value * 1000);
                    break;
            }
            break;
        case 3:
            switch (to_unit)
            {
                case 0:
                    printf("Converted value: %.2f ng", value / 1000000000);
                    break;
                case 1:
                    printf("Converted value: %.2f mg", value / 1000000);
                    break;
                case 2:
                    printf("Converted value: %.2f g", value / 1000);
                    break;
                case 3:
                    printf("The same value: %.2f", value);
                    break;
            }
            break;
    }
}

int main()
{
    float value;
    int from_unit, to_unit;

    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the from unit (0-3): ");
    scanf("%d", &from_unit);

    printf("Enter the to unit (0-3): ");
    scanf("%d", &to_unit);

    unit_converter(value, from_unit, to_unit);

    return 0;
}