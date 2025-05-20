//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

typedef struct unit {
    char name[20];
    double factor;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"centimeter", 0.01},
    {" millimeter", 0.001},
    {"yard", 0.9144},
    {"foot", 0.3048},
    {"inch", 0.0254},
    {"pound", 0.453592},
    {"ounce", 0.0283495},
    {"gram", 0.001},
    {"kilogram", 1000.0}
};

int main() {
    int i, j;
    double value, conversion_factor;
    char input_unit[20], output_unit[20];

    printf("Enter a value: ");
    scanf("%lf", &value);

    printf("Enter the unit of measurement (e.g., meter, kilogram): ");
    fgets(input_unit, 20, stdin);

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, input_unit) == 0) {
            conversion_factor = units[i].factor;
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid unit of measurement. Please try again.\n");
        return 1;
    }

    for (j = 0; j < MAX_CONVERSIONS; j++) {
        printf("Conversion factor: %f\n", conversion_factor);

        if (j > 0) {
            conversion_factor *= units[j].factor;
        }

        printf("Value in %s: %f\n", units[j].name, value / conversion_factor);

        if (j < MAX_CONVERSIONS - 1) {
            printf("To convert back, enter the unit of measurement again: ");
            fgets(output_unit, 20, stdin);

            for (i = 0; i < MAX_UNITS; i++) {
                if (strcmp(output_unit, units[i].name) == 0) {
                    conversion_factor = 1.0 / units[i].factor;
                    break;
                }
            }

            if (i == MAX_UNITS) {
                printf("Invalid unit of measurement. Please try again.\n");
                return 1;
            }

            value = value * conversion_factor;
            printf("Value in %s: %f\n", units[i].name, value);
        }
    }

    return 0;
}