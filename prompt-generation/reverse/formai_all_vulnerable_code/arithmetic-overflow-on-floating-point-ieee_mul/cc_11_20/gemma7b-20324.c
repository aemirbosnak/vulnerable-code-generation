//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Alan Turing
#include <stdio.h>

int main()
{
    int num_units;
    float conversion_factor;
    char unit_from, unit_to;

    printf("Enter the number of units: ");
    scanf("%d", &num_units);

    printf("Enter the conversion factor: ");
    scanf("%f", &conversion_factor);

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
                    printf("The number of kilograms is: %.2f", num_units * conversion_factor);
                    break;
                case 'g':
                    printf("The number of grams is: %.2f", num_units * conversion_factor * 1000);
                    break;
                case 't':
                    printf("The number of tons is: %.2f", num_units * conversion_factor / 1000);
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'm':
                    printf("The number of meters is: %.2f", num_units * conversion_factor);
                    break;
                case 'g':
                    printf("The number of grams is: %.2f", num_units * conversion_factor * 1000);
                    break;
                case 't':
                    printf("The number of tons is: %.2f", num_units * conversion_factor / 1000);
                    break;
            }
            break;
        case 'g':
            switch (unit_to)
            {
                case 'm':
                    printf("The number of meters is: %.2f", num_units * conversion_factor / 1000);
                    break;
                case 'kg':
                    printf("The number of kilograms is: %.2f", num_units * conversion_factor);
                    break;
                case 't':
                    printf("The number of tons is: %.2f", num_units * conversion_factor / 1000);
                    break;
            }
            break;
        case 't':
            switch (unit_to)
            {
                case 'm':
                    printf("The number of meters is: %.2f", num_units * conversion_factor * 1000);
                    break;
                case 'kg':
                    printf("The number of kilograms is: %.2f", num_units * conversion_factor * 1000);
                    break;
                case 'g':
                    printf("The number of grams is: %.2f", num_units * conversion_factor * 1000);
                    break;
            }
            break;
    }

    return 0;
}