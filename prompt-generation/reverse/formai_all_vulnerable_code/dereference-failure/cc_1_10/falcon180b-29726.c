//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_UNITS 100

struct unit_conversion {
    char *name;
    double conversion_factor;
};

struct unit_conversion units[MAX_UNITS];
int num_units = 0;

void add_unit(char *name, double conversion_factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        exit(1);
    }
    units[num_units].name = strdup(name);
    units[num_units].conversion_factor = conversion_factor;
    num_units++;
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

    int choice;
    double value, result;
    char unit_name[MAX_UNITS];

    printf("Enter the unit you want to convert from:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
    scanf("%d", &choice);
    printf("Enter the value to convert:\n");
    scanf("%lf", &value);
    printf("Enter the unit to convert to:\n");
    scanf("%s", unit_name);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, unit_name) == 0) {
            result = value * units[i].conversion_factor;
            printf("%.2lf %s = %.2lf %s\n", value, unit_name, result, units[i].name);
            break;
        }
    }

    return 0;
}