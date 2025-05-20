//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

struct unit {
    char name[20];
    double value;
};

struct conversion {
    char from_unit[20];
    char to_unit[20];
    double factor;
};

int main() {
    struct unit units[MAX_UNITS] = {
        {"inch", 2.54},
        {"foot", 12},
        {"yard", 36},
        {"mile", 5280},
        {"pound", 453.592}
    };

    struct conversion conversions[MAX_CONVERSIONS] = {
        {"inch", "foot", 12},
        {"foot", "yard", 3},
        {"yard", "mile", 0.025},
        {"pound", "ounce", 16},
        {"ounce", "pound", 0.0625}
    };

    int unit_count = 0;
    int conversion_count = 0;

    while (1) {
        char input[50];
        double value;

        printf("Enter a unit or conversion (q to quit): ");
        fgets(input, 50, stdin);

        if (strcmp(input, "q") == 0) break;

        if (sscanf(input, "%lf%19s", &value, units[unit_count].name) == 2) {
            units[unit_count].value = value;
            unit_count++;

            if (unit_count >= MAX_UNITS) {
                printf("Too many units. Quitting...\n");
                break;
            }
        }

        if (sscanf(input, "%19s%19s", conversions[conversion_count].from_unit, conversions[conversion_count].to_unit) == 2) {
            conversions[conversion_count].factor = (double)conversions[conversion_count].to_unit[0] / (double)conversions[conversion_count].from_unit[0];
            conversion_count++;

            if (conversion_count >= MAX_CONVERSIONS) {
                printf("Too many conversions. Quitting...\n");
                break;
            }
        }
    }

    printf("Units:\n");
    for (int i = 0; i < unit_count; i++) {
        printf("%-20s: %8.2f\n", units[i].name, units[i].value);
    }

    printf("\nConversions:\n");
    for (int i = 0; i < conversion_count; i++) {
        printf("%-20s %-20s: %8.2f\n", conversions[i].from_unit, conversions[i].to_unit, conversions[i].factor);
    }

    return 0;
}