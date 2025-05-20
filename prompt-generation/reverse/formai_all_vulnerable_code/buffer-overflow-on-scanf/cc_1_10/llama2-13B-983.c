//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: visionary
// Visionary Unit Converter

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_COUNT 10
#define UNIT_NAMES \
    "cm", "m", "km", "mm", "inch", "ft", "yd", "mile", "lightyear"

typedef struct {
    char name[8];
    double factor;
} Unit;

Unit units[UNIT_COUNT] = {
    {"cm", 0.01},
    {"m", 0.001},
    {"km", 0.000001},
    {"mm", 0.0000001},
    {"inch", 0.08},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mile", 1.609344},
    {"lightyear", 9.46073e12}
};

int main() {
    int choice;
    double value;

    printf("Welcome to the Visionary Unit Converter!\n");

    do {
        printf("Please enter a value: ");
        scanf("%lf", &value);

        printf("Please select a unit: ");
        scanf("%d", &choice);

        for (int i = 0; i < UNIT_COUNT; i++) {
            if (choice == units[i].name[0]) {
                value *= units[i].factor;
                break;
            }
        }

        printf("Value in unit %s: %f\n", units[choice - '0'].name, value);

    } while (choice != 'q');

    return 0;
}