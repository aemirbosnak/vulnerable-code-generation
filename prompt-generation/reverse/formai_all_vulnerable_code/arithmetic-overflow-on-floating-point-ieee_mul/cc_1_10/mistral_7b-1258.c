//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char unit[20];
    float conversionFactor;
} Unit;

Unit units[] = {
    {"Miles", 0.000621371},
    {"Kilometers", 1.60934},
    {"Pounds", 0.453592},
    {"Kilograms", 2.20462},
    {"Degrees Fahrenheit", 1.8},
    {"Degrees Celsius", 1},
    {"Liters", 0.264172},
    {"Gallons", 3.78541},
    {"Seconds", 1},
    {"Minutes", 60},
    {"Hours", 3600},
    {"Days", 86400},
    {"Yards", 0.9144},
    {"Feet", 0.3048},
    {"Inches", 0.0254},
    {"Meters", 1},
    {"Centimeters", 0.01},
    {"Millimeters", 0.001},
};

void printUnits() {
    int i;
    printf("\nAvailable Units:\n");
    for (i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        printf("%s : %s\n", units[i].unit, units[i].unit);
    }
}

void convert(Unit from, Unit to, float value) {
    float result;
    result = value * (to.conversionFactor / from.conversionFactor);
    printf("%.2f %s is equal to %.2f %s\n", value, from.unit, result, to.unit);
}

int main() {
    char inputUnit1[20], inputUnit2[20];
    float value;
    int i;
    Unit from, to;

    printUnits();

    printf("\nEnter the first unit: ");
    scanf("%s", inputUnit1);

    for (i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        if (strcmp(inputUnit1, units[i].unit) == 0) {
            from = units[i];
            break;
        }
    }

    if (i == sizeof(units) / sizeof(Unit)) {
        printf("Invalid unit: %s\n", inputUnit1);
        return 0;
    }

    printf("\nEnter the second unit: ");
    scanf("%s", inputUnit2);

    for (i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        if (strcmp(inputUnit2, units[i].unit) == 0) {
            to = units[i];
            break;
        }
    }

    if (i == sizeof(units) / sizeof(Unit)) {
        printf("Invalid unit: %s\n", inputUnit2);
        return 0;
    }

    printf("\nEnter the value to convert: ");
    scanf("%f", &value);

    convert(from, to, value);

    return 0;
}