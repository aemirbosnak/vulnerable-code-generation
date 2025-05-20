//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: inquisitive
#include <stdio.h>
#include <math.h>

int main()
{
    int units_from, units_to;
    float value;

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the units you want to convert from:");
    scanf("%d", &units_from);

    printf("Please enter the units you want to convert to:");
    scanf("%d", &units_to);

    printf("Please enter the value you want to convert:");
    scanf("%f", &value);

    switch (units_from)
    {
        case 1:
            switch (units_to)
            {
                case 2:
                    printf("The converted value is: %.2f kilograms.", value * 1000);
                    break;
                case 3:
                    printf("The converted value is: %.2f grams.", value * 1000000);
                    break;
            }
            break;
        case 2:
            switch (units_to)
            {
                case 1:
                    printf("The converted value is: %.2f grams.", value * 1000);
                    break;
                case 3:
                    printf("The converted value is: %.2f milligrams.", value * 1000000);
                    break;
            }
            break;
        case 3:
            switch (units_to)
            {
                case 1:
                    printf("The converted value is: %.2f milligrams.", value * 1000);
                    break;
                case 2:
                    printf("The converted value is: %.2f kilograms.", value * 1000);
                    break;
            }
            break;
    }

    return 0;
}