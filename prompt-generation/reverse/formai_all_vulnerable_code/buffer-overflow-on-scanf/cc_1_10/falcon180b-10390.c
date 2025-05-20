//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <locale.h>

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[] = {
    {"m", 1},
    {"km", 1000},
    {"cm", 0.01},
    {"mm", 0.001},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},

    {"kg", 1},
    {"g", 0.001},
    {"lb", 0.453592},

    {"l", 1},
    {"ml", 0.001},
    {"fl. oz.", 0.0295735},
    {"gal", 3.78541},

    {"C", 1},
    {"F", 1.8},
    {"K", 1}
};

int main() {
    setlocale(LC_ALL, "");
    int n, i, j, k;
    char input[100], *endptr;
    Unit from, to;

    printf("Enter the number of units to convert: ");
    scanf("%d", &n);

    printf("Enter the units in the format 'from_unit to_unit value':\n");
    for (i = 0; i < n; i++) {
        scanf("%s %s %s", input, input + strlen(input) + 1, input + strlen(input) + strlen(input) + 1);
        from.name = input;
        to.name = input + strlen(input) + 1;
        from.factor = 1;
        for (j = 0; j < sizeof(units) / sizeof(Unit); j++) {
            if (!strcmp(from.name, units[j].name)) {
                from.factor = units[j].factor;
                break;
            }
        }
        for (k = 0; k < sizeof(units) / sizeof(Unit); k++) {
            if (!strcmp(to.name, units[k].name)) {
                to.factor = units[k].factor;
                break;
            }
        }
        if (from.factor == 0 || to.factor == 0) {
            printf("Invalid unit.\n");
            continue;
        }
        double value = strtod(input + strlen(input) + strlen(input) + 1, &endptr);
        if (*endptr!= '\0') {
            printf("Invalid value.\n");
            continue;
        }
        double result = value * from.factor / to.factor;
        printf("%s %s = %.2f %s\n", input, input + strlen(input) + 1, result, to.name);
    }

    return 0;
}