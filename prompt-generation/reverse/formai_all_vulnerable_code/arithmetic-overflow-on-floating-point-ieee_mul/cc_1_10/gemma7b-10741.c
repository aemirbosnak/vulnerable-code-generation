//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT_NUMBER 1000

typedef struct ConversionRate {
    char sourceUnit;
    char targetUnit;
    int conversionFactor;
} ConversionRate;

ConversionRate conversionRates[] = {
    {'m', 'kg', 1000},
    {'g', 'kg', 1000},
    {'L', 'ml', 1000},
    {'ml', 'L', 1000},
    {'g', 't', 1000000}
};

int main() {
    float numberToConvert;
    char sourceUnit;
    char targetUnit;

    printf("Enter the number to convert: ");
    scanf("%f", &numberToConvert);

    printf("Enter the source unit: ");
    scanf(" %c", &sourceUnit);

    printf("Enter the target unit: ");
    scanf(" %c", &targetUnit);

    ConversionRate* conversionRate = NULL;
    for (int i = 0; i < MAX_CONVERT_NUMBER; i++) {
        if (conversionRates[i].sourceUnit == sourceUnit && conversionRates[i].targetUnit == targetUnit) {
            conversionRate = &conversionRates[i];
            break;
        }
    }

    if (conversionRate == NULL) {
        printf("Error: Invalid conversion.\n");
        return 1;
    }

    float convertedNumber = numberToConvert * conversionRate->conversionFactor;

    printf("The converted number is: %.2f %s.\n", convertedNumber, conversionRate->targetUnit);

    return 0;
}