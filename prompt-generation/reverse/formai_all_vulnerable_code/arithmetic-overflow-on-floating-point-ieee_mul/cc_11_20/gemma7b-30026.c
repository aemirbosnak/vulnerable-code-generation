//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int unit_from, unit_to, quantity;
    float conversion_factor;

    printf("Enter the unit you want to convert from: ");
    scanf("%d", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%d", &unit_to);

    printf("Enter the quantity you want to convert: ");
    scanf("%d", &quantity);

    switch (unit_from)
    {
        case 1:
            switch (unit_to)
            {
                case 2:
                    conversion_factor = 2.2;
                    break;
                case 3:
                    conversion_factor = 1.613;
                    break;
                case 4:
                    conversion_factor = 1.0;
                    break;
            }
            break;
        case 2:
            switch (unit_to)
            {
                case 1:
                    conversion_factor = 0.454;
                    break;
                case 3:
                    conversion_factor = 1.613;
                    break;
                case 4:
                    conversion_factor = 1.0;
                    break;
            }
            break;
        case 3:
            switch (unit_to)
            {
                case 1:
                    conversion_factor = 1.613;
                    break;
                case 2:
                    conversion_factor = 0.625;
                    break;
                case 4:
                    conversion_factor = 1.0;
                    break;
            }
            break;
        case 4:
            switch (unit_to)
            {
                case 1:
                    conversion_factor = 1.0;
                    break;
                case 2:
                    conversion_factor = 1.0;
                    break;
                case 3:
                    conversion_factor = 1.0;
                    break;
            }
            break;
    }

    float converted_quantity = quantity * conversion_factor;

    printf("The converted quantity is: %.2f", converted_quantity);

    return 0;
}