//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num;
    int unit_from, unit_to;
    float conversion_factor;

    printf("Enter the number: ");
    scanf("%f", &num);

    printf("Enter the unit you are converting from: ");
    scanf("%d", &unit_from);

    printf("Enter the unit you are converting to: ");
    scanf("%d", &unit_to);

    switch (unit_from)
    {
        case 1:
            conversion_factor = 1.613;
            break;
        case 2:
            conversion_factor = 0.625;
            break;
        case 3:
            conversion_factor = 0.0833;
            break;
        default:
            printf("Invalid unit from.\n");
            exit(1);
    }

    switch (unit_to)
    {
        case 1:
            conversion_factor = 1.613;
            break;
        case 2:
            conversion_factor = 0.625;
            break;
        case 3:
            conversion_factor = 0.0833;
            break;
        default:
            printf("Invalid unit to.\n");
            exit(1);
    }

    float converted_num = num * conversion_factor;

    printf("The converted number is: %.2f\n", converted_num);

    return 0;
}