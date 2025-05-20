//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define MAX_STR_LEN 32

typedef struct {
    double value;
    char unit[MAX_STR_LEN];
} Measurement;

void print_usage(char *program_name) {
    fprintf(stderr, "Usage: %s <value> <unit>\n", program_name);
    fprintf(stderr, "  <value>  The value to be converted\n");
    fprintf(stderr, "  <unit>   The unit of the value (e.g. km, m, cm, etc.)\n");
}

int convert_unit(Measurement *m, char *unit) {
    if (strcmp(unit, "m") == 0) {
        m->unit[0] = 'm';
        m->value /= 1000;
    } else if (strcmp(unit, "km") == 0) {
        m->unit[0] = 'k';
        m->value *= 1000;
    } else {
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }

    Measurement m;
    char *endptr;
    m.value = strtod(argv[1], &endptr);
    if (*endptr != '\0') {
        fprintf(stderr, "Invalid value: %s\n", argv[1]);
        return 1;
    }

    if (convert_unit(&m, argv[2]) != 0) {
        fprintf(stderr, "Invalid unit: %s\n", argv[2]);
        return 1;
    }

    printf("%f %s\n", m.value, m.unit);

    return 0;
}