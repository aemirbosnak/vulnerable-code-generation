//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

struct unit {
    char *name;
    double factor;
};

int main() {
    int n_units;
    struct unit *units;

    printf("Enter number of units (max %d): ", MAX_UNITS);
    scanf("%d", &n_units);

    units = (struct unit *)malloc(n_units * sizeof(struct unit));

    printf("Enter units (name, factor):\n");
    for (int i = 0; i < n_units; i++) {
        scanf("%s %lf", &units[i].name, &units[i].factor);
    }

    double value;
    char from_unit[MAX_UNITS], to_unit[MAX_UNITS];

    printf("Enter value to convert:\n");
    scanf("%lf", &value);

    printf("Enter from unit:\n");
    scanf("%s", from_unit);

    printf("Enter to unit:\n");
    scanf("%s", to_unit);

    for (int i = 0; i < n_units; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            for (int j = 0; j < n_units; j++) {
                if (strcmp(to_unit, units[j].name) == 0) {
                    printf("%.2lf %s = %.2lf %s\n", value, from_unit, value * units[i].factor / units[j].factor, to_unit);
                    break;
                }
            }
            break;
        }
    }

    return 0;
}