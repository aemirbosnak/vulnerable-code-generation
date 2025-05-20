//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main()
{
    double value;
    char unit_from, unit_to;

    printf("Enter the value: ");
    scanf("%lf", &value);

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
                    printf("%lf kg = %.2lf tons", value * 1000, value * 1000 / 2200);
                    break;
                case 'g':
                    printf("%lf g = %.2lf mg", value, value * 1000);
                    break;
                case 't':
                    printf("%lf t = %.2lf years", value * 365, value * 365 / 1000);
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'm':
                    printf("%lf kg = %.2lf m", value * 0.001, value * 0.001);
                    break;
                case 'g':
                    printf("%lf kg = %.2lf g", value * 1000, value * 1000);
                    break;
                case 't':
                    printf("%lf kg = %.2lf years", value * 365, value * 365 / 1000);
                    break;
            }
            break;
        case 'g':
            switch (unit_to)
            {
                case 'm':
                    printf("%lf g = %.2lf m", value * 0.001, value * 0.001);
                    break;
                case 'kg':
                    printf("%lf g = %.2lf kg", value * 1000, value * 1000);
                    break;
                case 't':
                    printf("%lf g = %.2lf years", value * 365, value * 365 / 1000);
                    break;
            }
            break;
        case 't':
            switch (unit_to)
            {
                case 'm':
                    printf("%lf t = %.2lf m", value * 365, value * 365 * 0.001);
                    break;
                case 'kg':
                    printf("%lf t = %.2lf kg", value * 365, value * 365 * 1000);
                    break;
                case 'g':
                    printf("%lf t = %.2lf g", value * 365, value * 365 * 1000);
                    break;
            }
            break;
    }

    return 0;
}