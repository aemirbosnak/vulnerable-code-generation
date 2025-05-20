//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct unit {
    char name[20];
    double factor;
} unit_t;

typedef struct conversion {
    char from_unit[20];
    char to_unit[20];
    double factor;
} conversion_t;

unit_t units[MAX_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"mi", 1609.344},
    {"ft", 3.28084},
    {"in", 0.0254},
    {"yd", 0.01097},
    {"mile", 1609.344}
};

conversion_t conversions[MAX_CONVERTIONS] = {
    {"m", "ft", 3.28084},
    {"ft", "in", 12},
    {"in", "yd", 0.0254},
    {"yd", "mi", 0.01097},
    {"mi", "km", 1.609344}
};

int main() {
    int i, j;
    char input_unit[20];
    char output_unit[20];
    double input_value;
    double output_value;

    // Print the list of units
    printf("Available units:\n");
    for (i = 0; i < MAX_UNITS; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }

    // Print the list of conversions
    printf("Available conversions:\n");
    for (j = 0; j < MAX_CONVERTIONS; j++) {
        printf("%d. %s to %s\n", j + 1, conversions[j].from_unit, conversions[j].to_unit);
    }

    // Get the input value and unit
    printf("Enter the value and unit: ");
    scanf("%lf %s", &input_value, input_unit);

    // Find the conversion factor
    for (i = 0; i < MAX_CONVERTIONS; i++) {
        if (strcmp(input_unit, conversions[i].from_unit) == 0) {
            break;
        }
    }
    if (i == MAX_CONVERTIONS) {
        printf("Invalid unit\n");
        return 1;
    }

    // Perform the conversion
    output_value = input_value * conversions[i].factor;

    // Print the result
    printf("Value in %s: %f\n", conversions[i].to_unit, output_value);

    return 0;
}