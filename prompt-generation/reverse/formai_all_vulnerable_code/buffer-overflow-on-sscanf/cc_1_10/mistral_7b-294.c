//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024
#define NUM_UNITS 15

typedef struct {
    char name[20];
    double conversion_factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"mile", 1609.34},
    {"yard", 0.9144},
    {"foot", 0.3048},
    {"inch", 0.0254},
    {"pica", 0.01524},
    {"point", 0.00145},
    {"galoon", 3.7854},
    {"liter", 0.001},
    {"gallon_us", 3.78541},
    {"ounce", 0.029567},
    {"pound", 0.453592},
    {"star_parsec", 3.0857e+16},
};

void print_usage() {
    printf("Usage: TheGalacticMeasurer <convert|list|exit> <value> <from_unit> <to_unit>\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        print_usage();
        return 1;
    }

    char command = toupper(argv[1][0]);
    double value;
    int i;

    if (command != 'C' && command != 'L' && command != 'E') {
        print_usage();
        return 1;
    }

    if (command == 'C') {
        if (sscanf(argv[2], "%lf", &value) != 1) {
            fprintf(stderr, "Invalid value: %s\n", argv[2]);
            return 1;
        }

        i = find_unit_index(argv[3]);
        if (i < 0) {
            fprintf(stderr, "Unknown unit: %s\n", argv[3]);
            return 1;
        }

        value *= units[i].conversion_factor;

        i = find_unit_index(argv[4]);
        if (i < 0) {
            fprintf(stderr, "Unknown unit: %s\n", argv[4]);
            return 1;
        }

        value /= units[i].conversion_factor;

        printf("%.16f %s is equal to %.16f %s\n", value, argv[3], value, argv[4]);
    } else if (command == 'L') {
        for (i = 0; i < NUM_UNITS; i++) {
            printf("%d. %s\n", i + 1, units[i].name);
        }
    }

    return 0;
}

int find_unit_index(const char *unit_name) {
    int i;

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(units[i].name, unit_name) == 0) {
            return i;
        }
    }

    return -1;
}