//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

static struct unit units[] = {
    {"inch", 2.54},
    {"foot", 12.0},
    {"yard", 36.0},
    {"mile", 5280.0},
    {"kilometer", 1000.0}
};

static struct conversion conversions[] = {
    {"inch", "foot", 1.0 / 12.0},
    {"foot", "yard", 1.0 / 3.0},
    {"yard", "mile", 1.0 / 1760.0},
    {"mile", "kilometer", 1.0 / 5280.0}
};

int main() {
    int i, j;
    double value, converted_value;
    char input_unit[20];
    char output_unit[20];

    // Print the list of units
    printf("Available units:\n");
    for (i = 0; i < MAX_UNITS; i++) {
        printf("  %s\n", units[i].name);
    }

    // Print the list of conversions
    printf("Available conversions:\n");
    for (j = 0; j < MAX_CONVERTIONS; j++) {
        printf("  %s to %s\n", conversions[j].from_unit, conversions[j].to_unit);
    }

    // Get the input value and unit
    printf("Enter a value and unit: ");
    fgets(input_unit, sizeof(input_unit), stdin);
    input_unit[strcspn(input_unit, "\n")] = 0;

    // Perform the conversion
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            converted_value = value = atof(input_unit);
            for (j = 0; j < MAX_CONVERTIONS; j++) {
                if (strcmp(units[i].name, conversions[j].from_unit) == 0) {
                    converted_value = converted_value * conversions[j].factor;
                    break;
                }
            }
            printf("Conversion: %s = %f %s\n", input_unit, converted_value, conversions[j].to_unit);
            break;
        }
    }

    return 0;
}