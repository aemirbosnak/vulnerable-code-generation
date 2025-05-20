//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>
#include <math.h>

int main()
{
    float f_num;
    int i_num;
    char unit_from, unit_to;

    printf("Enter a number: ");
    scanf("%f", &f_num);

    printf("Enter the unit you want to convert from (kg, g, lb, t): ");
    scanf(" %c", &unit_from);

    printf("Enter the unit you want to convert to (kg, g, lb, t): ");
    scanf(" %c", &unit_to);

    switch (unit_from)
    {
        case 'k':
            switch (unit_to)
            {
                case 'g':
                    i_num = (int) (f_num * 1000);
                    printf("%f kilograms is equal to %d grams.\n", f_num, i_num);
                    break;
                case 'lb':
                    i_num = (int) (f_num * 2.2046);
                    printf("%f kilograms is equal to %d pounds.\n", f_num, i_num);
                    break;
                case 't':
                    i_num = (int) (f_num * 1000000);
                    printf("%f kilograms is equal to %d tons.\n", f_num, i_num);
                    break;
            }
            break;
        case 'g':
            switch (unit_to)
            {
                case 'k':
                    i_num = (int) (f_num / 1000);
                    printf("%f grams is equal to %d kilograms.\n", f_num, i_num);
                    break;
                case 'lb':
                    i_num = (int) (f_num * 0.002204);
                    printf("%f grams is equal to %d pounds.\n", f_num, i_num);
                    break;
                case 't':
                    i_num = (int) (f_num * 0.000001) ;
                    printf("%f grams is equal to %d tons.\n", f_num, i_num);
                    break;
            }
            break;
        case 'lb':
            switch (unit_to)
            {
                case 'k':
                    i_num = (int) (f_num * 0.45359);
                    printf("%f pounds is equal to %d kilograms.\n", f_num, i_num);
                    break;
                case 'g':
                    i_num = (int) (f_num * 2.2046);
                    printf("%f pounds is equal to %d grams.\n", f_num, i_num);
                    break;
                case 't':
                    i_num = (int) (f_num * 0.001102);
                    printf("%f pounds is equal to %d tons.\n", f_num, i_num);
                    break;
            }
            break;
        case 't':
            switch (unit_to)
            {
                case 'k':
                    i_num = (int) (f_num * 0.001) ;
                    printf("%f tons is equal to %d kilograms.\n", f_num, i_num);
                    break;
                case 'g':
                    i_num = (int) (f_num * 1000000);
                    printf("%f tons is equal to %d grams.\n", f_num, i_num);
                    break;
                case 'lb':
                    i_num = (int) (f_num * 907.185);
                    printf("%f tons is equal to %d pounds.\n", f_num, i_num);
                    break;
            }
            break;
    }

    return 0;
}