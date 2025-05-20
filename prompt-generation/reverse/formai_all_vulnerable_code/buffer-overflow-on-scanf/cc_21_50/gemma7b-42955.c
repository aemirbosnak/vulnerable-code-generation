//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>

int main()
{
    float f_amount, f_converted_amount;
    int i_unit_from, i_unit_to;

    printf("Enter the amount: ");
    scanf("%f", &f_amount);

    printf("Enter the unit you are converting from (kg, g, l, ml): ");
    scanf("%d", &i_unit_from);

    printf("Enter the unit you are converting to (kg, g, l, ml): ");
    scanf("%d", &i_unit_to);

    switch (i_unit_from)
    {
        case 1: // kg
            switch (i_unit_to)
            {
                case 1: // kg
                    f_converted_amount = f_amount;
                    break;
                case 2: // g
                    f_converted_amount = f_amount * 1000;
                    break;
                case 3: // l
                    f_converted_amount = f_amount * 1000 * 1000;
                    break;
                case 4: // ml
                    f_converted_amount = f_amount * 1000 * 1000 * 1000;
                    break;
            }
            break;
        case 2: // g
            switch (i_unit_to)
            {
                case 1: // kg
                    f_converted_amount = f_amount / 1000;
                    break;
                case 2: // g
                    f_converted_amount = f_amount;
                    break;
                case 3: // l
                    f_converted_amount = f_amount / 1000 * 1000;
                    break;
                case 4: // ml
                    f_converted_amount = f_amount / 1000 * 1000 * 1000;
                    break;
            }
            break;
        case 3: // l
            switch (i_unit_to)
            {
                case 1: // kg
                    f_converted_amount = f_amount * 1000 * 1000;
                    break;
                case 2: // g
                    f_converted_amount = f_amount * 1000 * 1000 * 1000;
                    break;
                case 3: // l
                    f_converted_amount = f_amount;
                    break;
                case 4: // ml
                    f_converted_amount = f_amount * 1000 * 1000 * 1000;
                    break;
            }
            break;
        case 4: // ml
            switch (i_unit_to)
            {
                case 1: // kg
                    f_converted_amount = f_amount / 1000 * 1000 * 1000;
                    break;
                case 2: // g
                    f_converted_amount = f_amount / 1000 * 1000 * 1000;
                    break;
                case 3: // l
                    f_converted_amount = f_amount / 1000 * 1000;
                    break;
                case 4: // ml
                    f_converted_amount = f_amount;
                    break;
            }
            break;
    }

    printf("The converted amount is: %.2f", f_converted_amount);

    return 0;
}