//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 20
#define UNIT_NAME_LEN 10
#define CONVERSION_FACTOR_LEN 20

typedef struct {
    char name[UNIT_NAME_LEN];
    double conversion_factor;
} Unit;

int main() {
    int num_units;
    scanf("%d", &num_units);

    if (num_units > MAX_UNITS || num_units < 2) {
        printf("Invalid number of units.\n");
        return 1;
    }

    Unit units[num_units];

    for (int i = 0; i < num_units; i++) {
        printf("Enter name of unit %d: ", i+1);
        scanf("%s", units[i].name);

        printf("Enter conversion factor for %s: ", units[i].name);
        scanf("%s", units[i].conversion_factor);
    }

    char from_unit[UNIT_NAME_LEN];
    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);

    char to_unit[UNIT_NAME_LEN];
    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, from_unit) == 0 && strcmp(units[i].name, to_unit)!= 0) {
            for (int j = 0; j < num_units; j++) {
                if (strcmp(units[j].name, to_unit) == 0) {
                    double result = (double)units[i].conversion_factor / units[j].conversion_factor;
                    printf("%s %s = %.2f %s\n", units[i].name, to_unit, result, units[j].name);
                }
            }
        }
    }

    return 0;
}