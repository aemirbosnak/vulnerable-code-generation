//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct UnitConverter {
    char *sourceUnit;
    char *targetUnit;
    double conversionFactor;
} UnitConverter;

int main() {
    UnitConverter converters[] = {
        {"kg", "g", 1000},
        {"L", "ml", 1000},
        {"km", "m", 1000},
        {"h", "min", 60},
        {"s", "ms", 1000}
    };

    char inputUnit[MAX_BUFFER_SIZE];
    char targetUnit[MAX_BUFFER_SIZE];
    double inputValue;

    printf("Enter the source unit: ");
    scanf("%s", inputUnit);

    printf("Enter the target unit: ");
    scanf("%s", targetUnit);

    printf("Enter the input value: ");
    scanf("%lf", &inputValue);

    for (int i = 0; i < 5; i++) {
        if (strcmp(converters[i].sourceUnit, inputUnit) == 0 && strcmp(converters[i].targetUnit, targetUnit) == 0) {
            double conversionFactor = converters[i].conversionFactor;
            double outputValue = inputValue * conversionFactor;
            printf("The output value is: %.2lf %s", outputValue, converters[i].targetUnit);
            break;
        }
    }

    if (strcmp(inputUnit, targetUnit) == 0) {
        printf("Error: the source and target units are the same.");
    } else if (inputValue == 0) {
        printf("Error: the input value is 0.");
    } else {
        printf("Error: the unit conversion is not available.");
    }

    return 0;
}