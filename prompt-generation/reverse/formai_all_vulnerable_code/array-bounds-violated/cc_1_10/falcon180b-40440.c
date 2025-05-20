//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 5

struct Unit {
    char name[10];
    double factor;
};

struct Unit units[MAX_UNITS];
int num_units = 0;

void add_unit(char *name, double factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }
    strcpy(units[num_units].name, name);
    units[num_units].factor = factor;
    num_units++;
}

int main() {
    add_unit("meter", 1.0);
    add_unit("kilometer", 1000.0);
    add_unit("gram", 1.0);
    add_unit("kilogram", 1000.0);
    add_unit("liter", 1.0);

    char input[20];
    double value;
    int choice;

    printf("Unit Converter\n");
    printf("Enter the unit you want to convert from: ");
    scanf("%s", input);
    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the unit you want to convert to:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
    scanf("%d", &choice);

    double result = value * units[choice-1].factor;

    printf("Result: %.2lf %s = %.2lf %s\n", value, input, result, units[choice-1].name);

    return 0;
}