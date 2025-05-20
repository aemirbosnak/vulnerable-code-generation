//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void UnitConverter(int fromUnit, int toUnit, float value)
{
    switch (fromUnit)
    {
        case 0:
            switch (toUnit)
            {
                case 0:
                    printf("The value is the same in both units.\n");
                    break;
                case 1:
                    printf("The value is %f times the value in liters.\n", value * 1000);
                    break;
                case 2:
                    printf("The value is %f times the value in quarts.\n", value * 4);
                    break;
            }
            break;
        case 1:
            switch (toUnit)
            {
                case 0:
                    printf("The value is %f times the value in liters.\n", value / 1000);
                    break;
                case 1:
                    printf("The value is the same in both units.\n");
                    break;
                case 2:
                    printf("The value is %f times the value in quarts.\n", value * 4);
                    break;
            }
            break;
        case 2:
            switch (toUnit)
            {
                case 0:
                    printf("The value is %f times the value in liters.\n", value / 4);
                    break;
                case 1:
                    printf("The value is %f times the value in liters.\n", value * 0.25);
                    break;
                case 2:
                    printf("The value is the same in both units.\n");
                    break;
            }
            break;
    }
}

int main()
{
    int fromUnit, toUnit;
    float value;

    printf("Enter the unit you want to convert from: (0 - liters, 1 - liters, 2 - quarts)");
    scanf("%d", &fromUnit);

    printf("Enter the unit you want to convert to: (0 - liters, 1 - liters, 2 - quarts)");
    scanf("%d", &toUnit);

    printf("Enter the value you want to convert:");
    scanf("%f", &value);

    UnitConverter(fromUnit, toUnit, value);

    return 0;
}