//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>
#include <math.h>

#define PI 3.1415926535

int main()
{
    float number;
    char unit;
    float conversion_factor;

    printf("Enter a number and a unit: ");
    scanf("%f %c", &number, &unit);

    switch (unit)
    {
        case 'm':
            conversion_factor = 1;
            break;
        case 'kg':
            conversion_factor = 1000;
            break;
        case 'g':
            conversion_factor = 1000000;
            break;
        case 'l':
            conversion_factor = 1000;
            break;
        case 't':
            conversion_factor = 3600;
            break;
        default:
            printf("Invalid unit.\n");
            return 1;
    }

    float converted_number = number * conversion_factor;

    switch (unit)
    {
        case 'm':
            printf("Converted number: %.2f meters.\n", converted_number);
            break;
        case 'kg':
            printf("Converted number: %.2f kilograms.\n", converted_number);
            break;
        case 'g':
            printf("Converted number: %.2f grams.\n", converted_number);
            break;
        case 'l':
            printf("Converted number: %.2f liters.\n", converted_number);
            break;
        case 't':
            printf("Converted number: %.2f hours.\n", converted_number);
            break;
        default:
            printf("Invalid unit.\n");
            return 1;
    }

    return 0;
}