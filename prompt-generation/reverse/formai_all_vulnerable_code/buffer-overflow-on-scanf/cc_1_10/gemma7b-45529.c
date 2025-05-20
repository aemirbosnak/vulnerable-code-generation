//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: complete
#include <stdio.h>
#include <math.h>

void UnitConverter(float value, int fromUnit, int toUnit)
{
    float conversionFactor;

    switch (fromUnit)
    {
        case 0:
            conversionFactor = 1;
            break;
        case 1:
            conversionFactor = 1000;
            break;
        case 2:
            conversionFactor = 16;
            break;
        case 3:
            conversionFactor = 2.208;
            break;
        default:
            printf("Invalid unit conversion.\n");
            return;
    }

    switch (toUnit)
    {
        case 0:
            conversionFactor = 1;
            break;
        case 1:
            conversionFactor = 1000;
            break;
        case 2:
            conversionFactor = 16;
            break;
        case 3:
            conversionFactor = 2.208;
            break;
        default:
            printf("Invalid unit conversion.\n");
            return;
    }

    float convertedValue = value * conversionFactor;

    printf("Converted value: %.2f %s to %.2f %s.\n", value, fromUnit, convertedValue, toUnit);
}

int main()
{
    float value;
    int fromUnit, toUnit;

    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the unit conversion from: ");
    scanf("%d", &fromUnit);

    printf("Enter the unit conversion to: ");
    scanf("%d", &toUnit);

    UnitConverter(value, fromUnit, toUnit);

    return 0;
}