//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535

int main()
{
    float num, unit, result;
    char operation;

    printf("Enter a number: ");
    scanf("%f", &num);

    printf("Enter the unit you want to convert from (kg, g, lb, km, mi): ");
    scanf("%s", &unit);

    printf("Enter the unit you want to convert to (kg, g, lb, km, mi): ");
    scanf("%s", &operation);

    switch (operation)
    {
        case 'k':
            result = num * 1000;
            unit = 'kg';
            break;
        case 'g':
            result = num * 1000;
            unit = 'g';
            break;
        case 'l':
            result = num * 0.45359;
            unit = 'lb';
            break;
        case 'km':
            result = num * 1.609;
            unit = 'mi';
            break;
        case 'mi':
            result = num * 1.609;
            unit = 'km';
            break;
        default:
            printf("Invalid operation.\n");
            return 1;
    }

    printf("The result is: %.2f %s.\n", result, unit);

    return 0;
}