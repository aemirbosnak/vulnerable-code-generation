//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

struct unit {
    char name[20];
    double factor;
};

struct conversion {
    char from_unit[20];
    char to_unit[20];
    double factor;
};

int main() {
    struct unit units[MAX_UNITS] = {
        {"feet", 0.3048},
        {"meters", 1.0},
        {"kilometers", 1000.0},
        {"pounds", 0.453592},
        {"kilograms", 1.0}
    };

    struct conversion conversions[MAX_CONVERSIONS] = {
        {"feet", "meters", 0.3048},
        {"meters", "kilometers", 1.0},
        {"kilometers", "pounds", 0.453592},
        {"pounds", "kilograms", 0.453592},
        {"kilograms", "feet", 0.453592 / 0.3048}
    };

    int unit_count = 0;
    int conversion_count = 0;

    printf("Welcome to the Unit Converter!\n");

    while (1) {
        system("clear");
        printf("Available Units: \n");
        for (int i = 0; i < MAX_UNITS; i++) {
            printf("%d. %s (%f)\n", i + 1, units[i].name, units[i].factor);
        }

        printf("\nEnter a unit to convert: ");
        scanf("%d", &unit_count);

        if (unit_count > 0 && unit_count <= MAX_UNITS) {
            struct unit *unit = &units[unit_count - 1];
            printf("You have selected %s\n", unit->name);

            conversion_count = 0;
            printf("Available Conversions: \n");
            for (int i = 0; i < MAX_CONVERSIONS; i++) {
                printf("%d. %s to %s (%f)\n", i + 1, conversions[i].from_unit, conversions[i].to_unit, conversions[i].factor);
            }

            printf("\nEnter a conversion to perform: ");
            scanf("%d", &conversion_count);

            if (conversion_count > 0 && conversion_count <= MAX_CONVERSIONS) {
                struct conversion *conversion = &conversions[conversion_count - 1];
                double value = 0.0;
                char from_unit = conversion->from_unit[0];
                char to_unit = conversion->to_unit[0];

                if (from_unit == unit->name[0]) {
                    value = (double)scanf("%f", &value) == 1 ? value : 0.0;
                    value *= units[from_unit - '0'].factor;
                    value /= units[to_unit - '0'].factor;
                    printf("%.2f %s is equal to %.2f %s\n", value, from_unit, value, to_unit);
                } else {
                    printf("Invalid input. Please enter a valid value for %s\n", from_unit);
                }
            }
        } else {
            printf("Invalid input. Please enter a valid unit number\n");
        }
    }

    return 0;
}