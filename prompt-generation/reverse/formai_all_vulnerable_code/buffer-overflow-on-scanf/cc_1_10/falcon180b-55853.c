//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} unit;

unit units[MAX_UNITS];
int num_units;

void add_unit(char *name, double factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Too many units.\n");
        exit(1);
    }
    units[num_units].name = name;
    units[num_units].factor = factor;
    num_units++;
}

int get_unit_index(char *name) {
    for (int i = 0; i < num_units; i++) {
        if (strcmp(name, units[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

double convert(double value, int from_unit, int to_unit) {
    double result = value * units[from_unit].factor;
    for (int i = from_unit + 1; i <= to_unit; i++) {
        result /= units[i].factor;
    }
    return result;
}

int main() {
    add_unit("meter", 1.0);
    add_unit("centimeter", 0.01);
    add_unit("millimeter", 0.001);
    add_unit("kilogram", 1.0);
    add_unit("gram", 0.001);
    add_unit("second", 1.0);
    add_unit("minute", 60.0);
    add_unit("hour", 3600.0);
    add_unit("liter", 1.0);
    add_unit("milliliter", 0.001);

    int num_conversions;
    printf("Enter the number of conversions: ");
    scanf("%d", &num_conversions);

    for (int i = 0; i < num_conversions; i++) {
        char from_unit_name[20];
        char to_unit_name[20];
        printf("Enter the units for conversion %d (e.g. meter to centimeter): ", i+1);
        scanf("%s %s", from_unit_name, to_unit_name);

        int from_unit = get_unit_index(from_unit_name);
        int to_unit = get_unit_index(to_unit_name);

        if (from_unit == -1 || to_unit == -1) {
            printf("Error: Invalid unit.\n");
            continue;
        }

        double value;
        printf("Enter the value to convert: ");
        scanf("%lf", &value);

        double result = convert(value, from_unit, to_unit);
        printf("%.2lf %s = %.2lf %s\n", value, units[from_unit].name, result, units[to_unit].name);
    }

    return 0;
}