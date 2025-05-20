//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

struct unit {
    const char *name;
    double factor;
};

struct conversion {
    const char *from_unit;
    const char *to_unit;
    double factor;
};

static struct unit units[MAX_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000.0},
    {"mi", 1609.344},
    {"yd", 0.9144},
    {"ft", 0.3048},
    {"in", 0.0254},
    {"pt", 0.0001},
};

static struct conversion conversions[MAX_CONVERTIONS] = {
    {"m", "cm", 100.0},
    {"cm", "mm", 0.1},
    {"mm", "km", 0.001},
    {"km", "mi", 0.621371},
    {"mi", "yd", 1760.0},
    {"yd", "ft", 0.9144},
    {"ft", "in", 12.0},
    {"in", "pt", 0.0001},
};

int main() {
    int i, j;
    double value, converted_value;
    char unit_from[20], unit_to[20];

    printf("Welcome to the Unit Converter!\n");

    // Get the user's input
    printf("Enter a value: ");
    scanf("%lf", &value);

    // Ask the user for the units they want to convert from and to
    printf("Enter the units you want to convert from (e.g. 'm' for meters): ");
    fgets(unit_from, 20, stdin);
    unit_from[strcspn(unit_from, "\n")] = 0;

    printf("Enter the units you want to convert to (e.g. 'cm' for centimeters): ");
    fgets(unit_to, 20, stdin);
    unit_to[strcspn(unit_to, "\n")] = 0;

    // Find the appropriate conversion factors
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, unit_from) == 0) {
            break;
        }
    }

    for (j = 0; j < MAX_CONVERTIONS; j++) {
        if (strcmp(conversions[j].from_unit, unit_to) == 0) {
            break;
        }
    }

    // Perform the conversion
    converted_value = value * conversions[j].factor / units[i].factor;

    // Print the result
    printf("Value in %s: %f\n", unit_to, converted_value);

    return 0;
}