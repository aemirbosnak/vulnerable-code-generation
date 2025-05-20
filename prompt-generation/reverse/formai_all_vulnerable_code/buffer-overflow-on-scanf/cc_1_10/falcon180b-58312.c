//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} unit;

void add_unit(unit *units, int num_units, char *name, double factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        exit(1);
    }

    units[num_units].name = strdup(name);
    units[num_units].factor = factor;

    num_units++;
}

int main() {
    unit units[MAX_UNITS];
    int num_units = 0;
    char input[100];

    add_unit(units, num_units, "meters", 1.0);
    add_unit(units, num_units, "feet", 3.28084);
    add_unit(units, num_units, "inches", 39.3701);

    printf("Enter a value to convert:\n");
    scanf("%s", input);

    double value = atof(input);
    char from_unit[100];
    char to_unit[100];

    printf("Enter the unit of the value: ");
    scanf("%s", from_unit);

    int from_unit_index = -1;
    for (int i = 0; i < num_units; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            from_unit_index = i;
            break;
        }
    }

    if (from_unit_index == -1) {
        printf("Error: Invalid unit.\n");
        exit(1);
    }

    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    int to_unit_index = -1;
    for (int i = 0; i < num_units; i++) {
        if (strcmp(to_unit, units[i].name) == 0) {
            to_unit_index = i;
            break;
        }
    }

    if (to_unit_index == -1) {
        printf("Error: Invalid unit.\n");
        exit(1);
    }

    double result = value * units[to_unit_index].factor / units[from_unit_index].factor;

    printf("%.2f %s = %.2f %s\n", value, from_unit, result, to_unit);

    return 0;
}