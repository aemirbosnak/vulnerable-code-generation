//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>

void secure_unit_converter(void)
{
    int from_unit, to_unit, value;
    float conversion_factor;

    printf("Enter the unit you want to convert from: ");
    scanf("%d", &from_unit);

    printf("Enter the unit you want to convert to: ");
    scanf("%d", &to_unit);

    printf("Enter the value you want to convert: ");
    scanf("%d", &value);

    switch (from_unit)
    {
        case 1:
            switch (to_unit)
            {
                case 2:
                    conversion_factor = 2;
                    break;
                case 3:
                    conversion_factor = 3;
                    break;
                case 4:
                    conversion_factor = 4;
                    break;
                default:
                    printf("Invalid conversion.\n");
                    return;
            }
            break;
        case 2:
            switch (to_unit)
            {
                case 1:
                    conversion_factor = 0.5;
                    break;
                case 3:
                    conversion_factor = 1.5;
                    break;
                case 4:
                    conversion_factor = 2.0;
                    break;
                default:
                    printf("Invalid conversion.\n");
                    return;
            }
            break;
        case 3:
            switch (to_unit)
            {
                case 1:
                    conversion_factor = 0.3333;
                    break;
                case 2:
                    conversion_factor = 0.6666;
                    break;
                case 4:
                    conversion_factor = 1.0;
                    break;
                default:
                    printf("Invalid conversion.\n");
                    return;
            }
            break;
        case 4:
            switch (to_unit)
            {
                case 1:
                    conversion_factor = 0.25;
                    break;
                case 2:
                    conversion_factor = 0.5;
                    break;
                case 3:
                    conversion_factor = 1.0;
                    break;
                default:
                    printf("Invalid conversion.\n");
                    return;
            }
            break;
        default:
            printf("Invalid unit.\n");
            return;
    }

    conversion_factor = (float) value * conversion_factor;

    printf("The converted value is: %.2f\n", conversion_factor);
}

int main(void)
{
    secure_unit_converter();

    return 0;
}