//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>
#include <math.h>

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
                    printf("%f is equal to %f liters.\n", num, num * 1000);
                    break;
                case 3:
                    printf("%f is equal to %f cubic meters.\n", num, num * 1000 * 1000);
                    break;
                default:
                    printf("Invalid unit conversion.\n");
                    break;
            }
            break;
        case 2:
            switch (unit_to)
            {
                case 1:
                    printf("%f is equal to %f milliliters.\n", num, num / 1000);
                    break;
                case 3:
                    printf("%f is equal to %f cubic meters.\n", num, num * 1000);
                    break;
                default:
                    printf("Invalid unit conversion.\n");
                    break;
            }
            break;
        case 3:
            switch (unit_to)
            {
                case 1:
                    printf("%f is equal to %f milliliters.\n", num, num / 1000 * 1000);
                    break;
                case 2:
                    printf("%f is equal to %f liters.\n", num, num / 1000);
                    break;
                default:
                    printf("Invalid unit conversion.\n");
                    break;
            }
            break;
        default:
            printf("Invalid unit conversion.\n");
            break;
    }

    return 0;
}