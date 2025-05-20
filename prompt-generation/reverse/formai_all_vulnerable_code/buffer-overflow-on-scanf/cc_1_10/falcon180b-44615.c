//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 100
#define MAX_FACTOR 10

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[MAX_UNITS];
int num_units;

void add_unit(char *name, double factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Too many units defined.\n");
        exit(1);
    }
    units[num_units].name = strdup(name);
    units[num_units].factor = factor;
    num_units++;
}

void print_units() {
    printf("Available units:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%s (%c)\n", units[i].name, 'A' + i);
    }
}

int main() {
    add_unit("meter", 1.0);
    add_unit("kilometer", 1000.0);
    add_unit("centimeter", 0.01);
    add_unit("inch", 0.0254);
    add_unit("foot", 0.3048);
    add_unit("yard", 0.9144);
    add_unit("mile", 160934.4);
    print_units();

    char unit1, unit2;
    double value;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the input unit (A-G): ");
    scanf(" %c", &unit1);

    printf("Enter the output unit (A-G): ");
    scanf(" %c", &unit2);

    for (int i = 0; i < num_units; i++) {
        if (units[i].name[0] == unit1) {
            for (int j = 0; j < num_units; j++) {
                if (units[j].name[0] == unit2) {
                    printf("%.2lf %c = %.2lf %c\n", value, unit1, value * units[j].factor, unit2);
                    return 0;
                }
            }
        }
    }

    printf("Invalid units.\n");
    return 1;
}