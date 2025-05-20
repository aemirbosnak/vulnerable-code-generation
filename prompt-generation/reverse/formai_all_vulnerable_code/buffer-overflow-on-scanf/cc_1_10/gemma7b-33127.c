//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num;
    char unit;
    float conversion_factor;
    char target_unit;

    printf("Enter the number: ");
    scanf("%f", &num);

    printf("Enter the unit: ");
    scanf(" %c", &unit);

    switch (unit)
    {
        case 'm':
            conversion_factor = 1;
            target_unit = 'km';
            break;
        case 'kg':
            conversion_factor = 1000;
            target_unit = 't';
            break;
        case 'l':
            conversion_factor = 1000;
            target_unit = 'L';
            break;
        default:
            printf("Invalid unit.\n");
            return 1;
    }

    printf("Enter the target unit: ");
    scanf(" %c", &target_unit);

    switch (target_unit)
    {
        case 'km':
            conversion_factor = 1000;
            break;
        case 't':
            conversion_factor = 1000000;
            break;
        case 'L':
            conversion_factor = 1000;
            break;
        default:
            printf("Invalid target unit.\n");
            return 1;
    }

    float converted_num = num * conversion_factor;

    printf("The converted number is: %.2f %s.\n", converted_num, target_unit);

    return 0;
}