//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10

struct unit {
    char symbol[10];
    double factor;
};

int main() {
    struct unit units[MAX_UNITS];
    int num_units;
    char input[20];
    double value;
    char from_unit[10];
    char to_unit[10];
    int from_unit_index;
    int to_unit_index;

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the number of units you want to convert from: ");
    scanf("%d", &num_units);

    for (int i = 0; i < num_units; i++) {
        printf("Enter unit %d name: ", i + 1);
        scanf("%s", units[i].symbol);
        printf("Enter unit %d factor: ", i + 1);
        scanf("%lf", &units[i].factor);
    }

    printf("\nEnter the value you want to convert: ");
    scanf("%lf", &value);

    printf("\nEnter the unit you want to convert from: ");
    scanf("%s", from_unit);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(from_unit, units[i].symbol) == 0) {
            from_unit_index = i;
            break;
        }
    }

    printf("\nEnter the unit you want to convert to: ");
    scanf("%s", to_unit);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(to_unit, units[i].symbol) == 0) {
            to_unit_index = i;
            break;
        }
    }

    if (from_unit_index == -1 || to_unit_index == -1) {
        printf("\nError: Invalid unit entered.\n");
        return 1;
    }

    value = value * units[from_unit_index].factor;
    value = value / units[to_unit_index].factor;

    printf("\n%lf %s = %lf %s\n", value, from_unit, value, to_unit);

    return 0;
}