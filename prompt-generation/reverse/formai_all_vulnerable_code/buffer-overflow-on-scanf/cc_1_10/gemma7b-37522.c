//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int number;
    float conversion_factor;
    char unit_from, unit_to;

    printf("Enter the number: ");
    scanf("%d", &number);

    printf("Enter the unit you want to convert from: ");
    scanf(" %c", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf(" %c", &unit_to);

    switch (unit_from)
    {
        case 'm':
            conversion_factor = 1000;
            break;
        case 'kg':
            conversion_factor = 1000;
            break;
        case 'g':
            conversion_factor = 1000;
            break;
        case 'L':
            conversion_factor = 1000;
            break;
        default:
            printf("Invalid unit.\n");
            return;
    }

    switch (unit_to)
    {
        case 'm':
            conversion_factor = 1;
            break;
        case 'kg':
            conversion_factor = 1000;
            break;
        case 'g':
            conversion_factor = 1000;
            break;
        case 'L':
            conversion_factor = 1000;
            break;
        default:
            printf("Invalid unit.\n");
            return;
    }

    float converted_number = number * conversion_factor;

    printf("The converted number is: %.2f\n", converted_number);

    return;
}