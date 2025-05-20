//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: complete
#include <stdio.h>

int main()
{
    int num, choice, unit_from, unit_to;
    float result;

    printf("Enter the number: ");
    scanf("%d", &num);

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
                    result = num * 2;
                    break;
                case 3:
                    result = num * 3;
                    break;
                case 4:
                    result = num * 4;
                    break;
                default:
                    printf("Invalid conversion");
            }
            break;
        case 2:
            switch (unit_to)
            {
                case 1:
                    result = num / 2;
                    break;
                case 3:
                    result = num * 1.5;
                    break;
                case 4:
                    result = num * 2.5;
                    break;
                default:
                    printf("Invalid conversion");
            }
            break;
        case 3:
            switch (unit_to)
            {
                case 1:
                    result = num / 3;
                    break;
                case 2:
                    result = num * 2/3;
                    break;
                case 4:
                    result = num * 4/3;
                    break;
                default:
                    printf("Invalid conversion");
            }
            break;
        case 4:
            switch (unit_to)
            {
                case 1:
                    result = num / 4;
                    break;
                case 2:
                    result = num * 2/4;
                    break;
                case 3:
                    result = num * 3/4;
                    break;
                default:
                    printf("Invalid conversion");
            }
            break;
        default:
            printf("Invalid conversion");
    }

    if (result != 0)
    {
        printf("The result is: %.2f", result);
    }

    return 0;
}