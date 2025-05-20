//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>

void main()
{
    float f_num, f_result;
    char unit_from, unit_to;

    printf("Enter a number: ");
    scanf("%f", &f_num);

    printf("Enter the unit you want to convert from: ");
    scanf(" %c", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf(" %c", &unit_to);

    switch (unit_from)
    {
        case 'm':
            switch (unit_to)
            {
                case 'kg':
                    f_result = f_num * 1000;
                    break;
                case 'g':
                    f_result = f_num * 1000000;
                    break;
                case 't':
                    f_result = f_num * 1000000000;
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'm':
                    f_result = f_num * 0.001;
                    break;
                case 'g':
                    f_result = f_num * 1000;
                    break;
                case 't':
                    f_result = f_num * 1000000;
                    break;
            }
            break;
        case 'g':
            switch (unit_to)
            {
                case 'm':
                    f_result = f_num * 0.001;
                    break;
                case 'kg':
                    f_result = f_num * 0.001;
                    break;
                case 't':
                    f_result = f_num * 1000000;
                    break;
            }
            break;
        case 't':
            switch (unit_to)
            {
                case 'm':
                    f_result = f_num * 0.001;
                    break;
                case 'kg':
                    f_result = f_num * 0.001;
                    break;
                case 'g':
                    f_result = f_num * 0.001;
                    break;
            }
            break;
    }

    printf("The result is: %.2f %s", f_result, unit_to);

    return;
}