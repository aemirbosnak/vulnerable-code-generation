//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float num, factor, result;
    char unit, target_unit;

    printf("Prepare for a shock! Enter a number: ");
    scanf("%f", &num);

    printf("Pick a unit to convert from: ");
    scanf(" %c", &unit);

    printf("Choose the target unit you want to convert to: ");
    scanf(" %c", &target_unit);

    switch (unit)
    {
        case 'm':
            factor = 1000;
            break;
        case 'kg':
            factor = 1000;
            break;
        case 'g':
            factor = 1000;
            break;
        case 'L':
            factor = 1000;
            break;
        case 'km':
            factor = 1000;
            break;
        default:
            printf("Invalid unit. Try again.\n");
            return 1;
    }

    switch (target_unit)
    {
        case 'm':
            result = num * factor;
            break;
        case 'kg':
            result = num * factor;
            break;
        case 'g':
            result = num * factor;
            break;
        case 'L':
            result = num * factor;
            break;
        case 'km':
            result = num * factor;
            break;
        default:
            printf("Invalid target unit. Try again.\n");
            return 1;
    }

    printf("Get ready for the conversion! The result is: %.2f %s\n", result, target_unit);

    return 0;
}