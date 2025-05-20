//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS

typedef struct {
    float value;
    char unit[10];
} Unit;

void convert(Unit input, Unit *output, char targetUnit[]) {
    float conversionFactor = 1.0;

    if (strcmp(targetUnit, "miles") == 0) {
        conversionFactor = 0.000621371; // 1 kilometer to miles
    } else if (strcmp(targetUnit, "feet") == 0) {
        conversionFactor = 3280.84; // 1 kilometer to feet
    } else if (strcmp(targetUnit, "meters") == 0) {
        conversionFactor = 1.0; // No conversion needed for meters
    } else if (strcmp(targetUnit, "centimeters") == 0) {
        conversionFactor = 100.0; // 1 kilometer to centimeters
    } else if (strcmp(targetUnit, "grams") == 0) {
        conversionFactor = 1000.0; // 1 kilogram to grams
    } else if (strcmp(targetUnit, "pounds") == 0) {
        conversionFactor = 2.20462; // 1 kilogram to pounds
    }

    output->value = input.value * conversionFactor;
    strcpy(output->unit, targetUnit);
}

void printUnit(Unit unit) {
    printf("Value: %.2f %s\n", unit.value, unit.unit);
}

int main() {
    Unit input, output;
    char targetUnit[10];

    printf("Welcome to the Unit Converter 3000!\n");
    printf("Please input the value and unit you want to convert:\n");
    printf("Value: ");
    scanf("%f", &input.value);
    printf("Unit: ");
    scanf("%s", input.unit);
    printf("Target unit: ");
    scanf("%s", targetUnit);

    convert(input, &output, targetUnit);

    printf("\nResult:\n");
    printUnit(output);

    return 0;
}