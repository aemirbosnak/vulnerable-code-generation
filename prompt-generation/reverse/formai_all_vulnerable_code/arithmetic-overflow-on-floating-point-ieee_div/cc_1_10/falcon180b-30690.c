//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 10

struct unit {
    char *name;
    float factor;
};

void add_unit(struct unit *units, int *num_units, char *name, float factor) {
    if (*num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }

    units[*num_units].name = strdup(name);
    units[*num_units].factor = factor;
    (*num_units)++;
}

int main() {
    char input[100];
    char from_unit[10], to_unit[10];
    float value, result;
    int num_units = 0;
    struct unit units[MAX_UNITS];

    add_unit(units, &num_units, "m", 1.0);
    add_unit(units, &num_units, "cm", 0.01);
    add_unit(units, &num_units, "mm", 0.001);
    add_unit(units, &num_units, "in", 0.393701);
    add_unit(units, &num_units, "ft", 12.0);
    add_unit(units, &num_units, "yd", 36.0);
    add_unit(units, &num_units, "mi", 63360.0);

    printf("Enter the value to convert: ");
    scanf("%f", &value);

    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            for (int j = 0; j < num_units; j++) {
                if (strcmp(to_unit, units[j].name) == 0) {
                    result = value * units[i].factor / units[j].factor;
                    printf("%.2f %s = %.2f %s\n", value, from_unit, result, to_unit);
                    break;
                }
            }
            break;
        }
    }

    return 0;
}