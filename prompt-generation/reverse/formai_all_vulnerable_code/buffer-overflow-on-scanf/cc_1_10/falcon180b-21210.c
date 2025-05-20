//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[MAX_UNITS];
int num_units;

void add_unit(char *name, double factor) {
    if (num_units >= MAX_UNITS) {
        fprintf(stderr, "Error: Maximum number of units reached.\n");
        exit(1);
    }
    units[num_units] = (Unit) {name, factor};
    num_units++;
}

int main() {
    add_unit("meter", 1.0);
    add_unit("kilometer", 1000.0);
    add_unit("gram", 1.0);
    add_unit("kilogram", 1000.0);
    add_unit("liter", 1.0);
    add_unit("milliliter", 0.001);
    add_unit("second", 1.0);
    add_unit("minute", 60.0);
    add_unit("hour", 3600.0);
    add_unit("day", 86400.0);

    char input[100];
    char from_unit[20];
    char to_unit[20];
    double value;

    printf("Enter the value to convert:\n");
    scanf("%s", input);

    printf("Enter the unit of the value:\n");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to:\n");
    scanf("%s", to_unit);

    int from_index = -1;
    int to_index = -1;

    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            from_index = i;
        }
        if (strcmp(units[i].name, to_unit) == 0) {
            to_index = i;
        }
    }

    if (from_index == -1 || to_index == -1) {
        fprintf(stderr, "Error: Invalid unit.\n");
        exit(1);
    }

    value *= units[from_index].factor;
    value /= units[to_index].factor;

    printf("%.2f %s = %.2f %s\n", value, to_unit, value, from_unit);

    return 0;
}