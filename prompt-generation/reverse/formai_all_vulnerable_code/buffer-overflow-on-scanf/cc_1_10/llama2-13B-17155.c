//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 5
#define MAX_CONVERTIONS 10

typedef struct unit {
    char name[20];
    double factor;
} unit_t;

unit_t units[] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"mi", 1609.34}
};

int main() {
    int i, j, num_units;
    double value, conversion_factor;
    char input_unit[20];
    char output_unit[20];

    printf("Enter a value: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from (m, cm, mm, km, mi): ");
    fgets(input_unit, 20, stdin);

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            conversion_factor = units[i].factor;
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid unit. Please enter a valid unit.\n");
        return 1;
    }

    for (j = 0; j < MAX_CONVERTIONS; j++) {
        printf("Conversion from %s to %s: %lf\n", units[i].name, units[j].name, value * conversion_factor);
        value *= conversion_factor;
        conversion_factor = 1.0;
    }

    return 0;
}