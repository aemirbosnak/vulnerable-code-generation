//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct unit {
    char name[20];
    double factor;
} unit_t;

typedef struct conversion {
    char from[20];
    char to[20];
} conversion_t;

static unit_t units[MAX_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000.0},
    {"mi", 1609.344},
    {"yd", 0.9144},
    {"ft", 1.0},
    {"in", 0.0254},
    {"pt", 0.000001},
    {"gc", 0.0000001}
};

static conversion_t conversions[MAX_CONVERTIONS] = {
    {"m", "ft"},
    {"cm", "in"},
    {"mm", "pt"},
    {"km", "mi"},
    {"yd", "ft"},
    {"ft", "in"}
};

void init_units(void) {
    int i;
    for (i = 0; i < MAX_UNITS; i++) {
        units[i].factor = pow(10, i * 3);
    }
}

void init_conversions(void) {
    int i, j;
    for (i = 0; i < MAX_CONVERTIONS; i++) {
        for (j = 0; j < MAX_UNITS; j++) {
            conversions[i].from[j] = units[j].name;
            conversions[i].to[j] = units[j].name;
        }
    }
}

void convert(double value, char *from_unit, char *to_unit) {
    int from_index = 0, to_index = 0;
    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            from_index = i;
            break;
        }
    }
    for (int j = 0; j < MAX_UNITS; j++) {
        if (strcmp(to_unit, units[j].name) == 0) {
            to_index = j;
            break;
        }
    }
    if (from_index == -1 || to_index == -1) {
        printf("Invalid unit(s) provided. Please enter a valid unit(s) for conversion.\n");
        return;
    }
    value *= units[from_index].factor;
    value /= units[to_index].factor;
    printf("Value in %s is %f\n", to_unit, value);
}

int main(void) {
    init_units();
    init_conversions();
    char from_unit[20], to_unit[20];
    double value;

    printf("Welcome to the Unit Converter!\n");
    printf("Enter a value in a unit (e.g. 50 m): ");
    scanf("%lf", &value);
    gets(from_unit);
    gets(to_unit);
    convert(value, from_unit, to_unit);
    return 0;
}