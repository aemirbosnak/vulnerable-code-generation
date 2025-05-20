//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>
#include <math.h>

void UnitConverter(double value, char fromUnit, char toUnit)
{
    double conversionFactor;

    switch (fromUnit)
    {
        case 'm':
            switch (toUnit)
            {
                case 'km':
                    conversionFactor = 1000;
                    break;
                case 'hm':
                    conversionFactor = 100;
                    break;
                case 'dm':
                    conversionFactor = 10;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
                    return;
            }
            break;
        case 'kg':
            switch (toUnit)
            {
                case 'g':
                    conversionFactor = 1000;
                    break;
                case 't':
                    conversionFactor = 1000000;
                    break;
                default:
                    printf("Invalid unit conversion.\n");
                    return;
            }
            break;
        default:
            printf("Invalid unit conversion.\n");
            return;
    }

    conversionFactor = conversionFactor * value;

    printf("%f %s converted to %f %s is %f.\n", value, fromUnit, toUnit, conversionFactor, conversionFactor);
}

int main()
{
    double value;
    char fromUnit;
    char toUnit;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the from unit: ");
    scanf(" %c", &fromUnit);

    printf("Enter the to unit: ");
    scanf(" %c", &toUnit);

    UnitConverter(value, fromUnit, toUnit);

    return 0;
}