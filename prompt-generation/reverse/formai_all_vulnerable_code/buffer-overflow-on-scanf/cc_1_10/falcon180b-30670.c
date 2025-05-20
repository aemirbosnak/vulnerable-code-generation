//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    char input[MAX_UNITS + 1];
    char output[MAX_UNITS + 1];
    int num_units;
    Unit units[MAX_UNITS];

    printf("Enter the input unit: ");
    scanf("%s", input);

    printf("Enter the output unit: ");
    scanf("%s", output);

    printf("Enter the number of units to convert (1-%d): ", MAX_UNITS);
    scanf("%d", &num_units);

    printf("Enter the units and their conversion factors:\n");
    for (int i = 0; i < num_units; i++) {
        printf("Unit %d: ", i + 1);
        scanf("%s %lf", units[i].name, &units[i].factor);
    }

    double value = 1;
    for (int i = 0; i < num_units; i++) {
        if (strcmp(input, units[i].name) == 0) {
            break;
        }
        value *= units[i].factor;
    }

    for (int i = 0; i < num_units; i++) {
        if (strcmp(output, units[i].name) == 0) {
            printf("%s = %.2lf %s\n", input, value / units[i].factor, units[i].name);
            break;
        }
    }

    return 0;
}