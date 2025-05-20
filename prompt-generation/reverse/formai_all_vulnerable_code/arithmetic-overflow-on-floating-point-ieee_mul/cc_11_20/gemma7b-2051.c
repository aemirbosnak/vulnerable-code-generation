//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    double dValue, fValue, tValue, kValue, eValue, hValue;
    int choice, i;
    char unit_from, unit_to;

    printf("Enter the value: ");
    scanf("%lf", &dValue);

    printf("Enter the unit of measurement (kg, t, e, h, f): ");
    scanf(" %c", &unit_from);

    printf("Enter the unit of measurement you want to convert to (kg, t, e, h, f): ");
    scanf(" %c", &unit_to);

    switch (unit_from)
    {
        case 'k':
            kValue = dValue;
            break;
        case 't':
            tValue = dValue * 1000;
            break;
        case 'e':
            eValue = dValue * 1000000;
            break;
        case 'h':
            hValue = dValue * 1000000 * 2;
            break;
        case 'f':
            fValue = dValue * 16;
            break;
        default:
            printf("Invalid unit of measurement.\n");
            return 1;
    }

    switch (unit_to)
    {
        case 'k':
            tValue = kValue / 1000;
            printf("%lf kg\n", tValue);
            break;
        case 't':
            kValue = tValue * 1000;
            printf("%lf kg\n", kValue);
            break;
        case 'e':
            kValue = eValue / 1000000;
            printf("%lf kg\n", kValue);
            break;
        case 'h':
            kValue = hValue / 1000000 * 2;
            printf("%lf kg\n", kValue);
            break;
        case 'f':
            kValue = fValue * 0.0625;
            printf("%lf kg\n", kValue);
            break;
        default:
            printf("Invalid unit of measurement.\n");
            return 1;
    }

    return 0;
}