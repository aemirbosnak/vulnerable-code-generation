//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: energetic
#include <stdio.h>
#include <math.h>

int main()
{
    float num;
    char unit_from, unit_to;

    printf("Enter the number: ");
    scanf("%f", &num);

    printf("Enter the unit you want to convert from: ");
    scanf(" %c", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf(" %c", &unit_to);

    switch (unit_from)
    {
        case 'm':
            switch (unit_to)
            {
                case 'km':
                    num *= 1000;
                    break;
                case 'hg':
                    num *= 1000000;
                    break;
                case 't':
                    num *= 1000000000;
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'm':
                    num /= 1000;
                    break;
                case 'hg':
                    num *= 1000;
                    break;
                case 't':
                    num *= 1000000;
                    break;
            }
            break;
        case 'g':
            switch (unit_to)
            {
                case 'm':
                    num /= 1000000;
                    break;
                case 'kg':
                    num /= 1000;
                    break;
                case 't':
                    num *= 1000000;
                    break;
            }
            break;
    }

    printf("The converted number is: %.2f %s", num, unit_to);

    return 0;
}