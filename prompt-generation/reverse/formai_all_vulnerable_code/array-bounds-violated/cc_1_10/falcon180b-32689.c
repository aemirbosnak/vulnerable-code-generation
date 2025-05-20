//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} unit;

unit units[MAX_UNITS];
int num_units;

void add_unit(char *name, double factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Too many units!\n");
        return;
    }

    units[num_units].name = strdup(name);
    units[num_units].factor = factor;
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
    add_unit("liter", 1.0);
    add_unit("gallon", 3.78541);

    int choice;
    double value, result;
    char unit_name[20];

    printf("Enter the unit you want to convert from:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
    scanf("%d", &choice);

    printf("Enter the value you want to convert:\n");
    scanf("%lf", &value);

    printf("Enter the unit you want to convert to:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
    scanf("%d", &choice);

    strcpy(unit_name, units[choice-1].name);

    result = value * units[choice-1].factor;

    printf("%.2lf %s = %.2lf %s\n", value, unit_name, result, units[choice-1].name);

    return 0;
}