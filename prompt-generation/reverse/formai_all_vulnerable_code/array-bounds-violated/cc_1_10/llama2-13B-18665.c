//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct {
    char *name;
    double factor;
} unit_t;

static unit_t units[MAX_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"km", 1000},
    {"mm", 0.001},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 1609.344},
    {"kg", 0.001},
    {"g", 0.000001},
    {"lb", 0.453592}
};

static int convertions[MAX_CONVERTIONS] = {
    -1, // none
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1
};

void add_conversion(char *from, char *to) {
    int i = 0;
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, from) == 0) break;
    }
    if (i == MAX_UNITS) {
        printf("Invalid unit: %s\n", from);
        return;
    }
    convertions[i] = to;
}

void convert(double value, char *from, char *to) {
    int i = 0;
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, from) == 0) break;
    }
    if (i == MAX_UNITS) {
        printf("Invalid unit: %s\n", from);
        return;
    }
    double factor = units[i].factor;
    double converted = value * factor;
    if (to != NULL) {
        converted /= units[convertions[i]].factor;
        printf("%.2f %s = %.2f %s\n", value, from, converted, to);
    } else {
        printf("%.2f %s\n", value, from);
    }
}

int main() {
    double value = 5.0;
    char from[] = "m";
    char to[] = "ft";

    add_conversion("in", "cm");
    add_conversion("ft", "yd");
    add_conversion("yd", "mi");

    convert(value, from, to);

    return 0;
}