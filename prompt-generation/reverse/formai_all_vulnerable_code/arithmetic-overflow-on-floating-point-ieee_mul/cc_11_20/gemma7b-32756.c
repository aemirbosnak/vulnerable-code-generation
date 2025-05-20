//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num;
    int unit_from, unit_to;

    printf("Enter the number: ");
    scanf("%f", &num);

    printf("Enter the unit you want to convert from: ");
    scanf("%d", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%d", &unit_to);

    switch (unit_from)
    {
        case 1:
            switch (unit_to)
            {
                case 2:
                    printf("The converted number is: %.2f", num * 2);
                    break;
                case 3:
                    printf("The converted number is: %.2f", num * 3);
                    break;
                case 4:
                    printf("The converted number is: %.2f", num * 4);
                    break;
                default:
                    printf("Invalid unit conversion");
            }
            break;
        case 2:
            switch (unit_to)
            {
                case 1:
                    printf("The converted number is: %.2f", num / 2);
                    break;
                case 3:
                    printf("The converted number is: %.2f", num * 1.5);
                    break;
                case 4:
                    printf("The converted number is: %.2f", num * 2);
                    break;
                default:
                    printf("Invalid unit conversion");
            }
            break;
        case 3:
            switch (unit_to)
            {
                case 1:
                    printf("The converted number is: %.2f", num / 3);
                    break;
                case 2:
                    printf("The converted number is: %.2f", num * 2 / 3);
                    break;
                case 4:
                    printf("The converted number is: %.2f", num * 4 / 3);
                    break;
                default:
                    printf("Invalid unit conversion");
            }
            break;
        case 4:
            switch (unit_to)
            {
                case 1:
                    printf("The converted number is: %.2f", num / 4);
                    break;
                case 2:
                    printf("The converted number is: %.2f", num * 2 / 4);
                    break;
                case 3:
                    printf("The converted number is: %.2f", num * 3 / 4);
                    break;
                default:
                    printf("Invalid unit conversion");
            }
            break;
        default:
            printf("Invalid unit conversion");
    }

    return 0;
}