//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>
#include <math.h>

void main()
{
    float flt_num;
    int int_num;
    char unit_from, unit_to;

    printf("Enter the number: ");
    scanf("%f", &flt_num);

    printf("Enter the unit of measurement from: ");
    scanf(" %c", &unit_from);

    printf("Enter the unit of measurement to: ");
    scanf(" %c", &unit_to);

    switch (unit_from)
    {
        case 'm':
            switch (unit_to)
            {
                case 'km':
                    int_num = (int)(flt_num * 1000);
                    printf("%f meters is equal to %d kilometers.\n", flt_num, int_num);
                    break;
                case 'cm':
                    int_num = (int)(flt_num * 100);
                    printf("%f meters is equal to %d centimeters.\n", flt_num, int_num);
                    break;
                case 'dm':
                    int_num = (int)(flt_num * 10);
                    printf("%f meters is equal to %d decimeters.\n", flt_num, int_num);
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'g':
                    int_num = (int)(flt_num * 1000);
                    printf("%f kilograms is equal to %d grams.\n", flt_num, int_num);
                    break;
                case 't':
                    int_num = (int)(flt_num * 1000);
                    printf("%f kilograms is equal to %d tons.\n", flt_num, int_num);
                    break;
            }
            break;
        default:
            printf("Invalid unit of measurement.\n");
    }

    return;
}