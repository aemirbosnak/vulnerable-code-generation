//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 100

typedef struct {
    char *name;
    int value;
} Unit;

int main() {
    int num_units;
    char input[MAX_UNITS];
    Unit units[MAX_UNITS];
    int i;

    // Get number of units
    printf("Enter the number of units: ");
    scanf("%d", &num_units);

    // Get unit names and values
    for (i = 0; i < num_units; i++) {
        printf("Enter unit %d name: ", i+1);
        scanf("%s", input);
        strcpy(units[i].name, input);

        printf("Enter unit %d value: ", i+1);
        scanf("%d", &units[i].value);
    }

    // Convert units
    char from_unit[MAX_UNITS];
    char to_unit[MAX_UNITS];
    int value, converted_value;

    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    for (i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            value = units[i].value;
            break;
        }
    }

    for (i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, to_unit) == 0) {
            converted_value = (value * units[i].value) / 100;
            break;
        }
    }

    printf("%.2f %s = %.2f %s\n", value, from_unit, converted_value, to_unit);

    return 0;
}