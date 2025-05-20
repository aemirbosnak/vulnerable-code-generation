//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: energetic
#include <stdio.h>
#include <math.h>

int main()
{
    float f_num;
    int i_num;
    char unit_from, unit_to;

    printf("Welcome to the Ultimate Unit Converter!\n");
    printf("Please enter a number: ");
    scanf("%f", &f_num);

    printf("Please enter the unit you are converting from: ");
    scanf(" %c", &unit_from);

    printf("Please enter the unit you are converting to: ");
    scanf(" %c", &unit_to);

    switch (unit_from)
    {
        case 'm':
            switch (unit_to)
            {
                case 'kg':
                    i_num = (int)(f_num * 1000);
                    printf("The converted weight is: %d kg\n", i_num);
                    break;
                case 'g':
                    i_num = (int)(f_num * 1000000);
                    printf("The converted weight is: %d g\n", i_num);
                    break;
                case 't':
                    i_num = (int)(f_num * 1000000);
                    printf("The converted weight is: %d tons\n", i_num);
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'm':
                    f_num = f_num / 1000;
                    printf("The converted weight is: %.2f m\n", f_num);
                    break;
                case 'g':
                    i_num = (int)(f_num * 1000);
                    printf("The converted weight is: %d g\n", i_num);
                    break;
                case 't':
                    i_num = (int)(f_num * 1000000);
                    printf("The converted weight is: %d tons\n", i_num);
                    break;
            }
            break;
        case 'g':
            switch (unit_to)
            {
                case 'm':
                    f_num = f_num / 1000000;
                    printf("The converted weight is: %.2f m\n", f_num);
                    break;
                case 'kg':
                    i_num = (int)(f_num / 1000);
                    printf("The converted weight is: %d kg\n", i_num);
                    break;
                case 't':
                    i_num = (int)(f_num * 1000000);
                    printf("The converted weight is: %d tons\n", i_num);
                    break;
            }
            break;
        case 't':
            switch (unit_to)
            {
                case 'm':
                    f_num = f_num / 1000000;
                    printf("The converted weight is: %.2f m\n", f_num);
                    break;
                case 'kg':
                    i_num = (int)(f_num * 1000);
                    printf("The converted weight is: %d kg\n", i_num);
                    break;
                case 'g':
                    i_num = (int)(f_num * 1000000);
                    printf("The converted weight is: %d g\n", i_num);
                    break;
            }
            break;
    }

    return 0;
}