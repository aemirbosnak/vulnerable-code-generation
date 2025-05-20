//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 6
#define MAX_NAME_LEN 20
#define MIN_VALUE 0.0001

typedef struct {
    char name[MAX_NAME_LEN];
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"meters", 1.0},
    {"kilometers", 1000.0},
    {"grams", 1.0},
    {"kilograms", 1000.0},
    {"liters", 1.0},
    {"gallons", 3.78541}
};

int main() {
    printf("Welcome to the Post-Apocalyptic Unit Converter!\n");
    printf("Enter the unit you want to convert from: ");
    char from_unit[MAX_NAME_LEN];
    scanf("%s", from_unit);

    int from_unit_index = -1;
    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            from_unit_index = i;
            break;
        }
    }

    if (from_unit_index == -1) {
        printf("Invalid unit: %s\n", from_unit);
        return 1;
    }

    printf("Enter the unit you want to convert to: ");
    char to_unit[MAX_NAME_LEN];
    scanf("%s", to_unit);

    int to_unit_index = -1;
    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(units[i].name, to_unit) == 0) {
            to_unit_index = i;
            break;
        }
    }

    if (to_unit_index == -1) {
        printf("Invalid unit: %s\n", to_unit);
        return 1;
    }

    printf("Enter the value to convert: ");
    double value;
    if (scanf("%lf", &value)!= 1 || value <= MIN_VALUE) {
        printf("Invalid value\n");
        return 1;
    }

    double result = value * units[to_unit_index].factor / units[from_unit_index].factor;
    printf("%.2lf %s = %.2lf %s\n", value, units[from_unit_index].name, result, units[to_unit_index].name);

    return 0;
}