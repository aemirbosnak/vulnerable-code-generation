//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float f_num;
    int i_num;
    char unit_from, unit_to;

    printf("Enter the number: ");
    scanf("%f", &f_num);

    printf("Enter the unit you want to convert from: ");
    scanf(" %c", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf(" %c", &unit_to);

    switch (unit_from)
    {
        case 'g':
            switch (unit_to)
            {
                case 'kg':
                    i_num = (int)(f_num * 1000);
                    printf("%f grams is equal to %d kilograms.\n", f_num, i_num);
                    break;
                case 't':
                    i_num = (int)(f_num * 1000 * 1000);
                    printf("%f grams is equal to %d tons.\n", f_num, i_num);
                    break;
                default:
                    printf("Invalid unit conversion.\n");
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'g':
                    i_num = (int)(f_num * 1000);
                    printf("%f kilograms is equal to %d grams.\n", f_num, i_num);
                    break;
                case 't':
                    i_num = (int)(f_num * 1000 * 1000);
                    printf("%f kilograms is equal to %d tons.\n", f_num, i_num);
                    break;
                default:
                    printf("Invalid unit conversion.\n");
            }
            break;
        case 't':
            switch (unit_to)
            {
                case 'g':
                    i_num = (int)(f_num * 1000 * 1000);
                    printf("%f tons is equal to %d grams.\n", f_num, i_num);
                    break;
                case 'kg':
                    i_num = (int)(f_num * 1000 * 1000);
                    printf("%f tons is equal to %d kilograms.\n", f_num, i_num);
                    break;
                default:
                    printf("Invalid unit conversion.\n");
            }
            break;
        default:
            printf("Invalid unit conversion.\n");
    }

    return 0;
}