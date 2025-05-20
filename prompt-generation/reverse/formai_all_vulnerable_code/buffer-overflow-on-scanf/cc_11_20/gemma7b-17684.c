//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, num1, num2, unit1, unit2;

    printf("Enter the number of conversion: ");
    scanf("%d", &num1);

    printf("Enter the units you want to convert from: ");
    scanf("%d", &unit1);

    printf("Enter the units you want to convert to: ");
    scanf("%d", &unit2);

    switch (unit1)
    {
        case 1:
            printf("Enter the value of the quantity: ");
            scanf("%d", &num2);
            switch (unit2)
            {
                case 1:
                    printf("The converted value is: %d", num2);
                    break;
                case 2:
                    printf("The converted value is: %.2lf", (double)num2 * 1.613);
                    break;
                case 3:
                    printf("The converted value is: %.2lf", (double)num2 * 2.204);
                    break;
                default:
                    printf("Invalid unit conversion");
                    break;
            }
            break;
        case 2:
            printf("Enter the value of the quantity: ");
            scanf("%lf", &num2);
            switch (unit2)
            {
                case 1:
                    printf("The converted value is: %.2lf", (double)num2 * 0.613);
                    break;
                case 2:
                    printf("The converted value is: %d", (int)(num2 * 1.613));
                    break;
                case 3:
                    printf("The converted value is: %.2lf", (double)num2 * 2.204);
                    break;
                default:
                    printf("Invalid unit conversion");
                    break;
            }
            break;
        case 3:
            printf("Enter the value of the quantity: ");
            scanf("%lf", &num2);
            switch (unit2)
            {
                case 1:
                    printf("The converted value is: %.2lf", (double)num2 * 0.453);
                    break;
                case 2:
                    printf("The converted value is: %.2lf", (double)num2 * 1.613);
                    break;
                case 3:
                    printf("The converted value is: %d", (int)(num2 * 2.204));
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