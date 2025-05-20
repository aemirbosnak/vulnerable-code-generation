//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} unit;

unit units[MAX_UNITS] = {
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
    char input[50];
    char output_unit[10];
    double value, result;
    int i, j;

    printf("Enter the value to convert:\n");
    scanf("%lf", &value);

    printf("Enter the input unit:\n");
    scanf("%s", input);

    printf("Enter the output unit:\n");
    scanf("%s", output_unit);

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, input) == 0) {
            for (j = 0; j < MAX_UNITS; j++) {
                if (strcmp(units[j].name, output_unit) == 0) {
                    result = value * units[i].factor / units[j].factor;
                    printf("%.2lf %s = %.2lf %s\n", value, input, result, output_unit);
                    return 0;
                }
            }
        }
    }

    printf("Invalid input or output unit.\n");

    return 0;
}