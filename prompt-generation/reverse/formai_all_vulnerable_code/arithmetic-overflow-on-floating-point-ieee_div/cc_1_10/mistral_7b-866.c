//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    float conversionFactor;
} Unit;

Unit units[] = {
    {"Ounce", 0.06852},
    {"Gram", 1.0},
    {"Kilogram", 1000.0},
    {"Milliliter", 0.03527}
};

void printUnits() {
    printf("\nAvailable Units:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s\t-%0.2f\n", units[i].name, units[i].conversionFactor);
    }
}

float convert(float value, Unit fromUnit, Unit toUnit) {
    float result;

    if (fromUnit.name[0] == toUnit.name[0]) {
        printf("Error: Cannot convert %s to itself!\n", fromUnit.name);
        exit(EXIT_FAILURE);
    }

    result = value * (toUnit.conversionFactor / fromUnit.conversionFactor);
    return result;
}

int main() {
    float value, convertedValue;
    Unit fromUnit, toUnit;

    printf("\n** Welcome to the Cheerful Unit Converter! **\n");
    printUnits();

    printf("\nEnter the value to be converted: ");
    scanf("%f", &value);

    printf("\nEnter the unit of the given value: ");
    printf("\nFor Ounces: type 'oz'\nFor Grams: type 'g'\nFor Kilograms: type 'kg'\nFor Milliliters: type 'ml'\n");
    scanf("%s", fromUnit.name);

    for (int i = 0; i < 4; i++) {
        if (strcmp(fromUnit.name, units[i].name) == 0) {
            fromUnit = units[i];
            break;
        }
    }

    printf("\nEnter the unit to convert to: ");
    printf("\nFor Ounces: type 'oz'\nFor Grams: type 'g'\nFor Kilograms: type 'kg'\nFor Milliliters: type 'ml'\n");
    scanf("%s", toUnit.name);

    for (int i = 0; i < 4; i++) {
        if (strcmp(toUnit.name, units[i].name) == 0) {
            toUnit = units[i];
            break;
        }
    }

    convertedValue = convert(value, fromUnit, toUnit);
    printf("\n%0.2f %s is equal to %0.2f %s\n", value, fromUnit.name, convertedValue, toUnit.name);

    return EXIT_SUCCESS;
}