//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} unit_t;

unit_t units[] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"mile", 1609.34},
    {"yard", 0.9144},
    {"foot", 0.3048},
    {"inch", 0.0254},
    {"centimeter", 0.01},
    {"millimeter", 0.001},
    {"micrometer", 0.000001},
    {"nanometer", 0.000000001}
};

int get_unit_index(char *name) {
    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(name, units[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

double convert(double value, char *from, char *to) {
    int from_index = get_unit_index(from);
    int to_index = get_unit_index(to);

    if (from_index == -1 || to_index == -1) {
        return -1.0;
    }

    return value * units[to_index].factor / units[from_index].factor;
}

int main() {
    char from[20], to[20];
    double value;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from: ");
    scanf("%s", from);

    printf("Enter the unit to convert to: ");
    scanf("%s", to);

    double converted_value = convert(value, from, to);

    if (converted_value == -1.0) {
        printf("Invalid units entered.\n");
    } else {
        printf("%lf %s is equal to %lf %s\n", value, from, converted_value, to);
    }

    return 0;
}