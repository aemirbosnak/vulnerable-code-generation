//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LEN 1024

enum {
    CELSIUS,
    FAHRENHEIT
};

struct unit {
    char *name;
    double factor;
};

static struct unit units[] = {
    {"C", 1.0},
    {"F", 1.8}
};

static int num_units = sizeof(units) / sizeof(units[0]);

static int parse_unit(const char *str)
{
    int i;

    for (i = 0; i < num_units; i++) {
        if (strcmp(str, units[i].name) == 0) {
            return i;
        }
    }

    return -1;
}

static double convert_temp(double temp, int from_unit, int to_unit)
{
    if (from_unit == to_unit) {
        return temp;
    }

    if (from_unit == CELSIUS) {
        temp += 273.15;
    } else if (from_unit == FAHRENHEIT) {
        temp = (temp - 32) * 5.0 / 9.0;
    }

    return temp * units[to_unit].factor;
}

static void usage(const char *progname)
{
    fprintf(stderr, "Usage: %s <temperature> <from_unit> <to_unit>\n", progname);
    fprintf(stderr, "where <from_unit> and <to_unit> are one of:\n");

    for (int i = 0; i < num_units; i++) {
        fprintf(stderr, "  %s\n", units[i].name);
    }
}

int main(int argc, char *argv[])
{
    if (argc!= 4) {
        usage(argv[0]);
        return 1;
    }

    double temp = strtod(argv[1], NULL);
    int from_unit = parse_unit(argv[2]);
    int to_unit = parse_unit(argv[3]);

    if (from_unit == -1 || to_unit == -1) {
        usage(argv[0]);
        return 1;
    }

    double result = convert_temp(temp, from_unit, to_unit);

    printf("%.2f %s = %.2f %s\n", temp, units[from_unit].name, result, units[to_unit].name);

    return 0;
}