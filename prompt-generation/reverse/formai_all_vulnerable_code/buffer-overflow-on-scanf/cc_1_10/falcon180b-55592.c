//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    Unit units[] = {{"meters", 1}, {"kilometers", 1000}, {"miles", 1609.34}, {"yards", 1093.61}};
    int num_units = sizeof(units) / sizeof(units[0]);

    char input[100];
    double value, result;
    int unit_index;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from (meters, kilometers, miles, yards): ");
    scanf("%s", input);

    unit_index = -1;
    for (int i = 0; i < num_units; i++) {
        if (strcmp(input, units[i].name) == 0) {
            unit_index = i;
            break;
        }
    }

    if (unit_index == -1) {
        printf("Invalid unit.\n");
        return 1;
    }

    printf("Enter the unit to convert to (meters, kilometers, miles, yards): ");
    scanf("%s", input);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(input, units[i].name) == 0) {
            result = value * units[i].factor;
            printf("%lf %s is %lf %s.\n", value, units[unit_index].name, result, units[i].name);
            return 0;
        }
    }

    printf("Invalid unit.\n");
    return 1;
}