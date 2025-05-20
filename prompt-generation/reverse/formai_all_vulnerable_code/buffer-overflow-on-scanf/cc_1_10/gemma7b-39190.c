//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: multivariable
#include <stdio.h>
#include <math.h>

void unit_converter(float value, int from_unit, int to_unit)
{
    switch (from_unit)
    {
        case 1:
            switch (to_unit)
            {
                case 2:
                    printf("%f liters are equal to %f gallons.\n", value, value * 1.05669);
                    break;
                case 3:
                    printf("%f liters are equal to %f quarts.\n", value, value * 1.05669 * 4);
                    break;
            }
            break;
        case 2:
            switch (to_unit)
            {
                case 1:
                    printf("%f gallons are equal to %f liters.\n", value, value * 1.05669);
                    break;
                case 3:
                    printf("%f gallons are equal to %f quarts.\n", value, value * 1.05669 * 4);
                    break;
            }
            break;
        case 3:
            switch (to_unit)
            {
                case 1:
                    printf("%f quarts are equal to %f liters.\n", value, value * 1.05669 / 4);
                    break;
                case 2:
                    printf("%f quarts are equal to %f gallons.\n", value, value * 1.05669 / 4 * 1.05669);
                    break;
            }
            break;
    }
}

int main()
{
    float value;
    int from_unit, to_unit;

    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the from unit (1 - liter, 2 - gallon, 3 - quart): ");
    scanf("%d", &from_unit);

    printf("Enter the to unit (1 - liter, 2 - gallon, 3 - quart): ");
    scanf("%d", &to_unit);

    unit_converter(value, from_unit, to_unit);

    return 0;
}