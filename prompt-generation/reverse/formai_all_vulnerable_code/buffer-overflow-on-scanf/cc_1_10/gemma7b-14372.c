//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>
#include <math.h>

void main()
{
    float f_amount;
    int i_units_from, i_units_to;

    printf("Enter the amount: ");
    scanf("%f", &f_amount);

    printf("Enter the units you are converting from: ");
    scanf("%d", &i_units_from);

    printf("Enter the units you are converting to: ");
    scanf("%d", &i_units_to);

    switch (i_units_from)
    {
        case 1:
            switch (i_units_to)
            {
                case 2:
                    printf("The converted amount is: %.2f liters.", f_amount * 1000);
                    break;
                case 3:
                    printf("The converted amount is: %.2f gallons.", f_amount * 3.785);
                    break;
                default:
                    printf("Invalid units conversion.");
                    break;
            }
            break;
        case 2:
            switch (i_units_to)
            {
                case 1:
                    printf("The converted amount is: %.2f milliliters.", f_amount * 1000);
                    break;
                case 3:
                    printf("The converted amount is: %.2f gallons.", f_amount * 3.785);
                    break;
                default:
                    printf("Invalid units conversion.");
                    break;
            }
            break;
        case 3:
            switch (i_units_to)
            {
                case 1:
                    printf("The converted amount is: %.2f milliliters.", f_amount * 1000);
                    break;
                case 2:
                    printf("The converted amount is: %.2f liters.", f_amount * 1000);
                    break;
                default:
                    printf("Invalid units conversion.");
                    break;
            }
            break;
        default:
            printf("Invalid units conversion.");
            break;
    }

    return;
}