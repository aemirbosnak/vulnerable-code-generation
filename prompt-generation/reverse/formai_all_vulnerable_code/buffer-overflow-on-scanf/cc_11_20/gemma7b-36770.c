//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

int main()
{
    float num, converted_num;
    int unit, converted_unit;

    printf("Enter the number: ");
    scanf("%f", &num);

    printf("Enter the unit you want to convert from: ");
    scanf("%d", &unit);

    printf("Enter the unit you want to convert to: ");
    scanf("%d", &converted_unit);

    switch (unit)
    {
        case 1:
            switch (converted_unit)
            {
                case 2:
                    converted_num = num * 2;
                    break;
                case 3:
                    converted_num = num * 3;
                    break;
                case 4:
                    converted_num = num * 4;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
            }
            break;
        case 2:
            switch (converted_unit)
            {
                case 1:
                    converted_num = num / 2;
                    break;
                case 3:
                    converted_num = num * 1.5;
                    break;
                case 4:
                    converted_num = num * 2.5;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
            }
            break;
        case 3:
            switch (converted_unit)
            {
                case 1:
                    converted_num = num / 3;
                    break;
                case 2:
                    converted_num = num * 2/3;
                    break;
                case 4:
                    converted_num = num * 4/3;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
            }
            break;
        default:
            printf("Invalid unit conversion.\n");
    }

    printf("The converted number is: %.2f\n", converted_num);

    return 0;
}