//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ConversionRates {
    float usdToEur;
    float usdToYen;
    float usdToPound;
    float usdToCad;
} ConversionRates;

ConversionRates conversionRates;

int main() {
    conversionRates.usdToEur = 0.99;
    conversionRates.usdToYen = 113.82;
    conversionRates.usdToPound = 0.84;
    conversionRates.usdToCad = 1.25;

    float amount;
    printf("Enter the amount you want to convert: ");
    scanf("%f", &amount);

    char currency;
    printf("Enter the currency you want to convert to: ");
    scanf(" %c", &currency);

    float convertedAmount = 0;

    switch (currency) {
        case 'E':
            convertedAmount = amount * conversionRates.usdToEur;
            break;
        case 'Y':
            convertedAmount = amount * conversionRates.usdToYen;
            break;
        case 'P':
            convertedAmount = amount * conversionRates.usdToPound;
            break;
        case 'C':
            convertedAmount = amount * conversionRates.usdToCad;
            break;
        default:
            printf("Invalid currency.\n");
            break;
    }

    if (convertedAmount > 0) {
        printf("The converted amount is: %.2f %s.\n", convertedAmount, currency);
    }

    return 0;
}