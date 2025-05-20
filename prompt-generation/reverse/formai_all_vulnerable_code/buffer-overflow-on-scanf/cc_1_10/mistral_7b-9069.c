//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double value;
    char unit[10];
} Unit;

Unit convert(Unit base, char* targetUnit) {
    Unit result;
    double conversionFactor;

    memset(&result, 0, sizeof(Unit));

    if (strcmp(base.unit, "m") == 0 && strcmp(targetUnit, "km") == 0) {
        conversionFactor = 0.001;
    } else if (strcmp(base.unit, "kg") == 0 && strcmp(targetUnit, "g") == 0) {
        conversionFactor = 1000.0;
    } else if (strcmp(base.unit, "l") == 0 && strcmp(targetUnit, "gal") == 0) {
        conversionFactor = 0.264172;
    } else {
        printf("Invalid units.\n");
        exit(EXIT_FAILURE);
    }

    result.value = base.value * conversionFactor;
    strcpy(result.unit, targetUnit);

    return result;
}

int main() {
    Unit input;
    char outputUnit[10];

    printf("Enter the value and unit: ");
    scanf("%lf %s", &input.value, input.unit);

    printf("Enter the output unit: ");
    scanf("%s", outputUnit);

    Unit output = convert(input, outputUnit);

    printf("Output:\n");
    printf("Value: %.2f\n", output.value);
    printf("Unit: %s\n", output.unit);

    return EXIT_SUCCESS;
}