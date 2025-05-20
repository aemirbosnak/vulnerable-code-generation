//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    char input[100];
    char from_unit[10], to_unit[10];
    double value, result;
    int i, from_index, to_index;
    Unit units[MAX_UNITS] = {
        {"m", 1.0},
        {"cm", 0.01},
        {"in", 0.0254},
        {"ft", 0.3048},
        {"yd", 0.9144},
        {"mi", 160934.4},
        {"kg", 1.0},
        {"g", 0.001},
        {"lb", 0.453592},
        {"oz", 0.0283495}
    };

    printf("Enter the value to convert:\n");
    scanf("%lf", &value);

    printf("Enter the unit of the value:\n");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to:\n");
    scanf("%s", to_unit);

    from_index = -1;
    to_index = -1;

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            from_index = i;
            break;
        }
    }

    if (from_index == -1) {
        printf("Invalid unit: %s\n", from_unit);
        return 1;
    }

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(to_unit, units[i].name) == 0) {
            to_index = i;
            break;
        }
    }

    if (to_index == -1) {
        printf("Invalid unit: %s\n", to_unit);
        return 1;
    }

    result = value * units[to_index].factor / units[from_index].factor;

    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);

    return 0;
}