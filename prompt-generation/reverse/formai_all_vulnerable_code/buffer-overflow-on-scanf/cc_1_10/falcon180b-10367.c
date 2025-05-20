//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    char input[100];
    char from_unit[20], to_unit[20];
    double value, result;
    int from_unit_index, to_unit_index;
    Unit units[MAX_UNITS] = {{"meters", 1.0}, {"centimeters", 0.01}, {"millimeters", 0.001}, {"kilometers", 1000.0}, {"inches", 0.0254}, {"feet", 0.3048}, {"yards", 0.9144}, {"miles", 160934.4}, {"pounds", 0.453592}, {"ounces", 0.0283495}};
    int num_units = 0;

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter a value and the units you want to convert from and to:\n");
    scanf("%s %s %s", input, from_unit, to_unit);

    value = atof(input);

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            from_unit_index = i;
            break;
        }
    }

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, to_unit) == 0) {
            to_unit_index = i;
            break;
        }
    }

    if (from_unit_index == -1 || to_unit_index == -1) {
        printf("Invalid units entered.\n");
        return 1;
    }

    result = value * units[from_unit_index].factor / units[to_unit_index].factor;

    printf("%.2f %s is equal to %.2f %s.\n", value, from_unit, result, to_unit);

    return 0;
}