//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: inquisitive
#include <stdio.h>
#include <math.h>

int main()
{
    float f_num;
    int i_num;
    char unit_from, unit_to;
    float factor;

    printf("Enter the number: ");
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
                    factor = 1000;
                    break;
                case 'g':
                    factor = 1000000;
                    break;
                case 't':
                    factor = 1000000000;
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'm':
                    factor = 0.001;
                    break;
                case 'g':
                    factor = 1000;
                    break;
                case 't':
                    factor = 1000000;
                    break;
            }
            break;
        case 'g':
            switch (unit_to)
            {
                case 'm':
                    factor = 0.001;
                    break;
                case 'kg':
                    factor = 0.001;
                    break;
                case 't':
                    factor = 1000000;
                    break;
            }
            break;
        case 't':
            switch (unit_to)
            {
                case 'm':
                    factor = 0.001;
                    break;
                case 'kg':
                    factor = 0.001;
                    break;
                case 'g':
                    factor = 0.001;
                    break;
            }
            break;
    }

    i_num = (int)(f_num * factor);

    printf("The converted number is: %d", i_num);

    return 0;
}