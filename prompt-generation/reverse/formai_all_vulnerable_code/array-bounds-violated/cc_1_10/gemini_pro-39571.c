//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

#define MAX_UNITS 100

typedef struct {
    char *name;
    double factor;
} unit_t;

unit_t units[MAX_UNITS];
int num_units;

void add_unit(char *name, double factor) {
    assert(num_units < MAX_UNITS);
    units[num_units].name = malloc(strlen(name) + 1);
    strcpy(units[num_units].name, name);
    units[num_units].factor = factor;
    num_units++;
}

int find_unit(char *name) {
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

double convert_unit(double value, char *from, char *to) {
    int from_index = find_unit(from);
    int to_index = find_unit(to);
    assert(from_index != -1 && to_index != -1);
    return value * units[from_index].factor / units[to_index].factor;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <value> <from> <to>\n", argv[0]);
        exit(1);
    }

    double value = atof(argv[1]);
    char *from = argv[2];
    char *to = argv[3];

    double converted_value = convert_unit(value, from, to);

    printf("%f %s = %f %s\n", value, from, converted_value, to);

    return 0;
}