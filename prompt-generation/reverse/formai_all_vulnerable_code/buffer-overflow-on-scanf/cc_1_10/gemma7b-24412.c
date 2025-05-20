//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

void main()
{
    double number;
    char unit;
    double conversion_factor;
    char target_unit;

    printf("Enter a number: ");
    scanf("%lf", &number);

    printf("Enter the unit of the number (kg, g, lb, etc.): ");
    scanf(" %c", &unit);

    printf("Enter the target unit you want to convert to: ");
    scanf(" %c", &target_unit);

    switch (unit)
    {
        case 'k':
            conversion_factor = 1000;
            break;
        case 'g':
            conversion_factor = 1000;
            break;
        case 'lb':
            conversion_factor = 2.2046;
            break;
        case 'oz':
            conversion_factor = 0.035274;
            break;
        default:
            printf("Invalid unit.\n");
            return;
    }

    switch (target_unit)
    {
        case 'k':
            conversion_factor = 1000;
            break;
        case 'g':
            conversion_factor = 1000;
            break;
        case 'lb':
            conversion_factor = 2.2046;
            break;
        case 'oz':
            conversion_factor = 0.035274;
            break;
        default:
            printf("Invalid target unit.\n");
            return;
    }

    double converted_number = number * conversion_factor / conversion_factor;

    printf("The converted number is: %.2lf %s.\n", converted_number, target_unit);
}