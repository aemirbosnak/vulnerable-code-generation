//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNITS_COUNT 7

typedef struct {
    char *name;
    float factor;
} Unit;

Unit units[UNITS_COUNT] = {
    {"m", 1},
    {"cm", 0.01},
    {"mm", 0.001},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 160934.4}
};

int main() {
    int choice;
    float value, result;
    char unit_from[10], unit_to[10];

    printf("Welcome to the Unit Converter!\n");
    printf("Please choose the unit you want to convert from:\n");
    for (int i = 0; i < UNITS_COUNT; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
    scanf("%d", &choice);

    printf("Please enter the value you want to convert: ");
    scanf("%f", &value);

    printf("Please choose the unit you want to convert to:\n");
    for (int i = 0; i < UNITS_COUNT; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
    scanf("%d", &choice);

    strcpy(unit_from, units[choice-1].name);
    strcpy(unit_to, units[choice-1].name);

    for (int i = 0; i < UNITS_COUNT; i++) {
        if (strcmp(unit_to, units[i].name) == 0) {
            result = value * units[i].factor;
            printf("%f %s = %f %s\n", value, unit_from, result, unit_to);
            break;
        }
    }

    return 0;
}