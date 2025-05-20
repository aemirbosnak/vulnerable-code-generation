//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT 10

int main()
{
    int unit_from, unit_to, quantity;

    printf("Enter the unit you want to convert from: ");
    scanf("%d", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%d", &unit_to);

    printf("Enter the quantity you want to convert: ");
    scanf("%d", &quantity);

    if (unit_from == unit_to)
    {
        printf("Error: Cannot convert units to themselves.\n");
    }
    else if (quantity < 0)
    {
        printf("Error: Quantity cannot be negative.\n");
    }
    else
    {
        int conversion_factor = get_conversion_factor(unit_from, unit_to);

        int converted_quantity = quantity * conversion_factor;

        printf("The converted quantity is: %d %s.\n", converted_quantity, unit_to);
    }

    return 0;
}

int get_conversion_factor(int unit_from, int unit_to)
{
    switch (unit_from)
    {
        case 1:
            switch (unit_to)
            {
                case 2:
                    return 2;
                case 3:
                    return 3;
                case 4:
                    return 4;
                case 5:
                    return 5;
                default:
                    return -1;
            }
        case 2:
            switch (unit_to)
            {
                case 1:
                    return 0.5;
                case 3:
                    return 1.5;
                case 4:
                    return 2;
                case 5:
                    return 2.5;
                default:
                    return -1;
            }
        case 3:
            switch (unit_to)
            {
                case 1:
                    return 0.333;
                case 2:
                    return 0.666;
                case 4:
                    return 1.5;
                case 5:
                    return 2.0;
                default:
                    return -1;
            }
        case 4:
            switch (unit_to)
            {
                case 1:
                    return 0.25;
                case 2:
                    return 0.5;
                case 3:
                    return 0.666;
                case 5:
                    return 1.25;
                default:
                    return -1;
            }
        case 5:
            switch (unit_to)
            {
                case 1:
                    return 0.2;
                case 2:
                    return 0.4;
                case 3:
                    return 0.666;
                case 4:
                    return 0.8;
                default:
                    return -1;
            }
        default:
            return -1;
    }
}