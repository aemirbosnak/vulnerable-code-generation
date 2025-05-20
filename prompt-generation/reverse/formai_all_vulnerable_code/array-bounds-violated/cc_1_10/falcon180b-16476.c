//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[MAX_UNITS];
int unit_count = 0;

void add_unit(char *name, double factor) {
    if (unit_count >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }

    units[unit_count].name = strdup(name);
    units[unit_count].factor = factor;

    unit_count++;
}

int main() {
    add_unit("meters", 1.0);
    add_unit("feet", 3.28084);
    add_unit("yards", 1.09361);
    add_unit("miles", 0.000621371);
    add_unit("kilometers", 0.001);
    add_unit("centimeters", 0.01);
    add_unit("millimeters", 0.001);
    add_unit("inches", 0.0254);
    add_unit("liters", 3.78541);
    add_unit("gallons", 0.264172);

    int choice;
    double value, result;
    char unit_from[20], unit_to[20];

    printf("Welcome to the futuristic unit converter!\n");
    printf("Please select a unit to convert from:\n");

    for (int i = 0; i < unit_count; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }

    scanf("%d", &choice);

    strcpy(unit_from, units[choice-1].name);

    printf("Please enter the value to convert:\n");
    scanf("%lf", &value);

    printf("Please select a unit to convert to:\n");

    for (int i = 0; i < unit_count; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }

    scanf("%d", &choice);

    strcpy(unit_to, units[choice-1].name);

    result = value * units[choice-1].factor;

    printf("%.2lf %s = %.2lf %s\n", value, unit_from, result, unit_to);

    return 0;
}