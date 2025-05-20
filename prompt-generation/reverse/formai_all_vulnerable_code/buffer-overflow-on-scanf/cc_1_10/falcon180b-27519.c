//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: immersive
#include <stdio.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    Unit units[MAX_UNITS] = {
        {"m", 1},
        {"km", 1000},
        {"cm", 0.01},
        {"mm", 0.001},
        {"in", 0.0254},
        {"ft", 0.3048},
        {"yd", 0.9144},
        {"mi", 160934.4},
        {"l", 1},
        {"gal", 3.78541}
    };

    int num_units = sizeof(units) / sizeof(Unit);
    char input[20];
    char output[20];
    char from_unit[10], to_unit[10];
    double value;

    printf("Welcome to the Unit Converter!\n");
    printf("Enter the unit you want to convert from: ");
    scanf("%s", from_unit);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", to_unit);

    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            for (int j = 0; j < num_units; j++) {
                if (strcmp(units[j].name, to_unit) == 0) {
                    value *= units[j].factor;
                    sprintf(output, "%.2lf", value);
                    printf("%s %s = %s %s\n", value, from_unit, output, to_unit);
                    break;
                }
            }
        }
    }

    return 0;
}