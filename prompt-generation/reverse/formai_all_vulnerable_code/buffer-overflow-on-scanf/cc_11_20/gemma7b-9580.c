//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, unit1, unit2;

    printf("Enter the number you want to convert:");
    scanf("%d", &num1);

    printf("Enter the unit you want to convert from:");
    scanf("%d", &unit1);

    printf("Enter the unit you want to convert to:");
    scanf("%d", &unit2);

    switch (unit1)
    {
        case 1:
            switch (unit2)
            {
                case 2:
                    num2 = num1 * 2;
                    break;
                case 3:
                    num2 = num1 * 3;
                    break;
                case 4:
                    num2 = num1 * 4;
                    break;
                case 5:
                    num2 = num1 * 5;
                    break;
                default:
                    printf("Invalid unit conversion.");
                    break;
            }
            break;
        case 2:
            switch (unit2)
            {
                case 1:
                    num2 = num1 / 2;
                    break;
                case 3:
                    num2 = num1 * 1.5;
                    break;
                case 4:
                    num2 = num1 * 2.5;
                    break;
                case 5:
                    num2 = num1 * 3.5;
                    break;
                default:
                    printf("Invalid unit conversion.");
                    break;
            }
            break;
        case 3:
            switch (unit2)
            {
                case 1:
                    num2 = num1 / 3;
                    break;
                case 2:
                    num2 = num1 * 0.6666666;
                    break;
                case 4:
                    num2 = num1 * 1.3333333;
                    break;
                case 5:
                    num2 = num1 * 2.0;
                    break;
                default:
                    printf("Invalid unit conversion.");
                    break;
            }
            break;
        default:
            printf("Invalid unit conversion.");
            break;
    }

    printf("The converted number is: %d", num2);

    return 0;
}