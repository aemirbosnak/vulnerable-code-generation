//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: genius
#include <stdio.h>
#include <math.h>

void UnitConverter(float value, char fromUnit, char toUnit)
{
    float conversionFactor;

    switch (fromUnit)
    {
        case 'm':
            conversionFactor = 1;
            break;
        case 'kg':
            conversionFactor = 1000;
            break;
        case 'l':
            conversionFactor = 1000;
            break;
        case 'g':
            conversionFactor = 1000000;
            break;
        default:
            printf("Invalid unit.\n");
            return;
    }

    switch (toUnit)
    {
        case 'm':
            conversionFactor = 1;
            break;
        case 'kg':
            conversionFactor = 1000;
            break;
        case 'l':
            conversionFactor = 1000;
            break;
        case 'g':
            conversionFactor = 1000000;
            break;
        default:
            printf("Invalid unit.\n");
            return;
    }

    float convertedValue = value * conversionFactor;

    printf("Converted value: %.2f %s\n", convertedValue, toUnit);
}

int main()
{
    float value;
    char fromUnit;
    char toUnit;

    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the from unit: ");
    scanf(" %c", &fromUnit);

    printf("Enter the to unit: ");
    scanf(" %c", &toUnit);

    UnitConverter(value, fromUnit, toUnit);

    return 0;
}