//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} unit;

void add_unit(unit *units, int *num_units, char *name, double factor) {
    if (*num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        exit(1);
    }
    units[*num_units].name = strdup(name);
    units[*num_units].factor = factor;
    (*num_units)++;
}

int main() {
    unit units[MAX_UNITS];
    int num_units = 0;
    char input[100];

    // Add some default units
    add_unit(units, &num_units, "m", 1.0);
    add_unit(units, &num_units, "km", 1000.0);
    add_unit(units, &num_units, "ft", 0.3048);
    add_unit(units, &num_units, "mi", 160934.4);

    printf("Enter a value to convert:\n");
    scanf("%s", input);

    int value_pos = 0;
    double value = strtod(input, &value_pos);

    printf("Enter the unit to convert from:\n");
    scanf("%s", input);

    int from_pos = 0;
    char *from_unit = strtok(input, " ");

    printf("Enter the unit to convert to:\n");
    scanf("%s", input);

    int to_pos = 0;
    char *to_unit = strtok(input, " ");

    for (int i = 0; i < num_units; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            from_pos = i;
            break;
        }
    }

    for (int i = 0; i < num_units; i++) {
        if (strcmp(to_unit, units[i].name) == 0) {
            to_pos = i;
            break;
        }
    }

    double result = value * units[from_pos].factor / units[to_pos].factor;

    printf("%.2f %s = %.2f %s\n", value, from_unit, result, to_unit);

    return 0;
}