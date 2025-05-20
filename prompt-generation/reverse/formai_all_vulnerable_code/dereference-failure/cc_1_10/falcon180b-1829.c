//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 100

typedef struct {
    char *name;
    double factor;
} unit;

unit units[MAX_UNITS];
int num_units;

void add_unit(char *name, double factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Too many units\n");
        return;
    }
    units[num_units].name = strdup(name);
    units[num_units].factor = factor;
    num_units++;
}

void print_units() {
    printf("Available units:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%s\n", units[i].name);
    }
}

int main() {
    add_unit("meter", 1.0);
    add_unit("kilometer", 1000.0);
    add_unit("centimeter", 0.01);
    add_unit("millimeter", 0.001);
    add_unit("inch", 0.0254);
    add_unit("foot", 0.3048);
    add_unit("yard", 0.9144);
    add_unit("mile", 160934.4);

    print_units();

    char from_unit[100], to_unit[100];
    double value;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    int from_index = -1, to_index = -1;

    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            from_index = i;
        }
        if (strcmp(units[i].name, to_unit) == 0) {
            to_index = i;
        }
    }

    if (from_index == -1 || to_index == -1) {
        printf("Error: Invalid units\n");
        return 1;
    }

    double result = value * units[from_index].factor / units[to_index].factor;

    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);

    return 0;
}