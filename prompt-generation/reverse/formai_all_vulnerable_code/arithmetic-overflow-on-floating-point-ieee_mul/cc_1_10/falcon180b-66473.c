//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERSIONS 10

typedef enum {
    LENGTH,
    WEIGHT,
    VOLUME,
    TEMPERATURE,
    TIME
} ConversionType;

typedef struct {
    char fromUnit[20];
    char toUnit[20];
    double factor;
} Conversion;

Conversion conversions[MAX_CONVERSIONS] = {
    {"meter", "feet", 3.28084},
    {"meter", "yard", 1.09361},
    {"meter", "kilometer", 0.001},
    {"kilogram", "pound", 2.20462},
    {"kilogram", "ounce", 35.274},
    {"liter", "gallon", 0.264172},
    {"liter", "pint", 0.568261},
    {"second", "minute", 60},
    {"minute", "hour", 60},
    {"celsius", "fahrenheit", 9.0/5.0}
};

int main() {
    int numConversions;
    char fromUnit[20], toUnit[20];
    double value;

    printf("Welcome to the Unit Converter!\n\n");

    printf("Enter the number of conversions you would like to perform (up to %d): ", MAX_CONVERSIONS);
    scanf("%d", &numConversions);

    for (int i = 0; i < numConversions; i++) {
        printf("Enter the conversion type (length, weight, volume, temperature, time): ");
        scanf("%s", conversions[i].fromUnit);

        printf("Enter the from unit: ");
        scanf("%s", fromUnit);

        printf("Enter the to unit: ");
        scanf("%s", toUnit);

        printf("Enter the value to convert: ");
        scanf("%lf", &value);

        for (int j = 0; j < MAX_CONVERSIONS; j++) {
            if (strcmp(conversions[j].fromUnit, fromUnit) == 0 && strcmp(conversions[j].toUnit, toUnit) == 0) {
                value *= conversions[j].factor;
                printf("%lf %s = %lf %s\n", value, toUnit, value, conversions[j].toUnit);
                break;
            }
        }
    }

    return 0;
}