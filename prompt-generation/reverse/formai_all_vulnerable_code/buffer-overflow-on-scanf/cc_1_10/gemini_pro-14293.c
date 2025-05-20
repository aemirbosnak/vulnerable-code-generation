//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    LENGTH,
    WEIGHT,
    VOLUME
} unit_type;

typedef struct {
    char *name;
    double conversion_factor;
} unit;

unit units[] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"lb", 0.453592},
    {"oz", 0.0283495},
    {"g", 0.000453592},
    {"kg", 1.0},
    {"l", 1.0},
    {"ml", 0.001},
    {"gal", 3.78541},
    {"pt", 0.473176},
    {"qt", 0.946353}
};

const int num_units = sizeof(units) / sizeof(unit);

double convert(double value, unit from, unit to) {
    return value * from.conversion_factor / to.conversion_factor;
}

int main() {
    double value;
    char from_unit[3];
    char to_unit[3];
    int i, j;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    for (i = 0; i < num_units; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            for (j = 0; j < num_units; j++) {
                if (strcmp(to_unit, units[j].name) == 0) {
                    printf("%lf %s is equal to %lf %s\n", value, from_unit, convert(value, units[i], units[j]), to_unit);
                    return 0;
                }
            }
        }
    }

    printf("Invalid unit conversion\n");
    return 1;
}