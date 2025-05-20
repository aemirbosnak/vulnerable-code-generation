//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void UnitConverter(void)
{
    float number;
    char unit_from, unit_to;

    printf("Enter the number: ");
    scanf("%f", &number);

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
                    number *= 1000;
                    break;
                case 'g':
                    number *= 1000000;
                    break;
                case 't':
                    number *= 1000000000;
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'm':
                    number /= 1000;
                    break;
                case 'g':
                    number /= 1000000;
                    break;
                case 't':
                    number /= 1000000000;
                    break;
            }
            break;
        case 'g':
            switch (unit_to)
            {
                case 'm':
                    number /= 1000000;
                    break;
                case 'kg':
                    number /= 1000000;
                    break;
                case 't':
                    number /= 1000000000;
                    break;
            }
            break;
        case 't':
            switch (unit_to)
            {
                case 'm':
                    number /= 1000000000;
                    break;
                case 'kg':
                    number /= 1000000000;
                    break;
                case 'g':
                    number /= 1000000000;
                    break;
            }
            break;
    }

    printf("The converted number is: %.2f %s", number, unit_to);
}

int main()
{
    UnitConverter();

    return 0;
}