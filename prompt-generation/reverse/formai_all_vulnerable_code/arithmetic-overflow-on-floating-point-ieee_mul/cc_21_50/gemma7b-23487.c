//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: imaginative
#include <stdio.h>
#include <math.h>

void main()
{
    float num;
    int unit_from, unit_to;

    printf("Enter the number: ");
    scanf("%f", &num);

    printf("Enter the unit you want to convert from: ");
    scanf("%d", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%d", &unit_to);

    switch (unit_from)
    {
        case 1:
            switch (unit_to)
            {
                case 2:
                    num *= 2;
                    break;
                case 3:
                    num *= 3;
                    break;
                case 4:
                    num *= 4;
                    break;
                case 5:
                    num *= 5;
                    break;
                case 6:
                    num *= 6;
                    break;
                case 7:
                    num *= 7;
                    break;
                case 8:
                    num *= 8;
                    break;
                case 9:
                    num *= 9;
                    break;
                case 10:
                    num *= 10;
                    break;
            }
            break;
        case 2:
            switch (unit_to)
            {
                case 1:
                    num /= 2;
                    break;
                case 3:
                    num *= 1.5;
                    break;
                case 4:
                    num *= 2.5;
                    break;
                case 5:
                    num *= 3.5;
                    break;
                case 6:
                    num *= 4.5;
                    break;
                case 7:
                    num *= 5.5;
                    break;
                case 8:
                    num *= 6.5;
                    break;
                case 9:
                    num *= 7.5;
                    break;
                case 10:
                    num *= 8.5;
                    break;
            }
            break;
        case 3:
            switch (unit_to)
            {
                case 1:
                    num /= 3;
                    break;
                case 2:
                    num *= 2/3;
                    break;
                case 4:
                    num *= 4/3;
                    break;
                case 5:
                    num *= 5/3;
                    break;
                case 6:
                    num *= 6/3;
                    break;
                case 7:
                    num *= 7/3;
                    break;
                case 8:
                    num *= 8/3;
                    break;
                case 9:
                    num *= 9/3;
                    break;
                case 10:
                    num *= 10/3;
                    break;
            }
            break;
    }

    printf("The converted number is: %.2f", num);
    printf("\n");
}