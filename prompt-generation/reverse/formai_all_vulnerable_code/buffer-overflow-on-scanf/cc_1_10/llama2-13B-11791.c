//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

struct unit {
    const char *name;
    double factor;
};

static struct unit units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12.0},
    {"yard", 36.0},
    {"mile", 5280.0},
    {"meter", 1.0},
    {"centimeter", 0.01},
    {"kilometer", 1000.0},
    {"gram", 0.001},
    {"kilogram", 1000.0},
    {"ounce", 0.0283495},
    {"pound", 0.453592}
};

int main() {
    double value, converted_value;
    char input_unit[20];
    char target_unit[20];

    printf("Enter a value: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from (e.g. 'inch'): ");
    fgets(input_unit, 20, stdin);

    printf("Enter the unit to convert to (e.g. 'meter'): ");
    fgets(target_unit, 20, stdin);

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            converted_value = value * units[i].factor;
            break;
        }
    }

    if (converted_value == 0) {
        printf("Invalid input unit or conversion.\n");
        return 1;
    }

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(target_unit, units[i].name) == 0) {
            printf("%.2lf %s = %.2lf %s\n", value, input_unit, converted_value, target_unit);
            break;
        }
    }

    return 0;
}