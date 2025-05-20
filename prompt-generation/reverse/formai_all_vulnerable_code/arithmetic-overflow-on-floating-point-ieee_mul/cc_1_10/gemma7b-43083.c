//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include <stdio.h>
#include <math.h>

void morph_unit_converter(void)
{
    double number;
    char unit_from, unit_to;

    printf("Enter a number: ");
    scanf("%lf", &number);

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
                    printf("%lf kg = %lf tons", number * 1000, number * 1000 / 2200);
                    break;
                case 'g':
                    printf("%lf g = %lf mg", number, number * 1000);
                    break;
                case 't':
                    printf("%lf t = %lf years", number * 365, number * 365 / 1000);
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'm':
                    printf("%lf kg = %lf meters", number * 1000, number * 1000 / 1000);
                    break;
                case 'g':
                    printf("%lf kg = %lf grams", number * 1000, number * 1000);
                    break;
                case 't':
                    printf("%lf kg = %lf years", number * 365, number * 365 / 1000);
                    break;
            }
            break;
        case 'g':
            switch (unit_to)
            {
                case 'm':
                    printf("%lf g = %lf meters", number * 1000, number * 1000 / 1000);
                    break;
                case 'kg':
                    printf("%lf g = %lf kilograms", number, number / 1000);
                    break;
                case 't':
                    printf("%lf g = %lf years", number * 365, number * 365 / 1000);
                    break;
            }
            break;
        case 't':
            switch (unit_to)
            {
                case 'm':
                    printf("%lf t = %lf meters", number * 365, number * 365 / 1000);
                    break;
                case 'kg':
                    printf("%lf t = %lf kilograms", number * 365, number * 365 / 1000);
                    break;
                case 'g':
                    printf("%lf t = %lf grams", number * 365, number * 365 / 1000);
                    break;
            }
            break;
    }
}

int main(void)
{
    morph_unit_converter();

    return 0;
}