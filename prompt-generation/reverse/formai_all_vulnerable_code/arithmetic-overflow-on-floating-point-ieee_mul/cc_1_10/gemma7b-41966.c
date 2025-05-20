//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main()
{
    double number;
    double conversion_factor;
    char unit_from;
    char unit_to;

    printf("Enter the number: ");
    scanf("%lf", &number);

    printf("Enter the unit you want to convert from: ");
    scanf(" %c", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf(" %c", &unit_to);

    switch (unit_from)
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
        default:
            printf("Invalid unit.\n");
            return 1;
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
            conversion_factor = 1000000;
            break;
        default:
            printf("Invalid unit.\n");
            return 1;
    }

    double converted_number = number * conversion_factor;

    printf("The converted number is: %.2lf %s.\n", converted_number, unit_to);

    return 0;
}