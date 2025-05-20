//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float number;
    char unit;
    char target_unit;

    printf("Enter the number: ");
    scanf("%f", &number);

    printf("Enter the unit: ");
    scanf(" %c", &unit);

    printf("Enter the target unit: ");
    scanf(" %c", &target_unit);

    switch (unit)
    {
        case 'm':
            switch (target_unit)
            {
                case 'km':
                    number *= 1000;
                    break;
                case 'hm':
                    number *= 100;
                    break;
                case 'dm':
                    number *= 10;
                    break;
                case 'cm':
                    number *= 100;
                    break;
                default:
                    break;
            }
            break;
        case 'kg':
            switch (target_unit)
            {
                case 't':
                    number *= 1000;
                    break;
                case 'q':
                    number *= 1000;
                    break;
                case 'g':
                    number *= 1000;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    printf("The converted number is: %.2f %s", number, target_unit);

    return 0;
}