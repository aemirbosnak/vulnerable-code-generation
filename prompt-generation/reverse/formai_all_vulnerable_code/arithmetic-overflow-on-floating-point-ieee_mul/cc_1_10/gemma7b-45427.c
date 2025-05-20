//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main()
{
    double input_num;
    char unit_from, unit_to;

    printf("Enter the number you want to convert: ");
    scanf("%lf", &input_num);

    printf("Enter the unit you want to convert from (e.g. km, kg, etc.): ");
    scanf(" %c", &unit_from);

    printf("Enter the unit you want to convert to (e.g. km, kg, etc.): ");
    scanf(" %c", &unit_to);

    switch (unit_from)
    {
        case 'k':
            switch (unit_to)
            {
                case 'm':
                    printf("%lf meters", input_num * 1000);
                    break;
                case 'h':
                    printf("%lf hours", input_num * 3600);
                    break;
                default:
                    printf("Invalid unit conversion");
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'g':
                    printf("%lf grams", input_num * 1000);
                    break;
                case 't':
                    printf("%lf tons", input_num * 1000000);
                    break;
                default:
                    printf("Invalid unit conversion");
                    break;
            }
            break;
        default:
            printf("Invalid unit conversion");
            break;
    }

    return 0;
}