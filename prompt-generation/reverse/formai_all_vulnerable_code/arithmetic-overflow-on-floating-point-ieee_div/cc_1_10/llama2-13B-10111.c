//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[MAX_UNITS] = {
    {"cm", 10.0},
    {"m", 100.0},
    {"km", 100000.0},
    {"mm", 0.1},
    {"in", 2.54}
};

double convert(Unit from, Unit to) {
    return from.factor / to.factor;
}

int main() {
    int i, j;
    char input[100];
    Unit from, to;

    // Initialize the conversion table
    for (i = 0; i < MAX_UNITS; i++) {
        for (j = 0; j < MAX_UNITS; j++) {
            if (i == j) {
                continue;
            }

            units[i].factor = convert(units[i], units[j]);
        }
    }

    // Get the input unit and conversion factor
    printf("Enter the value in unit %s: ", units[0].name);
    fgets(input, 100, stdin);
    double value = atof(input);

    for (i = 1; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, units[0].name) == 0) {
            continue;
        }

        to = units[i];
        from = units[0];
        double factor = convert(from, to);
        printf("Value in %s is %f\n", to.name, value * factor);
        break;
    }

    return 0;
}