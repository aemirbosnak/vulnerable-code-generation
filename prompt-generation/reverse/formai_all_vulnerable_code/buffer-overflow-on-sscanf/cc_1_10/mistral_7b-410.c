//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1024
#define MAX_TOKEN 100

typedef struct {
    char unit[MAX_TOKEN];
    double conversion_factor;
} Unit;

Unit units[] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"km", 1000.0},
    {"lbs", 0.453592},
    {"kg", 2.20462},
    {"ft", 0.3048},
    {"in", 0.0254},
    {"oz", 0.035274},
    {"gallon", 3.78541},
    {"liter", 0.001},
    {NULL, 0.0}
};

void print_usage(void) {
    printf("Usage: unit_converter <value> <from_unit> <to_unit>\n");
    printf("Example: unit_converter 5 m km\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int i;
    double value, conversion;
    char *token[MAX_TOKEN];
    Unit *unit_from, *unit_to;

    if (argc != 4) {
        print_usage();
    }

    value = atof(argv[1]);

    if (sscanf(argv[2], "%s %n", argv[2], &i) != 1) {
        print_usage();
    }
    argv[2][i] = '\0';

    for (i = 0; units[i].unit[0]; i++) {
        if (strcmp(argv[2], units[i].unit) == 0) {
            unit_from = &units[i];
            break;
        }
    }
    if (!unit_from) {
        print_usage();
    }

    for (i = 0; units[i].unit[0]; i++) {
        if (strcmp(argv[3], units[i].unit) == 0) {
            unit_to = &units[i];
            break;
        }
    }
    if (!unit_to) {
        print_usage();
    }

    conversion = value * unit_from->conversion_factor / unit_to->conversion_factor;

    printf("%.12lf %s is equal to %.12lf %s\n", value, unit_from->unit, conversion, unit_to->unit);

    return EXIT_SUCCESS;
}