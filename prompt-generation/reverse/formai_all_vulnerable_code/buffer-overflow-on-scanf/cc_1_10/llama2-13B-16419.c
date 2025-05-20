//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 5
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
        {"cm", 10.0 / 2.54},
        {"m", 1.0},
        {"km", 1000.0 / 2.54},
        {"ft", 12.0 / 2.54},
        {"in", 0.3937 / 2.54}
    };

    struct conversion conversions[MAX_CONVERTIONS] = {
        {"cm", "m", 1.0},
        {"m", "km", 0.1},
        {"km", "ft", 0.001},
        {"ft", "in", 12.0 / 3.025},
        {"in", "cm", 2.54}
    };

    int unit_index, conversion_index;
    double value;

    printf("Enter a value: ");
    scanf("%lf", &value);

    for (unit_index = 0; unit_index < MAX_UNITS; unit_index++) {
        if (value == units[unit_index].factor * value) {
            break;
        }
    }

    for (conversion_index = 0; conversion_index < MAX_CONVERTIONS; conversion_index++) {
        if (conversions[conversion_index].from_unit == units[unit_index].name) {
            break;
        }
    }

    printf("Value in %s is %f\n", conversions[conversion_index].to_unit, value * conversions[conversion_index].factor);

    return 0;
}