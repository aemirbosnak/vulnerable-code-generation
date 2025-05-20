//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: happy
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
    char from_unit[10];
    char to_unit[10];
    double value;
    int from_unit_index, to_unit_index;
    Unit units[MAX_UNITS] = {{"meters", 1.0},
                             {"centimeters", 0.01},
                             {"millimeters", 0.001},
                             {"kilometers", 1000.0},
                             {"inches", 0.0254},
                             {"feet", 0.3048},
                             {"yards", 0.9144},
                             {"miles", 160934.4},
                             {"pounds", 0.453592},
                             {"ounces", 0.0283495}};

    printf("Welcome to the happy unit converter!\n");
    printf("Please enter the value you want to convert: ");
    scanf("%lf", &value);

    printf("Please enter the unit you want to convert from: ");
    scanf("%s", from_unit);

    printf("Please enter the unit you want to convert to: ");
    scanf("%s", to_unit);

    // Find the indices of the from and to units
    for (from_unit_index = 0; from_unit_index < MAX_UNITS; from_unit_index++) {
        if (strcmp(from_unit, units[from_unit_index].name) == 0) {
            break;
        }
    }

    for (to_unit_index = 0; to_unit_index < MAX_UNITS; to_unit_index++) {
        if (strcmp(to_unit, units[to_unit_index].name) == 0) {
            break;
        }
    }

    // Convert the value
    value *= units[from_unit_index].factor;
    value /= units[to_unit_index].factor;

    printf("%.2lf %s is equal to %.2lf %s!\n", value, to_unit, value, from_unit);

    return 0;
}