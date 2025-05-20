//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    Unit units[MAX_UNITS];
    int num_units = 0;
    char input[100];
    double value, result;
    char from_unit[10], to_unit[10];

    units[num_units++] = (Unit) {"m", 1.0};
    units[num_units++] = (Unit) {"cm", 0.01};
    units[num_units++] = (Unit) {"mm", 0.001};
    units[num_units++] = (Unit) {"km", 1000.0};

    units[num_units++] = (Unit) {"kg", 1.0};
    units[num_units++] = (Unit) {"g", 0.001};

    units[num_units++] = (Unit) {"l", 1.0};
    units[num_units++] = (Unit) {"ml", 0.001};

    units[num_units++] = (Unit) {"s", 1.0};
    units[num_units++] = (Unit) {"ms", 0.001};

    while (1) {
        printf("Enter a value to convert or type 'exit' to quit: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        sscanf(input, "%lf %s -> %s", &value, from_unit, to_unit);

        for (int i = 0; i < num_units; i++) {
            if (strcmp(units[i].name, from_unit) == 0 && strcmp(units[i].name, to_unit)!= 0) {
                for (int j = i + 1; j < num_units; j++) {
                    if (strcmp(units[j].name, to_unit) == 0) {
                        result = value * units[i].factor / units[j].factor;
                        printf("%lf %s = %lf %s\n", value, from_unit, result, to_unit);
                        break;
                    }
                }
            }
        }
    }

    return 0;
}