//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char *name;
    double factor;
} Unit;

void print_units(Unit units[], int num_units) {
    printf("Available units:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%s\n", units[i].name);
    }
}

Unit* get_unit(char* unit_name, Unit units[], int num_units) {
    for (int i = 0; i < num_units; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            return &units[i];
        }
    }
    return NULL;
}

double convert(double value, Unit from_unit, Unit to_unit) {
    return (value * from_unit.factor) / to_unit.factor;
}

int main() {
    Unit units[] = {{"meters", 1}, {"feet", 0.3048}, {"inches", 0.0254}, {"kilograms", 1}, {"pounds", 2.20462}, {"ounces", 0.035274}};
    int num_units = sizeof(units) / sizeof(units[0]);

    printf("Welcome to the Unit Converter!\n");
    print_units(units, num_units);

    char from_unit_name[20], to_unit_name[20];
    printf("Enter the unit you want to convert from: ");
    scanf("%s", from_unit_name);
    printf("Enter the unit you want to convert to: ");
    scanf("%s", to_unit_name);

    Unit* from_unit = get_unit(from_unit_name, units, num_units);
    Unit* to_unit = get_unit(to_unit_name, units, num_units);

    if (from_unit == NULL || to_unit == NULL) {
        printf("Invalid unit.\n");
        return 1;
    }

    double value;
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    double result = convert(value, *from_unit, *to_unit);
    printf("%.2lf %s = %.2lf %s\n", value, from_unit_name, result, to_unit_name);

    return 0;
}