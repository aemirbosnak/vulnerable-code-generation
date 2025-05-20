//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int unit_from, unit_to, number;

    printf("Enter the unit you want to convert from: ");
    scanf("%d", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%d", &unit_to);

    printf("Enter the number you want to convert: ");
    scanf("%d", &number);

    switch (unit_from)
    {
        case 1:
            switch (unit_to)
            {
                case 2:
                    number *= 2;
                    break;
                case 3:
                    number *= 3;
                    break;
                case 4:
                    number *= 4;
                    break;
                case 5:
                    number *= 5;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
            }
            break;
        case 2:
            switch (unit_to)
            {
                case 1:
                    number /= 2;
                    break;
                case 3:
                    number *= 3 / 2;
                    break;
                case 4:
                    number *= 4 / 2;
                    break;
                case 5:
                    number *= 5 / 2;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
            }
            break;
        case 3:
            switch (unit_to)
            {
                case 1:
                    number /= 3;
                    break;
                case 2:
                    number *= 2 / 3;
                    break;
                case 4:
                    number *= 4 / 3;
                    break;
                case 5:
                    number *= 5 / 3;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
            }
            break;
        case 4:
            switch (unit_to)
            {
                case 1:
                    number /= 4;
                    break;
                case 2:
                    number *= 2 / 4;
                    break;
                case 3:
                    number *= 3 / 4;
                    break;
                case 5:
                    number *= 5 / 4;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
            }
            break;
        case 5:
            switch (unit_to)
            {
                case 1:
                    number /= 5;
                    break;
                case 2:
                    number *= 2 / 5;
                    break;
                case 3:
                    number *= 3 / 5;
                    break;
                case 4:
                    number *= 4 / 5;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
            }
            break;
        default:
            printf("Invalid unit conversion.\n");
    }

    printf("The converted number is: %d\n", number);

    return 0;
}