//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: protected
#include <stdio.h>
#include <math.h>

int main()
{
    float number, unit_from, unit_to;
    char unit_from_symbol, unit_to_symbol;

    printf("Enter the number:");
    scanf("%f", &number);

    printf("Enter the unit of the number:");
    scanf("%c", &unit_from_symbol);

    printf("Enter the unit you want to convert to:");
    scanf("%c", &unit_to_symbol);

    switch (unit_from_symbol)
    {
        case 'g':
            switch (unit_to_symbol)
            {
                case 'kg':
                    unit_to = number * 1000;
                    break;
                case 'mg':
                    unit_to = number * 1000000;
                    break;
                case 'cg':
                    unit_to = number * 1000000000;
                    break;
            }
            break;
        case 'kg':
            switch (unit_to_symbol)
            {
                case 'g':
                    unit_to = number * 1000;
                    break;
                case 'mg':
                    unit_to = number * 1000000;
                    break;
                case 'cg':
                    unit_to = number * 1000000000;
                    break;
            }
            break;
        case 'mg':
            switch (unit_to_symbol)
            {
                case 'g':
                    unit_to = number * 1000;
                    break;
                case 'kg':
                    unit_to = number * 1000000;
                    break;
                case 'cg':
                    unit_to = number * 1000000000;
                    break;
            }
            break;
        case 'cg':
            switch (unit_to_symbol)
            {
                case 'g':
                    unit_to = number * 1000;
                    break;
                case 'kg':
                    unit_to = number * 1000000;
                    break;
                case 'mg':
                    unit_to = number * 1000000000;
                    break;
            }
            break;
    }

    printf("The converted number is: %.2f %s", unit_to, unit_to_symbol);

    return 0;
}