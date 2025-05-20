//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct {
    char *name;
    double factor;
} Unit;

typedef struct {
    char *name;
    Unit units[MAX_UNITS];
} Conversion;

static Unit units[] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"mi", 1609.34},
    {"yd", 0.9144},
    {"ft", 1.0},
    {"in", 0.0254},
    {"pt", 0.000001}
};

static Conversion conversions[] = {
    {"m", "cm", 1.0},
    {"m", "mm", 0.01},
    {"m", "km", 0.001},
    {"m", "mi", 0.000621371},
    {"cm", "m", 0.01},
    {"cm", "mm", 0.001},
    {"cm", "yd", 0.09144},
    {"cm", "ft", 0.10},
    {"cm", "in", 0.0254},
    {"mm", "m", 0.001},
    {"mm", "cm", 0.0001},
    {"mm", "mm", 1.0},
    {"km", "m", 1000.0},
    {"km", "cm", 1000000.0},
    {"km", "mm", 1000000000.0},
    {"mi", "m", 0.000621371},
    {"mi", "cm", 0.00621371},
    {"mi", "mm", 0.0000621371},
    {"yd", "m", 0.9144},
    {"yd", "cm", 91.44},
    {"yd", "mm", 0.9144}
};

int main() {
    int i, j;
    double value, factor;
    char unit_in[20], unit_out[20];

    printf("Welcome to the Unit Converter! \n");

    // Initialize the input and output units
    for (i = 0; i < MAX_UNITS; i++) {
        unit_in[i] = units[i].name;
    }
    for (j = 0; j < MAX_UNITS; j++) {
        unit_out[j] = units[j].name;
    }

    // Get the input value from the user
    printf("Enter a value: ");
    scanf("%lf", &value);

    // Iterate through the possible input units and find the closest match
    for (i = 0; i < MAX_UNITS; i++) {
        factor = value / units[i].factor;
        if (fabs(factor - value) < fabs(factor - value / units[i].factor)) {
            break;
        }
    }

    // Output the converted value in the selected output unit
    for (j = 0; j < MAX_UNITS; j++) {
        if (i == j) {
            printf("%.2f %s\n", value, unit_out[j]);
            break;
        }
        printf("%.2f %s = %.2f %s\n", value, unit_in[i], value / units[i].factor, unit_out[j]);
    }

    return 0;
}