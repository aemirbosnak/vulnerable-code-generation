//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>
#include <math.h>

void UnitConverter(void)
{
    float value;
    char from_unit, to_unit;

    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the source unit (e.g. kg, g, lb): ");
    scanf(" %c", &from_unit);

    printf("Enter the target unit (e.g. kg, g, lb): ");
    scanf(" %c", &to_unit);

    switch (from_unit)
    {
        case 'kg':
            switch (to_unit)
            {
                case 'g':
                    printf("The converted value is: %.2f g", value * 1000);
                    break;
                case 'lb':
                    printf("The converted value is: %.2f lb", value * 2.20462);
                    break;
            }
            break;
        case 'g':
            switch (to_unit)
            {
                case 'kg':
                    printf("The converted value is: %.2f kg", value / 1000);
                    break;
                case 'lb':
                    printf("The converted value is: %.2f lb", value * 0.0022046);
                    break;
            }
            break;
        case 'lb':
            switch (to_unit)
            {
                case 'kg':
                    printf("The converted value is: %.2f kg", value * 0.453592);
                    break;
                case 'g':
                    printf("The converted value is: %.2f g", value * 453.592);
                    break;
            }
            break;
    }
}

int main()
{
    UnitConverter();

    return 0;
}