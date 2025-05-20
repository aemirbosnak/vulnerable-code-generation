//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <math.h>

int main()
{
    float f_amount;
    int i_units, i_target_units;

    printf("Enter the amount: ");
    scanf("%f", &f_amount);

    printf("Enter the units: ");
    scanf("%d", &i_units);

    printf("Enter the target units: ");
    scanf("%d", &i_target_units);

    switch (i_units)
    {
        case 1:
            switch (i_target_units)
            {
                case 2:
                    f_amount *= 2;
                    break;
                case 3:
                    f_amount *= 3;
                    break;
                case 4:
                    f_amount *= 4;
                    break;
                case 5:
                    f_amount *= 5;
                    break;
                default:
                    printf("Invalid target units.\n");
            }
            break;
        case 2:
            switch (i_target_units)
            {
                case 1:
                    f_amount *= 0.5;
                    break;
                case 3:
                    f_amount *= 1.5;
                    break;
                case 4:
                    f_amount *= 2;
                    break;
                case 5:
                    f_amount *= 2.5;
                    break;
                default:
                    printf("Invalid target units.\n");
            }
            break;
        case 3:
            switch (i_target_units)
            {
                case 1:
                    f_amount *= 0.333333;
                    break;
                case 2:
                    f_amount *= 0.666666;
                    break;
                case 4:
                    f_amount *= 2;
                    break;
                case 5:
                    f_amount *= 3.333333;
                    break;
                default:
                    printf("Invalid target units.\n");
            }
            break;
        default:
            printf("Invalid units.\n");
    }

    printf("The converted amount is: %.2f %s\n", f_amount, i_target_units);

    return 0;
}