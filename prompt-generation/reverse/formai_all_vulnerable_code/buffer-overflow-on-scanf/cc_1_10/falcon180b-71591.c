//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NUM_UNITS 5

typedef struct {
    char *name;
    double factor;
} Unit;

void print_units(Unit units[]) {
    printf("Available units:\n");
    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
}

int get_unit_index(Unit units[], char *unit_name) {
    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(units[i].name, unit_name) == 0) {
            return i;
        }
    }
    return -1;
}

double convert(double value, Unit from_unit, Unit to_unit) {
    return value * from_unit.factor / to_unit.factor;
}

int main() {
    Unit units[NUM_UNITS] = {
        {"meters", 1.0},
        {"feet", 3.28084},
        {"inches", 39.3701},
        {"kilometers", 0.001},
        {"miles", 0.000621371}
    };

    int choice;
    double value, result;
    char unit_name[20];

    printf("Welcome to the unit converter!\n");
    print_units(units);

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Convert\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the value: ");
            scanf("%lf", &value);

            printf("Enter the unit of the value: ");
            scanf("%s", unit_name);

            int from_unit_index = get_unit_index(units, unit_name);
            if (from_unit_index == -1) {
                printf("Invalid unit.\n");
                continue;
            }

            printf("Enter the unit you want to convert to: ");
            scanf("%s", unit_name);

            int to_unit_index = get_unit_index(units, unit_name);
            if (to_unit_index == -1) {
                printf("Invalid unit.\n");
                continue;
            }

            result = convert(value, units[from_unit_index], units[to_unit_index]);
            printf("The result is: %.2lf %s\n", result, units[to_unit_index].name);
        } else if (choice == 2) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}