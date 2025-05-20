//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float f_from, f_to;
    char unit_from, unit_to;

    printf("Enter the conversion factor: ");
    scanf("%f", &f_from);

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
                    f_to = f_from * 1000;
                    break;
                case 'g':
                    f_to = f_from * 1000000;
                    break;
                case 't':
                    f_to = f_from * 1000000000;
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'm':
                    f_to = f_from / 1000;
                    break;
                case 'g':
                    f_to = f_from * 1000;
                    break;
                case 't':
                    f_to = f_from * 1000000;
                    break;
            }
            break;
        case 'g':
            switch (unit_to)
            {
                case 'm':
                    f_to = f_from / 1000000;
                    break;
                case 'kg':
                    f_to = f_from / 1000;
                    break;
                case 't':
                    f_to = f_from * 1000000;
                    break;
            }
            break;
        case 't':
            switch (unit_to)
            {
                case 'm':
                    f_to = f_from / 1000000000;
                    break;
                case 'kg':
                    f_to = f_from / 1000000;
                    break;
                case 'g':
                    f_to = f_from / 1000000;
                    break;
            }
            break;
    }

    printf("The converted factor is: %.2f %s\n", f_to, unit_to);

    return 0;
}