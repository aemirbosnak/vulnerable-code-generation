//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    Unit units[] = {
        {"m", 1},
        {"cm", 0.01},
        {"mm", 0.001},
        {"km", 1000},
        {"in", 0.0254},
        {"ft", 0.3048},
        {"yd", 0.9144},
        {"mi", 160934.4},
        {"kg", 1},
        {"g", 0.001},
        {"lb", 0.453592},
        {"oz", 0.0283495},
        {"l", 1},
        {"ml", 0.001},
        {"gal", 3.78541},
        {"fl oz", 0.0295735},
        {"C", 1},
        {"F", 1.8},
    };
    int num_units = sizeof(units) / sizeof(units[0]);
    char input[100];
    double value, result;
    int i;

    printf("Enter a value to convert:\n");
    scanf("%s", input);

    for (i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, input) == 0) {
            printf("%s = %.2f\n", units[i].name, value);
            break;
        }
    }

    while (1) {
        printf("Enter a unit to convert to:\n");
        scanf("%s", input);

        for (i = 0; i < num_units; i++) {
            if (strcmp(units[i].name, input) == 0) {
                result = value * units[i].factor;
                printf("%s = %.2f\n", input, result);
                break;
            }
        }
    }

    return 0;
}