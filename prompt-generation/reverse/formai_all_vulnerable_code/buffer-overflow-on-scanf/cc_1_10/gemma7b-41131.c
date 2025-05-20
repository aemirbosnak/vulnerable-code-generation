//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>
#include <math.h>

void main()
{
    float num, unit, converted_num;
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
                    converted_num = num * 1000;
                    break;
                case 'hg':
                    converted_num = num * 1000000;
                    break;
                case 'g':
                    converted_num = num * 1000000;
                    break;
                default:
                    printf("Invalid unit conversion.");
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'm':
                    converted_num = num * 0.001;
                    break;
                case 'hg':
                    converted_num = num * 1000;
                    break;
                case 'g':
                    converted_num = num * 1000000;
                    break;
                default:
                    printf("Invalid unit conversion.");
                    break;
            }
            break;
        default:
            printf("Invalid unit conversion.");
            break;
    }

    if (converted_num != 0)
    {
        printf("The converted number is: %.2f %s", converted_num, unit_to);
    }
}