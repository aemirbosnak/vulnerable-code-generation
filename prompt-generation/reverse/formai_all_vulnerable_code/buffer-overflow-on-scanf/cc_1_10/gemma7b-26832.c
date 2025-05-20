//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>
#include <math.h>

int main()
{
    float num, unit_from, unit_to;
    char symbol_from, symbol_to;

    printf("Enter the number: ");
    scanf("%f", &num);

    printf("Enter the unit of measurement from: ");
    scanf(" %c", &symbol_from);

    printf("Enter the unit of measurement to: ");
    scanf(" %c", &symbol_to);

    switch (symbol_from)
    {
        case 'm':
            unit_from = 1000;
            break;
        case 'kg':
            unit_from = 1000;
            break;
        case 'g':
            unit_from = 1000;
            break;
        case 'L':
            unit_from = 1000;
            break;
        default:
            printf("Invalid unit of measurement.\n");
            return 1;
    }

    switch (symbol_to)
    {
        case 'm':
            unit_to = 1000;
            break;
        case 'kg':
            unit_to = 1000;
            break;
        case 'g':
            unit_to = 1000;
            break;
        case 'L':
            unit_to = 1000;
            break;
        default:
            printf("Invalid unit of measurement.\n");
            return 1;
    }

    float converted_num = num * unit_from / unit_to;

    printf("The converted number is: %.2f %s.\n", converted_num, symbol_to);

    return 0;
}