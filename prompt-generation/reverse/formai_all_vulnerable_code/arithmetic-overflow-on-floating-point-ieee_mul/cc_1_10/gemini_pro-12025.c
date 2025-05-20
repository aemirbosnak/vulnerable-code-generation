//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 100

typedef struct {
    char *name;
    double factor;
} unit;

unit units[MAX_UNITS];
int num_units = 0;

void add_unit(char *name, double factor)
{
    if (num_units == MAX_UNITS) {
        fprintf(stderr, "Error: too many units\n");
        exit(1);
    }

    units[num_units].name = strdup(name);
    units[num_units].factor = factor;
    num_units++;
}

double convert(double value, char *from_unit, char *to_unit)
{
    int i, j;

    for (i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            break;
        }
    }

    if (i == num_units) {
        fprintf(stderr, "Error: unknown unit '%s'\n", from_unit);
        exit(1);
    }

    for (j = 0; j < num_units; j++) {
        if (strcmp(units[j].name, to_unit) == 0) {
            break;
        }
    }

    if (j == num_units) {
        fprintf(stderr, "Error: unknown unit '%s'\n", to_unit);
        exit(1);
    }

    return value * units[i].factor / units[j].factor;
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s value from_unit to_unit\n", argv[0]);
        exit(1);
    }

    add_unit("inch", 2.54);
    add_unit("foot", 12.0);
    add_unit("yard", 36.0);
    add_unit("mile", 1609.34);
    add_unit("kilometer", 1000.0);
    add_unit("meter", 1.0);

    double value = atof(argv[1]);
    char *from_unit = argv[2];
    char *to_unit = argv[3];

    double converted_value = convert(value, from_unit, to_unit);

    printf("%f %s is equal to %f %s\n", value, from_unit, converted_value, to_unit);

    return 0;
}