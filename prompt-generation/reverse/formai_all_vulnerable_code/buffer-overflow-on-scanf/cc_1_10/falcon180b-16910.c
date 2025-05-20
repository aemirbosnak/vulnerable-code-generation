//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define NUM_UNITS 8

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {{"m", 1}, {"km", 1000}, {"cm", 0.01}, {"mm", 0.001}, {"in", 0.0254}, {"ft", 0.3048}, {"yd", 0.9144}, {"mi", 160934.4}};

int main() {
    char input[100];
    char *endptr;
    double value, result = 0;
    int i, choice;

    printf("Enter a value to convert:\n");
    scanf("%s", input);

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(input, units[i].name) == 0) {
            result = 1;
            break;
        }
    }

    if (result == 0) {
        printf("Invalid unit.\n");
        return 1;
    }

    printf("Enter the unit to convert to:\n");
    scanf("%s", input);

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(input, units[i].name) == 0) {
            choice = i;
            break;
        }
    }

    if (choice == -1) {
        printf("Invalid unit.\n");
        return 1;
    }

    value = strtod(input, &endptr);

    if (endptr == input || *endptr!= '\0') {
        printf("Invalid value.\n");
        return 1;
    }

    result = value * units[choice].factor;

    printf("%.2f %s = %.2f %s\n", value, input, result, units[choice].name);

    return 0;
}