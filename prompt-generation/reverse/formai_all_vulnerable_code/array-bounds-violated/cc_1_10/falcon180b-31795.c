//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNITS 6
#define UNIT_NAMES { "Meters", "Kilometers", "Inches", "Feet", "Yards", "Miles" }
#define UNIT_FACTORS { 1, 1000, 0.393701, 0.3048, 0.9144, 0.000621371 }
#define UNIT_ABBREVS { "m", "km", "in", "ft", "yd", "mi" }

struct unit_conversion {
    char *name;
    double factor;
    char abbrev[4];
};

struct unit_conversion units[UNITS] = {
    { "Meters", 1, "m" },
    { "Kilometers", 1000, "km" },
    { "Inches", 0.393701, "in" },
    { "Feet", 0.3048, "ft" },
    { "Yards", 0.9144, "yd" },
    { "Miles", 0.000621371, "mi" }
};

int main() {
    int choice, from_unit, to_unit;
    double value, result;
    char input[100];

    printf("Welcome to the Unit Converter!\n\n");
    printf("Please select the unit you want to convert from:\n");
    for (int i = 0; i < UNITS; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
    scanf("%d", &choice);
    from_unit = choice - 1;

    printf("Please enter the value you want to convert:\n");
    scanf("%lf", &value);

    printf("Please select the unit you want to convert to:\n");
    for (int i = 0; i < UNITS; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
    scanf("%d", &choice);
    to_unit = choice - 1;

    result = value * units[from_unit].factor / units[to_unit].factor;

    printf("%.2lf %s is equal to %.2lf %s.\n", value, units[from_unit].abbrev, result, units[to_unit].abbrev);

    return 0;
}