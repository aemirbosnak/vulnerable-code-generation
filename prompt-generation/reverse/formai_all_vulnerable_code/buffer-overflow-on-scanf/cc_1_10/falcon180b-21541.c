//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_UNITS 10
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"meters", 1.0},
    {"centimeters", 0.01},
    {"millimeters", 0.001},
    {"inches", 0.0254},
    {"feet", 0.3048},
    {"yards", 0.9144},
    {"miles", 160934.4},
    {"kilograms", 1.0},
    {"grams", 0.001},
    {"pounds", 0.453592}
};

int main() {
    char from_unit[MAX_NAME_LEN];
    char to_unit[MAX_NAME_LEN];
    double value;
    int from_unit_index, to_unit_index;

    printf("Enter the unit you want to convert from: ");
    fgets(from_unit, MAX_NAME_LEN, stdin);
    from_unit[strcspn(from_unit, "\n")] = '\0';

    printf("Enter the unit you want to convert to: ");
    fgets(to_unit, MAX_NAME_LEN, stdin);
    to_unit[strcspn(to_unit, "\n")] = '\0';

    from_unit_index = -1;
    to_unit_index = -1;

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            from_unit_index = i;
        }
        if (strcmp(to_unit, units[i].name) == 0) {
            to_unit_index = i;
        }
    }

    if (from_unit_index == -1 || to_unit_index == -1) {
        printf("Invalid unit entered.\n");
        return 1;
    }

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    double result = value * units[from_unit_index].factor / units[to_unit_index].factor;

    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);

    return 0;
}