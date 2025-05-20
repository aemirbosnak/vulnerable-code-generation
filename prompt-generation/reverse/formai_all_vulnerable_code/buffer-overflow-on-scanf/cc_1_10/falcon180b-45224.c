//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[MAX_UNITS] = {
    {"m", 1.0},
    {"km", 1000.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 160934.4},
    {"gal", 3.78541},
    {"l", 0.264172}
};

int main() {
    char input[100];
    char output[100];
    char from_unit[10], to_unit[10];
    double value, result;

    printf("Enter the value to convert:\n");
    scanf("%s", input);

    printf("Enter the unit of the value:\n");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to:\n");
    scanf("%s", to_unit);

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            value = atof(input);
            for (int j = 0; j < MAX_UNITS; j++) {
                if (strcmp(to_unit, units[j].name) == 0) {
                    result = value * units[j].factor;
                    sprintf(output, "%.2f %s = %.2f %s", value, from_unit, result, to_unit);
                    printf("%s\n", output);
                    break;
                }
            }
            break;
        }
    }

    return 0;
}