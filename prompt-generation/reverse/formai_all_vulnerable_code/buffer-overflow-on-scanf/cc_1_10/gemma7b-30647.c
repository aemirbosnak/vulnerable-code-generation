//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>
#include <math.h>

int main()
{
    float num, factor, result;
    char unit, target_unit;

    printf("Enter the number: ");
    scanf("%f", &num);

    printf("Enter the unit: ");
    scanf(" %c", &unit);

    printf("Enter the target unit: ");
    scanf(" %c", &target_unit);

    switch (unit)
    {
        case 'm':
            factor = 1;
            break;
        case 'kg':
            factor = 1000;
            break;
        case 'g':
            factor = 1000000;
            break;
        default:
            printf("Invalid unit.\n");
            return 1;
    }

    switch (target_unit)
    {
        case 'm':
            result = num;
            break;
        case 'kg':
            result = num * factor;
            break;
        case 'g':
            result = num * factor * 1000;
            break;
        default:
            printf("Invalid target unit.\n");
            return 1;
    }

    printf("The result is: %.2f %s.\n", result, target_unit);

    return 0;
}