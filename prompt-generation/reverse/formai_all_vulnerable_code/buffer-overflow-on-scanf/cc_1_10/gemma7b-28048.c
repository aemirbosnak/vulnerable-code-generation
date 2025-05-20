//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT 10

int main()
{
    int from_unit, to_unit, value, factor, i;
    char unit_from[MAX_CONVERT], unit_to[MAX_CONVERT];

    printf("Enter the unit you want to convert from:");
    scanf("%s", unit_from);

    printf("Enter the unit you want to convert to:");
    scanf("%s", unit_to);

    printf("Enter the value you want to convert:");
    scanf("%d", &value);

    switch (from_unit)
    {
        case 'kg':
            factor = 1000;
            break;
        case 'g':
            factor = 1000;
            break;
        case 't':
            factor = 1000000;
            break;
        default:
            printf("Invalid unit of mass.\n");
            exit(1);
    }

    switch (to_unit)
    {
        case 'kg':
            factor = 1;
            break;
        case 'g':
            factor = 1000;
            break;
        case 't':
            factor = 1000000;
            break;
        default:
            printf("Invalid unit of mass.\n");
            exit(1);
    }

    i = value * factor;

    printf("The converted value is: %.2f %s\n", (float)i / factor, unit_to);

    return 0;
}