//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    double factor;
} conversion_t;

static unit_t units[MAX_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000.0},
    {"mi", 1609.344},
    {"yd", 0.9144},
    {"ft", 0.3048},
    {"in", 0.0254},
    {"pt", 0.00009144},
    {" Angle", 1}
};

static conversion_t conversions[MAX_CONVERTIONS] = {
    {"m", "cm", 0.01},
    {"m", "mm", 0.001},
    {"cm", "mm", 0.01},
    {"km", "mi", 1.609344},
    {"yd", "ft", 0.9144},
    {"ft", "in", 0.3048},
    {"in", "pt", 0.00009144}
};

int main() {
    int i, j;
    char input[50];
    char output[50];
    double value;

    printf("Unit Converter v1.0\n");

    while (1) {
        printf("Enter a unit: ");
        fgets(input, 50, stdin);
        input[strcspn(input, "\n")] = 0; // ignore newline

        for (i = 0; i < MAX_UNITS; i++) {
            if (strcmp(units[i].name, input) == 0) {
                break;
            }
        }

        if (i == MAX_UNITS) {
            printf("Invalid unit. Please enter a valid unit.\n");
            continue;
        }

        printf("Enter a value: ");
        scanf("%lf", &value);

        for (j = 0; j < MAX_CONVERTIONS; j++) {
            if (strcmp(conversions[j].from, input) == 0) {
                break;
            }
        }

        if (j == MAX_CONVERTIONS) {
            printf("Invalid conversion. Please enter a valid conversion.\n");
            continue;
        }

        value *= conversions[j].factor;
        sprintf(output, "%.2f %s", value, conversions[j].to);

        printf("Value in %s is %.2f %s\n", input, value, output);
    }

    return 0;
}