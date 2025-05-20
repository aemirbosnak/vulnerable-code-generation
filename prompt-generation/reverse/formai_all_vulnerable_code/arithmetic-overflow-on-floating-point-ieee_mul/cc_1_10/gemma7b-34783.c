//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>
#include <math.h>

void main()
{
    float num, unit, conversion_factor;
    char target_unit;

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the number you want to convert:");
    scanf("%f", &num);

    printf("Please enter the unit you want to convert from:");
    scanf(" %c", &target_unit);

    switch (target_unit)
    {
        case 'm':
            conversion_factor = 1;
            break;
        case 'kg':
            conversion_factor = 1000;
            break;
        case 'g':
            conversion_factor = 1000000;
            break;
        case 'L':
            conversion_factor = 1000;
            break;
        default:
            printf("Invalid unit.\n");
            return;
    }

    conversion_factor = conversion_factor;

    printf("Please enter the unit you want to convert to:");
    scanf(" %c", &target_unit);

    switch (target_unit)
    {
        case 'm':
            unit = num * conversion_factor;
            printf("The converted number is: %.2f meters.\n", unit);
            break;
        case 'kg':
            unit = num * conversion_factor / 1000;
            printf("The converted number is: %.2f kilograms.\n", unit);
            break;
        case 'g':
            unit = num * conversion_factor / 1000000;
            printf("The converted number is: %.2f grams.\n", unit);
            break;
        case 'L':
            unit = num * conversion_factor * 1000;
            printf("The converted number is: %.2f liters.\n", unit);
            break;
        default:
            printf("Invalid unit.\n");
            return;
    }

    return;
}