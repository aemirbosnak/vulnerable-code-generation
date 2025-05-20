//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include <stdio.h>
#include <math.h>

#define PI 3.141592653

int main()
{
    double num, unit, converted_num;
    char unit_from, unit_to;

    printf("Enter a number: ");
    scanf("%lf", &num);

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
            converted_num = num * 2.2046;
            break;
        case 't':
            converted_num = num * 1000000;
            break;
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
            converted_num = converted_num / 2.2046;
            break;
        case 't':
            converted_num = converted_num / 1000000;
            break;
    }

    printf("The converted number is: %.2lf %s", converted_num, unit_to);

    return 0;
}