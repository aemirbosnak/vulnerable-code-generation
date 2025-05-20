//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

struct unit_converter {
    char *name;
    double factor;
};

struct unit_converter units[MAX_UNITS];
int num_units;

void add_unit(char *name, double factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }

    units[num_units].name = strdup(name);
    units[num_units].factor = factor;
    num_units++;
}

int main() {
    add_unit("meter", 1.0);
    add_unit("kilometer", 1000.0);
    add_unit("gram", 1.0);
    add_unit("kilogram", 1000.0);
    add_unit("liter", 1.0);
    add_unit("milliliter", 0.001);

    int choice;
    double value, result;

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

    result = value * units[choice-1].factor;

    printf("%.2lf %s = %.2lf %s\n", value, units[choice-1].name, result, units[(choice-1+num_units)%num_units].name);

    return 0;
}