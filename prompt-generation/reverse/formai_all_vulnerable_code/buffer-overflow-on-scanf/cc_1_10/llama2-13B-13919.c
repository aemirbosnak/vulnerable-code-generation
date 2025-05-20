//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    struct unit units[MAX_UNITS] = {
        {"inch", 2.54},
        {"foot", 12.0},
        {"yard", 36.0},
        {"mile", 5280.0},
        {"kilometer", 1000.0}
    };

    struct conversion conversions[MAX_CONVERTIONS] = {
        {"inch", "foot", 1.0},
        {"foot", "yard", 0.3048},
        {"yard", "mile", 0.025625},
        {"mile", "kilometer", 1.60934}
    };

    char input_unit[32];
    char output_unit[32];
    double input_value;

    printf("Enter a value in inches: ");
    scanf("%lf", &input_value);

    printf("Enter the unit you want to convert to: ");
    fgets(input_unit, 32, stdin);

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            break;
        }
    }

    for (int i = 0; i < MAX_CONVERTIONS; i++) {
        if (strcmp(units[i].name, units[i].name) == 0) {
            continue;
        }

        for (int j = 0; j < MAX_CONVERTIONS; j++) {
            if (strcmp(conversions[j].from_unit, units[i].name) == 0) {
                input_value *= conversions[j].factor;
                break;
            }
        }
    }

    printf("The value in %s is %lf\n", output_unit, input_value);

    return 0;
}