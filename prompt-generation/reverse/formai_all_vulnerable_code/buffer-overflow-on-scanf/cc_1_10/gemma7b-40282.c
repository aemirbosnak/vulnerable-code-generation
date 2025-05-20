//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void UnitConverter(char **units, int **factors, int numUnits)
{
    int i, j, k, factor, conversionFactor, totalFactor = 0;
    char unit, convertedUnit;

    printf("Enter the unit you want to convert from: ");
    scanf("%c", &unit);

    for (i = 0; i < numUnits; i++)
    {
        if (units[i] == unit)
        {
            factor = factors[i];
            break;
        }
    }

    printf("Enter the unit you want to convert to: ");
    scanf("%c", &convertedUnit);

    for (j = 0; j < numUnits; j++)
    {
        if (units[j] == convertedUnit)
        {
            conversionFactor = factors[j];
            break;
        }
    }

    totalFactor = factor * conversionFactor;

    printf("Enter the number of units you want to convert: ");
    scanf("%d", &k);

    printf("The number of units converted is: %d", k * totalFactor);

    return;
}

int main()
{
    char *units[] = {"m", "kg", "l", "s", "g"};
    int *factors = {1000, 1000, 1000, 86400, 1000};
    int numUnits = 5;

    UnitConverter(units, factors, numUnits);

    return 0;
}