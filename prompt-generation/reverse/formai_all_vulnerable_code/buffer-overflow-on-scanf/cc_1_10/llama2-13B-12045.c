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

struct conversion {
    const char *from_unit;
    const char *to_unit;
    double factor;
};

static struct unit units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12},
    {"yard", 36},
    {"mile", 5280},
    {"meter", 100},
    {"centimeter", 0.01},
    {"kilometer", 100000},
    {"pound", 0.453592},
    {"ounce", 0.0283495},
    {"gram", 0.001}
};

static struct conversion conversions[MAX_CONVERSIONS] = {
    {"inch", "foot", 12},
    {"foot", "yard", 3},
    {"yard", "mile", 0.001},
    {"meter", "centimeter", 0.01},
    {"centimeter", "kilometer", 0.001},
    {"pound", "ounce", 16},
    {"ounce", "gram", 0.0283495}
};

int main() {
    double value, converted_value;
    char input_unit[20], output_unit[20];

    printf("Enter a value: ");
    scanf("%lf", &value);

    printf("Enter the input unit (e.g. 'inch', 'foot', etc.): ");
    fgets(input_unit, 20, stdin);

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            value *= units[i].factor;
            break;
        }
    }

    printf("Enter the output unit (e.g. 'foot', 'yard', etc.): ");
    fgets(output_unit, 20, stdin);

    for (int i = 0; i < MAX_CONVERSIONS; i++) {
        if (strcmp(output_unit, conversions[i].from_unit) == 0) {
            converted_value = value / conversions[i].factor;
            break;
        }
    }

    printf("The value of %s is %f %s\n", input_unit, converted_value, output_unit);

    return 0;
}