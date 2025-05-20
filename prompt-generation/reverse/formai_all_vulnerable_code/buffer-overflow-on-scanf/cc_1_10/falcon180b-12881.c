//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    float factor;
} Unit;

int main() {
    char input[100], output[100];
    char *endptr;
    Unit units[MAX_UNITS];
    int num_units = 0;

    // Initialize units
    units[num_units++] = (Unit) {"m", 1.0};
    units[num_units++] = (Unit) {"km", 1000.0};
    units[num_units++] = (Unit) {"cm", 0.01};
    units[num_units++] = (Unit) {"mm", 0.001};
    units[num_units++] = (Unit) {"in", 0.0254};
    units[num_units++] = (Unit) {"ft", 0.3048};
    units[num_units++] = (Unit) {"yd", 0.9144};
    units[num_units++] = (Unit) {"mi", 160934.4};
    units[num_units++] = (Unit) {"gal", 3.78541};
    units[num_units++] = (Unit) {"l", 0.264172};

    printf("Enter a value to convert:\n");
    scanf("%s", input);

    printf("Enter the input unit:\n");
    scanf("%s", input);

    printf("Enter the output unit:\n");
    scanf("%s", output);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(input, units[i].name) == 0) {
            float result = (float)atof(input) * units[i].factor;
            printf("%.2f %s is equal to %.2f %s\n", atof(input), units[i].name, result, output);
            return 0;
        }
    }

    printf("Invalid input unit\n");
    return 1;
}