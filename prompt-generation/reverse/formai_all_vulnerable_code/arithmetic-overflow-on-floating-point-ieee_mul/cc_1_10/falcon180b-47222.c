//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    Unit units[MAX_UNITS];
    int num_units = 0;
    char input[1024];
    char *token;
    int i;

    units[num_units].name = "meters";
    units[num_units].factor = 1.0;
    num_units++;

    units[num_units].name = "kilometers";
    units[num_units].factor = 1000.0;
    num_units++;

    units[num_units].name = "miles";
    units[num_units].factor = 1609.34;
    num_units++;

    units[num_units].name = "yards";
    units[num_units].factor = 0.9144;
    num_units++;

    units[num_units].name = "feet";
    units[num_units].factor = 0.3048;
    num_units++;

    units[num_units].name = "inches";
    units[num_units].factor = 0.0254;
    num_units++;

    units[num_units].name = "centimeters";
    units[num_units].factor = 0.01;
    num_units++;

    units[num_units].name = "millimeters";
    units[num_units].factor = 0.001;
    num_units++;

    printf("Enter a value to convert:\n");
    fgets(input, sizeof(input), stdin);

    token = strtok(input, " ");
    if (token == NULL) {
        printf("Invalid input.\n");
        return 1;
    }

    for (i = 0; i < num_units; i++) {
        if (strcmp(token, units[i].name) == 0) {
            printf("Converting from %s...\n", units[i].name);
            break;
        }
    }

    if (i == num_units) {
        printf("Invalid unit.\n");
        return 1;
    }

    token = strtok(NULL, " ");
    if (token == NULL) {
        printf("Invalid input.\n");
        return 1;
    }

    double value = atof(token);
    double result = value * units[i].factor;

    printf("%.2f %s = %.2f %s\n", value, units[i].name, result, units[0].name);

    return 0;
}