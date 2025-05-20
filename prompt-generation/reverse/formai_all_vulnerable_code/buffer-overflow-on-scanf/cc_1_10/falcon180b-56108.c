//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double factor;
} Unit;

void print_units(Unit *units, int n) {
    printf("Available units:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", units[i].name);
    }
}

int get_unit_index(Unit *units, int n, char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(units[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

double convert(double value, Unit from, Unit to) {
    return value * from.factor / to.factor;
}

int main() {
    Unit units[] = {{"meters", 1.0}, {"feet", 3.28084}, {"inches", 39.3701}, {"kilograms", 1.0}, {"pounds", 2.20462}, {"ounces", 35.274}};
    int n = sizeof(units) / sizeof(units[0]);

    char from_unit[20], to_unit[20];
    double value, result;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);

    int from_index = get_unit_index(units, n, from_unit);
    if (from_index == -1) {
        printf("Invalid unit: %s\n", from_unit);
        return 1;
    }

    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    int to_index = get_unit_index(units, n, to_unit);
    if (to_index == -1) {
        printf("Invalid unit: %s\n", to_unit);
        return 1;
    }

    result = convert(value, units[from_index], units[to_index]);

    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);

    return 0;
}