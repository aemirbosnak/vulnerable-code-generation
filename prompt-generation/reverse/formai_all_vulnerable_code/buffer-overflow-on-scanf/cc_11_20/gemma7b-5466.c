//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main()
{
    float num, unit, converted_num;
    char unit_from, unit_to;

    printf("Enter a number: ");
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
                    converted_num = num * 1000;
                    break;
                case 'cm':
                    converted_num = num * 100;
                    break;
                case 'dm':
                    converted_num = num * 10;
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'g':
                    converted_num = num * 1000;
                    break;
                case 't':
                    converted_num = num * 1000000;
                    break;
            }
            break;
        case 'L':
            switch (unit_to)
            {
                case 'ml':
                    converted_num = num * 1000;
                    break;
                case 'dl':
                    converted_num = num * 1000;
                    break;
            }
            break;
    }

    converted_num = round(converted_num);

    printf("The converted number is: %.2f %s\n", converted_num, unit_to);

    return 0;
}