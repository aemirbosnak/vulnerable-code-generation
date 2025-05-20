//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num1, num2, unit1, unit2;
    float result;

    printf("Enter the number of units you want to convert:");
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
                case 1:
                    result = num1;
                    break;
                case 2:
                    result = num1 * 1.613;
                    break;
                case 3:
                    result = num1 * 2.204;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
            }
            break;
        case 2:
            switch (unit2)
            {
                case 1:
                    result = num1 * 0.613;
                    break;
                case 2:
                    result = num1;
                    break;
                case 3:
                    result = num1 * 1.161;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
            }
            break;
        case 3:
            switch (unit2)
            {
                case 1:
                    result = num1 * 0.2204;
                    break;
                case 2:
                    result = num1 * 0.833;
                    break;
                case 3:
                    result = num1;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
            }
            break;
        default:
            printf("Invalid unit conversion.\n");
    }

    printf("The result is: %.2f\n", result);

    return;
}