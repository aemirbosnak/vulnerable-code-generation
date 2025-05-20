//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: surprised
#include <stdio.h>

void UnitConverter(int unit_from, int unit_to, float value)
{
    switch (unit_from)
    {
        case 1:
            switch (unit_to)
            {
                case 2:
                    value *= 10;
                    break;
                case 3:
                    value *= 100;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
                    break;
            }
            break;
        case 2:
            switch (unit_to)
            {
                case 1:
                    value /= 10;
                    break;
                case 3:
                    value *= 10;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
                    break;
            }
            break;
        case 3:
            switch (unit_to)
            {
                case 1:
                    value /= 100;
                    break;
                case 2:
                    value /= 10;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
                    break;
            }
            break;
        default:
            printf("Invalid unit conversion.\n");
            break;
    }

    printf("The converted value is: %.2f\n", value);
}

int main()
{
    float value;
    int unit_from, unit_to;

    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the unit conversion from: ");
    scanf("%d", &unit_from);

    printf("Enter the unit conversion to: ");
    scanf("%d", &unit_to);

    UnitConverter(unit_from, unit_to, value);

    return 0;
}