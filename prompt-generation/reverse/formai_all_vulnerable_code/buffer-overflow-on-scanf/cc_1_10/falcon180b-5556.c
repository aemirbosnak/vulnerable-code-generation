//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 160934.4},
    {"km", 1000.0},
    {"l", 1.0},
    {"ml", 0.001},
    {"fl.oz", 0.0295735},
    {"gal", 3.78541},
    {"kg", 1.0},
    {"g", 0.001},
    {"lb", 0.453592},
    {"oz", 0.0283495},
    {NULL, 0.0}
};

int main() {
    char from[20], to[20];
    double value;
    Unit *unit_from, *unit_to;
    int i;

    printf("Enter the unit to convert from: ");
    scanf("%s", from);

    printf("Enter the unit to convert to: ");
    scanf("%s", to);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    for (i = 0; units[i].name!= NULL; i++) {
        if (strcmp(units[i].name, from) == 0) {
            unit_from = &units[i];
            break;
        }
    }

    for (i = 0; units[i].name!= NULL; i++) {
        if (strcmp(units[i].name, to) == 0) {
            unit_to = &units[i];
            break;
        }
    }

    if (unit_from == NULL || unit_to == NULL) {
        printf("Invalid unit conversion.\n");
        return 1;
    }

    value *= unit_from->factor;
    value /= unit_to->factor;

    printf("%.2lf %s = %.2lf %s\n", value, to, value, from);

    return 0;
}