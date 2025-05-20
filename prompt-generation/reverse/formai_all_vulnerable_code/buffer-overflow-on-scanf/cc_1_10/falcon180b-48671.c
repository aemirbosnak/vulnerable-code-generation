//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    Unit units[MAX_UNITS];
    int num_units = 0;
    char input[100];

    units[num_units++] = (Unit) {"m", 1.0};
    units[num_units++] = (Unit) {"cm", 0.01};
    units[num_units++] = (Unit) {"mm", 0.001};
    units[num_units++] = (Unit) {"in", 0.0254};
    units[num_units++] = (Unit) {"ft", 0.3048};
    units[num_units++] = (Unit) {"yd", 0.9144};
    units[num_units++] = (Unit) {"mi", 160934.4};
    units[num_units++] = (Unit) {"kg", 1.0};
    units[num_units++] = (Unit) {"g", 0.001};
    units[num_units++] = (Unit) {"lb", 0.453592};

    printf("Enter a value and its unit (e.g. 5.5 kg): ");
    scanf("%s", input);

    char *value_str = strtok(input, " ");
    double value = atof(value_str);

    char *unit_str = strtok(NULL, " ");
    int i;
    for (i = 0; i < num_units; i++) {
        if (strcmp(unit_str, units[i].name) == 0) {
            break;
        }
    }

    if (i == num_units) {
        printf("Invalid unit.\n");
        return 1;
    }

    double result = value * units[i].factor;

    printf("%s = %.2f %s\n", value_str, result, unit_str);

    return 0;
}