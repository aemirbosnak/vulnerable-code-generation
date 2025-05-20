//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>

int main()
{
    int num, unit, target_unit;

    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Enter the current unit: ");
    scanf("%d", &unit);

    printf("Enter the target unit: ");
    scanf("%d", &target_unit);

    switch (unit)
    {
        case 1:
            switch (target_unit)
            {
                case 2:
                    printf("The converted number is: %.2lf", (double)num * 2);
                    break;
                case 3:
                    printf("The converted number is: %.2lf", (double)num * 3);
                    break;
                case 4:
                    printf("The converted number is: %.2lf", (double)num * 4);
                    break;
                default:
                    printf("Invalid target unit");
            }
            break;
        case 2:
            switch (target_unit)
            {
                case 1:
                    printf("The converted number is: %.2lf", (double)num / 2);
                    break;
                case 3:
                    printf("The converted number is: %.2lf", (double)num * 1.5);
                    break;
                case 4:
                    printf("The converted number is: %.2lf", (double)num * 2);
                    break;
                default:
                    printf("Invalid target unit");
            }
            break;
        case 3:
            switch (target_unit)
            {
                case 1:
                    printf("The converted number is: %.2lf", (double)num / 3);
                    break;
                case 2:
                    printf("The converted number is: %.2lf", (double)num * 0.666666);
                    break;
                case 4:
                    printf("The converted number is: %.2lf", (double)num * 1.333333);
                    break;
                default:
                    printf("Invalid target unit");
            }
            break;
        default:
            printf("Invalid unit");
    }

    return 0;
}