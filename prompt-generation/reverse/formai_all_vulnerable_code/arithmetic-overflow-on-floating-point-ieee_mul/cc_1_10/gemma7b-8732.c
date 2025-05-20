//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>
#include <math.h>

int main()
{
    float num, original_num, converted_num, unit_factor;
    char unit, original_unit, converted_unit;

    printf("Enter the original number: ");
    scanf("%f", &original_num);

    printf("Enter the original unit (kg, g, L, ml): ");
    scanf("%c", &original_unit);

    printf("Enter the converted unit (kg, g, L, ml): ");
    scanf("%c", &converted_unit);

    switch (original_unit)
    {
        case 'k':
            unit_factor = 1000;
            break;
        case 'g':
            unit_factor = 1000;
            break;
        case 'L':
            unit_factor = 1000;
            break;
        case 'ml':
            unit_factor = 1000;
            break;
        default:
            printf("Invalid unit.\n");
            return 1;
    }

    switch (converted_unit)
    {
        case 'k':
            converted_num = original_num * unit_factor;
            break;
        case 'g':
            converted_num = original_num * unit_factor / 1000;
            break;
        case 'L':
            converted_num = original_num * unit_factor / 1000;
            break;
        case 'ml':
            converted_num = original_num * unit_factor / 1000;
            break;
        default:
            printf("Invalid unit.\n");
            return 1;
    }

    printf("The converted number is: %.2f %s\n", converted_num, converted_unit);

    return 0;
}