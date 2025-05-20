//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num1, num2, unit1, unit2;
    float conversion_factor;

    printf("Enter the number you want to convert:");
    scanf("%d", &num1);

    printf("Enter the unit you want to convert from:");
    scanf("%d", &unit1);

    printf("Enter the unit you want to convert to:");
    scanf("%d", &unit2);

    switch (unit1)
    {
        case 1:
            conversion_factor = 1;
            break;
        case 2:
            conversion_factor = 2.2;
            break;
        case 3:
            conversion_factor = 2.5;
            break;
        case 4:
            conversion_factor = 4;
            break;
        default:
            printf("Invalid unit1");
            return;
    }

    switch (unit2)
    {
        case 1:
            conversion_factor = 1;
            break;
        case 2:
            conversion_factor = 0.454;
            break;
        case 3:
            conversion_factor = 0.833;
            break;
        case 4:
            conversion_factor = 0.666;
            break;
        default:
            printf("Invalid unit2");
            return;
    }

    num2 = (num1 * conversion_factor) * conversion_factor;

    printf("The converted number is:");
    printf("%d", num2);

    printf("Units:");
    printf("%d", unit2);

    return;
}