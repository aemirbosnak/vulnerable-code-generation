//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void convert_unit(int unit_from, int unit_to, float value)
{
    switch (unit_from)
    {
        case 0:
            switch (unit_to)
            {
                case 0:
                    printf("The value is the same.");
                    break;
                case 1:
                    printf("The value is doubled.");
                    break;
                case 2:
                    printf("The value is tripled.");
                    break;
                default:
                    printf("Invalid unit conversion.");
            }
            break;
        case 1:
            switch (unit_to)
            {
                case 0:
                    printf("The value is halved.");
                    break;
                case 1:
                    printf("The value is the same.");
                    break;
                case 2:
                    printf("The value is tripled.");
                    break;
                default:
                    printf("Invalid unit conversion.");
            }
            break;
        case 2:
            switch (unit_to)
            {
                case 0:
                    printf("The value is one third.");
                    break;
                case 1:
                    printf("The value is doubled.");
                    break;
                case 2:
                    printf("The value is the same.");
                    break;
                default:
                    printf("Invalid unit conversion.");
            }
            break;
        default:
            printf("Invalid unit conversion.");
    }
}

int main()
{
    int unit_from, unit_to;
    float value;

    printf("Enter the unit you want to convert from (0, 1, 2): ");
    scanf("%d", &unit_from);

    printf("Enter the unit you want to convert to (0, 1, 2): ");
    scanf("%d", &unit_to);

    printf("Enter the value: ");
    scanf("%f", &value);

    convert_unit(unit_from, unit_to, value);

    return 0;
}