//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"meters", 1.0},
    {"kilometers", 1000.0},
    {"grams", 1.0},
    {"kilograms", 1000.0},
    {"liters", 1.0},
    {"milliliters", 0.001},
    {"seconds", 1.0},
    {"minutes", 60.0},
    {"hours", 3600.0},
    {"days", 86400.0}
};

void print_units() {
    printf("Available units:\n");
    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
}

int main() {
    print_units();

    char input[20];
    int choice;
    scanf("%d", &choice);

    double value, result;
    int from_unit, to_unit;

    printf("Enter value to convert: ");
    scanf("%lf", &value);

    printf("Enter unit of value (1-%d): ", NUM_UNITS);
    scanf("%d", &from_unit);

    printf("Enter unit to convert to (1-%d): ", NUM_UNITS);
    scanf("%d", &to_unit);

    result = value * units[from_unit].factor / units[to_unit].factor;

    printf("%.2lf %s = %.2lf %s\n", value, units[from_unit].name, result, units[to_unit].name);

    return 0;
}