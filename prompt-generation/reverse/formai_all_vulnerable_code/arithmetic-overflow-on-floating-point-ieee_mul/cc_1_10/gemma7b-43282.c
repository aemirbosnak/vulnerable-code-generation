//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>
#include <math.h>

void UnitConverter(double value, int fromUnit, int toUnit)
{
    double conversionFactor = 0;

    switch (fromUnit)
    {
        case 1: // Meter
            switch (toUnit)
            {
                case 2: // Centimeter
                    conversionFactor = 100;
                    break;
                case 3: // Millimeter
                    conversionFactor = 1000;
                    break;
            }
            break;
        case 2: // Centimeter
            switch (toUnit)
            {
                case 1: // Meter
                    conversionFactor = 0.01;
                    break;
                case 3: // Millimeter
                    conversionFactor = 10;
                    break;
            }
            break;
        case 3: // Millimeter
            switch (toUnit)
            {
                case 1: // Meter
                    conversionFactor = 0.001;
                    break;
                case 2: // Centimeter
                    conversionFactor = 0.1;
                    break;
            }
            break;
    }

    double convertedValue = value * conversionFactor;

    printf("The converted value is: %.2lf %s", convertedValue, toUnit);
}

int main()
{
    double value;
    int fromUnit, toUnit;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the from unit (1 - Meter, 2 - Centimeter, 3 - Millimeter): ");
    scanf("%d", &fromUnit);

    printf("Enter the to unit (1 - Meter, 2 - Centimeter, 3 - Millimeter): ");
    scanf("%d", &toUnit);

    UnitConverter(value, fromUnit, toUnit);

    return 0;
}