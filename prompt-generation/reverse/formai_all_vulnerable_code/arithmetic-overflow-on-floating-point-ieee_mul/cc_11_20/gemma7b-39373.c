//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float f_num, f_conv, f_res;
    char ch_unit, ch_conv;

    printf("Enter the number: ");
    scanf("%f", &f_num);

    printf("Enter the conversion unit: ");
    scanf("%c", &ch_unit);

    printf("Enter the conversion factor: ");
    scanf("%c", &ch_conv);

    switch (ch_unit)
    {
        case 'm':
            switch (ch_conv)
            {
                case 'km':
                    f_conv = 1000;
                    break;
                case 'hm':
                    f_conv = 100;
                    break;
                case 'dm':
                    f_conv = 10;
                    break;
                case 'cm':
                    f_conv = 1;
                    break;
            }
            break;
        case 'kg':
            switch (ch_conv)
            {
                case 't':
                    f_conv = 1000;
                    break;
                case 'q':
                    f_conv = 100;
                    break;
                case 'g':
                    f_conv = 1;
                    break;
            }
            break;
        case 'l':
            switch (ch_conv)
            {
                case 'L':
                    f_conv = 1;
                    break;
                case 'ml':
                    f_conv = 1000;
                    break;
                case 'cl':
                    f_conv = 1000000;
                    break;
            }
            break;
    }

    f_res = f_num * f_conv;

    printf("The result is: %.2f %s", f_res, ch_conv);

    return 0;
}