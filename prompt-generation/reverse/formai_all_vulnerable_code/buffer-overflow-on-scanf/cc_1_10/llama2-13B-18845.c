//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct unit {
    char name[20];
    double factor;
} Unit;

typedef struct conversion {
    char from[20];
    char to[20];
    double factor;
} Conversion;

Unit units[MAX_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000.0},
    {"mi", 1609.344},
    {"ft", 0.3048},
    {"in", 0.0254},
    {"yd", 0.09144},
    {"mile", 1.609344}
};

Conversion conversions[MAX_CONVERTIONS] = {
    {"m", "cm", 0.01},
    {"m", "mm", 0.001},
    {"cm", "mm", 0.01},
    {"ft", "in", 0.0254},
    {"in", "yd", 0.09144},
    {"yd", "mile", 0.09144}
};

int main() {
    int i, j, k;
    double input, output;
    char from[20], to[20];

    printf("Unit Converter\n");

    for (i = 0; i < MAX_UNITS; i++) {
        printf("Unit: %s (%.2f)\n", units[i].name, units[i].factor);
    }

    for (i = 0; i < MAX_CONVERTIONS; i++) {
        printf("Conversion: %s to %s (%.2f)\n", conversions[i].from, conversions[i].to, conversions[i].factor);
    }

    do {
        printf("Enter the value in the unit you want to convert: ");
        scanf("%lf", &input);
        from[0] = '\0';
        to[0] = '\0';

        for (i = 0; i < MAX_UNITS; i++) {
            if (input >= units[i].factor) {
                strcpy(from, units[i].name);
                break;
            }
        }

        for (j = 0; j < MAX_CONVERTIONS; j++) {
            if (from[0] == conversions[j].from[0]) {
                strcpy(to, conversions[j].to);
                output = input * conversions[j].factor;
                break;
            }
        }

        printf("The value of %s is %s (%.2f)\n", from, to, output);
    } while (1);

    return 0;
}