//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main()
{
    float num, unit_from, unit_to;
    char unit_symbol_from, unit_symbol_to;

    printf("Enter the number: ");
    scanf("%f", &num);

    printf("Enter the unit of measurement from: ");
    scanf("%c", &unit_symbol_from);

    printf("Enter the unit of measurement to: ");
    scanf("%c", &unit_symbol_to);

    switch (unit_symbol_from)
    {
        case 'kg':
            switch (unit_symbol_to)
            {
                case 'g':
                    unit_to = num * 1000;
                    break;
                case 't':
                    unit_to = num / 1000;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
                    break;
            }
            break;
        case 'g':
            switch (unit_symbol_to)
            {
                case 'kg':
                    unit_to = num / 1000;
                    break;
                case 't':
                    unit_to = num / 1000000;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
                    break;
            }
            break;
        case 't':
            switch (unit_symbol_to)
            {
                case 'kg':
                    unit_to = num * 1000;
                    break;
                case 'g':
                    unit_to = num * 1000000;
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

    if (unit_to != 0)
    {
        printf("The converted number is: %.2f %s.\n", unit_to, unit_symbol_to);
    }
    else
    {
        printf("Invalid unit conversion.\n");
    }

    return 0;
}