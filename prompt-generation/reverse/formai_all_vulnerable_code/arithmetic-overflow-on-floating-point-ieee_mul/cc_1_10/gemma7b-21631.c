//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, from_unit, to_unit, quantity;
    float conversion_factor;

    printf("Welcome to the C Unit Converter!\n");
    printf("Please select the units you want to convert from:\n");
    printf("1. Metric\n");
    printf("2. Imperial\n");
    printf("Please select the units you want to convert to:\n");
    printf("1. Metric\n");
    printf("2. Imperial\n");

    scanf("%d", &choice);
    from_unit = choice;

    scanf("%d", &quantity);

    switch (from_unit)
    {
        case 1:
            switch (to_unit)
            {
                case 1:
                    conversion_factor = 1;
                    break;
                case 2:
                    conversion_factor = 2.208;
                    break;
                case 3:
                    conversion_factor = 1000;
                    break;
                default:
                    printf("Invalid conversion.\n");
                    break;
            }
            break;
        case 2:
            switch (to_unit)
            {
                case 1:
                    conversion_factor = 0.45359;
                    break;
                case 2:
                    conversion_factor = 1;
                    break;
                case 3:
                    conversion_factor = 1600;
                    break;
                default:
                    printf("Invalid conversion.\n");
                    break;
            }
            break;
        default:
            printf("Invalid selection.\n");
            break;
    }

    conversion_factor = conversion_factor * quantity;

    printf("The converted quantity is: %.2f %s.\n", conversion_factor, to_unit);

    return 0;
}