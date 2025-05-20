//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main()
{
    float num, unit, converted_num;
    char unit_from, unit_to;

    printf("Enter the number: ");
    scanf("%f", &num);

    printf("Enter the unit you want to convert from (kg, g, lb, t): ");
    scanf(" %c", &unit_from);

    printf("Enter the unit you want to convert to (kg, g, lb, t): ");
    scanf(" %c", &unit_to);

    switch (unit_from)
    {
        case 'k':
            converted_num = num * 1000;
            break;
        case 'g':
            converted_num = num * 1000;
            break;
        case 'lb':
            converted_num = num * 2.20462;
            break;
        case 't':
            converted_num = num * 1000000;
            break;
        default:
            printf("Invalid unit.\n");
            return 1;
    }

    switch (unit_to)
    {
        case 'k':
            converted_num = converted_num / 1000;
            break;
        case 'g':
            converted_num = converted_num / 1000;
            break;
        case 'lb':
            converted_num = converted_num * 0.453592;
            break;
        case 't':
            converted_num = converted_num / 1000000;
            break;
        default:
            printf("Invalid unit.\n");
            return 1;
    }

    printf("The converted number is: %.10f %s.\n", converted_num, unit_to);

    return 0;
}