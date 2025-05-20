//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 512

typedef struct {
    char *name;
    double value;
} unit_t;

unit_t units[] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"centimeter", 0.01},
    {"millimeter", 0.001},
    {"inch", 0.0254},
    {"foot", 0.3048},
    {"yard", 0.9144},
    {"mile", 1609.344},
    {"pound", 0.453592},
    {"kilogram", 1.0},
    {"gram", 0.001},
    {"ounce", 0.0283495},
    {"fahrenheit", (5.0 / 9.0)},
    {"celsius", (9.0 / 5.0)},
    {"kelvin", 1.0}
};

int main() {
    char input[DATA_SIZE];
    double value;
    char *unit_from, *unit_to;
    int i, j;

    printf("Welcome to the Cyberpunk Unit Converter v1.0\n");
    printf("Enter the value, unit to convert from, and unit to convert to (e.g. 10 cm m): ");
    scanf("%lf %s %s", &value, input, input);

    unit_from = input;
    unit_to = input;

    for (i = 0; i < DATA_SIZE; i++) {
        if (strcmp(unit_from, units[i].name) == 0) {
            break;
        }
    }

    for (j = 0; j < DATA_SIZE; j++) {
        if (strcmp(unit_to, units[j].name) == 0) {
            break;
        }
    }

    if (i == DATA_SIZE || j == DATA_SIZE) {
        printf("Invalid unit(s) entered.\n");
        return EXIT_FAILURE;
    }

    value *= units[i].value / units[j].value;

    printf("%lf %s\n", value, unit_to);

    return EXIT_SUCCESS;
}