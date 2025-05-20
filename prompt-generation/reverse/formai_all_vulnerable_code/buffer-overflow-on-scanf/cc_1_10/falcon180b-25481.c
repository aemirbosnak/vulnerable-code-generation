//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000.0},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 160934.4},
    {"l", 1.0},
    {"ml", 0.001},
    {"cl", 0.01},
    {"dl", 0.1},
    {"fl oz", 0.0295735},
    {"gal", 3.78541},
    {"kg", 1.0},
    {"g", 0.001},
    {"lb", 0.453592},
    {"oz", 0.0283495},
    {"C", 1.0},
    {"F", 1.8},
    {"K", 1.0}
};

int main() {
    int num_units, i, j;
    char input[100], unit_str[10];
    double value, result = 0.0;

    printf("Enter the number of units to convert: ");
    scanf("%d", &num_units);

    for (i = 0; i < num_units; i++) {
        printf("Enter the value to convert: ");
        scanf("%lf", &value);

        printf("Enter the unit of the value: ");
        scanf("%s", input);

        for (j = 0; j < 21; j++) {
            if (strcmp(input, units[j].name) == 0) {
                result = value * units[j].factor;
                break;
            }
        }

        if (j == 21) {
            printf("Invalid unit!\n");
            return 1;
        }

        printf("The converted value is: %.2lf %s\n", result, units[j].name);
    }

    return 0;
}