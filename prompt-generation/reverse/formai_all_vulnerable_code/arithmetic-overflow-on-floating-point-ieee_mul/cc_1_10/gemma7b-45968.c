//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void UnitConverter(float value, int fromUnit, int toUnit)
{
    float conversionFactor;
    switch (fromUnit)
    {
        case 1:
            switch (toUnit)
            {
                case 2:
                    conversionFactor = 10;
                    break;
                case 3:
                    conversionFactor = 100;
                    break;
                case 4:
                    conversionFactor = 1000;
                    break;
            }
            break;
        case 2:
            switch (toUnit)
            {
                case 1:
                    conversionFactor = 0.1;
                    break;
                case 3:
                    conversionFactor = 10;
                    break;
                case 4:
                    conversionFactor = 100;
                    break;
            }
            break;
        case 3:
            switch (toUnit)
            {
                case 1:
                    conversionFactor = 0.01;
                    break;
                case 2:
                    conversionFactor = 0.1;
                    break;
                case 4:
                    conversionFactor = 10;
                    break;
            }
            break;
        case 4:
            switch (toUnit)
            {
                case 1:
                    conversionFactor = 0.001;
                    break;
                case 2:
                    conversionFactor = 0.01;
                    break;
                case 3:
                    conversionFactor = 0.1;
                    break;
            }
            break;
    }

    float convertedValue = value * conversionFactor;
    printf("%f", convertedValue);
}

int main()
{
    float value;
    int fromUnit, toUnit;

    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the from unit (1, 2, 3, 4): ");
    scanf("%d", &fromUnit);

    printf("Enter the to unit (1, 2, 3, 4): ");
    scanf("%d", &toUnit);

    UnitConverter(value, fromUnit, toUnit);

    return 0;
}