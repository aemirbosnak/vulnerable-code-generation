//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: single-threaded
#include <stdio.h>
#include <math.h>

int main()
{
    float number;
    char unit_from, unit_to;

    printf("Enter the number: ");
    scanf("%f", &number);

    printf("Enter the unit of measurement from: ");
    scanf(" %c", &unit_from);

    printf("Enter the unit of measurement to: ");
    scanf(" %c", &unit_to);

    switch (unit_from)
    {
        case 'm':
            switch (unit_to)
            {
                case 'kg':
                    printf("The weight in kilograms is: %.2f\n", number * 1000);
                    break;
                case 'g':
                    printf("The weight in grams is: %.2f\n", number * 1000);
                    break;
                case 't':
                    printf("The weight in tons is: %.2f\n", number * 1000 * 1000);
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'm':
                    printf("The length in meters is: %.2f\n", number / 1000);
                    break;
                case 'g':
                    printf("The length in grams is: %.2f\n", number / 1000 * 1000);
                    break;
                case 't':
                    printf("The length in tons is: %.2f\n", number / 1000 * 1000 * 1000);
                    break;
            }
            break;
        case 't':
            switch (unit_to)
            {
                case 'm':
                    printf("The length in meters is: %.2f\n", number * 1000 * 1000);
                    break;
                case 'kg':
                    printf("The weight in kilograms is: %.2f\n", number * 1000 * 1000);
                    break;
                case 'g':
                    printf("The weight in grams is: %.2f\n", number * 1000 * 1000);
                    break;
            }
            break;
    }

    return 0;
}