//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_UNITS 10
#define UNIT_NAMES "degF,C,mph,kmh,ft,m,in,yd,mi"

struct unit {
    const char *name;
    double factor;
};

static struct unit units[NUM_UNITS] = {
    {"degF", 9.0/5.0},
    {"C", 5.0/9.0},
    {"mph", 1.609344},
    {"kmh", 0.44704},
    {"ft", 12.0},
    {"m", 1.0},
    {"in", 0.0254},
    {"yd", 0.01097},
    {"mi", 1.609344}
};

int main() {
    double value;
    char input[10];
    char unit_name[10];
    int i;

    printf("Enter a value: ");
    fgets(input, 10, stdin);
    value = atof(input);

    printf("Enter the unit you want to convert to (e.g. 'degF'): ");
    fgets(unit_name, 10, stdin);

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            break;
        }
    }

    if (i == NUM_UNITS) {
        printf("Invalid unit. Please try again.\n");
        return 1;
    }

    printf("Value in unit %s: %f\n", units[i].name, value * units[i].factor);

    return 0;
}