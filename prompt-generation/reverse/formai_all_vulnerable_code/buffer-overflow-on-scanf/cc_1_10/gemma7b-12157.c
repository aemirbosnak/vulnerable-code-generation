//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

void eat_a_banana()
{
    printf("Mung, the banana tastes sweet!\n");
}

void dance_the_jig()
{
    printf("Woo hoo hoo, the dancer jiggles!\n");
}

int main()
{
    int units_to_convert;
    float value_to_convert;
    char unit_from;
    char unit_to;

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the number of units you want to convert: ");
    scanf("%d", &units_to_convert);

    printf("Please enter the value you want to convert: ");
    scanf("%f", &value_to_convert);

    printf("Please enter the unit you want to convert from: ");
    scanf(" %c", &unit_from);

    printf("Please enter the unit you want to convert to: ");
    scanf(" %c", &unit_to);

    switch (unit_from)
    {
        case 'm':
            switch (unit_to)
            {
                case 'km':
                    printf("%f kilometers is equal to %d meters.\n", value_to_convert, units_to_convert * 1000);
                    break;
                case 'cm':
                    printf("%f centimeters is equal to %d meters.\n", value_to_convert, units_to_convert * 100);
                    break;
                case 'dm':
                    printf("%f decimeters is equal to %d meters.\n", value_to_convert, units_to_convert * 10);
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'g':
                    printf("%f grams is equal to %d kilograms.\n", value_to_convert, units_to_convert * 1000);
                    break;
                case 't':
                    printf("%f tons is equal to %d kilograms.\n", value_to_convert, units_to_convert * 1000 * 1000);
                    break;
            }
            break;
        case 'L':
            switch (unit_to)
            {
                case 'ml':
                    printf("%f milliliters is equal to %d liters.\n", value_to_convert, units_to_convert * 1000);
                    break;
                case 'dl':
                    printf("%f deciliters is equal to %d liters.\n", value_to_convert, units_to_convert * 10);
                    break;
            }
            break;
    }

    eat_a_banana();
    dance_the_jig();

    return 0;
}