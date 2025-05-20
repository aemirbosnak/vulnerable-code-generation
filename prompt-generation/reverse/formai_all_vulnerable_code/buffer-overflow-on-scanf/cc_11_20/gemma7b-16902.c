//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <math.h>

int main()
{
    float num, factor;
    char unit, target_unit;

    printf("Enter the number: ");
    scanf("%f", &num);

    printf("Enter the current unit: ");
    scanf(" %c", &unit);

    printf("Enter the target unit: ");
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
        case 'ml':
            factor = 1000;
            break;
        default:
            printf("Invalid unit.\n");
            return 1;
    }

    switch (target_unit)
    {
        case 'm':
            factor = 1;
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
        case 'ml':
            factor = 1000;
            break;
        default:
            printf("Invalid target unit.\n");
            return 1;
    }

    num *= factor;
    num /= factor;

    printf("The converted number is: %.2f %s.\n", num, target_unit);

    return 0;
}