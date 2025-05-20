//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double factor;
} unit;

void print_units(unit *units, int num_units) {
    printf("Available units:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
}

int get_unit_index(unit *units, int num_units, char *name) {
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

double convert(double value, unit from_unit, unit to_unit) {
    return value * from_unit.factor / to_unit.factor;
}

int main() {
    unit units[] = {
        {"meters", 1.0},
        {"feet", 3.28084},
        {"inches", 39.3701},
        {"kilograms", 1.0},
        {"pounds", 2.20462},
        {"ounces", 35.274},
    };
    int num_units = sizeof(units) / sizeof(units[0]);

    print_units(units, num_units);

    char from_unit_name[50];
    char to_unit_name[50];

    printf("Enter the unit you want to convert from: ");
    scanf("%s", from_unit_name);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", to_unit_name);

    int from_unit_index = get_unit_index(units, num_units, from_unit_name);
    int to_unit_index = get_unit_index(units, num_units, to_unit_name);

    if (from_unit_index == -1 || to_unit_index == -1) {
        printf("Invalid unit.\n");
        return 1;
    }

    double value;
    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    double result = convert(value, units[from_unit_index], units[to_unit_index]);

    printf("%.2lf %s = %.2lf %s\n", value, from_unit_name, result, to_unit_name);

    return 0;
}