//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    double conversion_factor;
} Unit;

Unit units[] = {
    {"inch", 0.0254},
    {"foot", 0.3048},
    {"yard", 0.9144},
    {"mile", 1609.34},
    {"gram", 0.001},
    {"kilogram", 1},
    {"pound", 0.4536},
    {"ounce", 0.035274},
    {"liter", 0.001},
    {"gallon", 0.00378541},
    {"Fahrenheit", 1.8},
    {"Celsius", 1},
    {"Kelvin", 1.8},
    {NULL, 0}
};

int find_unit_index(char *name) {
    int i;
    for (i = 0; units[i].name != NULL; i++) {
        if (strcasecmp(name, units[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

void print_usage() {
    printf("Usage: conv <from_unit> <to_unit> <value>\n");
    printf("Example: conv inch meter 12\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    int from_index, to_index;
    double value, result;

    if (argc != 4) {
        print_usage();
    }

    from_index = find_unit_index(argv[1]);
    to_index = find_unit_index(argv[2]);

    if (from_index == -1 || to_index == -1) {
        printf("Error: invalid unit %s or %s\n", argv[1], argv[2]);
        print_usage();
    }

    value = strtod(argv[3], NULL);

    result = value * units[from_index].conversion_factor / units[to_index].conversion_factor;

    printf("%.12f %s is equal to %.12f %s\n", value, argv[1], result, argv[3]);

    return 0;
}