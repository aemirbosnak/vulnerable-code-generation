//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: careful
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
    char input_buffer[100];
    char *token;
    double value, result = 0;
    char from_unit[10], to_unit[10];

    // Initialize units
    units[num_units++] = (Unit) {"m", 1.0};
    units[num_units++] = (Unit) {"cm", 0.01};
    units[num_units++] = (Unit) {"in", 0.393701};
    units[num_units++] = (Unit) {"ft", 3.28084};
    units[num_units++] = (Unit) {"yd", 1.09361};
    units[num_units++] = (Unit) {"mi", 160934.4};
    units[num_units++] = (Unit) {"kg", 1.0};
    units[num_units++] = (Unit) {"g", 0.001};
    units[num_units++] = (Unit) {"lb", 0.453592};
    units[num_units++] = (Unit) {"oz", 0.0283495};

    printf("Enter the value to convert: ");
    fgets(input_buffer, 100, stdin);
    token = strtok(input_buffer, " ");
    sscanf(token, "%lf", &value);

    printf("Enter the from unit: ");
    fgets(input_buffer, 100, stdin);
    strcpy(from_unit, input_buffer);

    printf("Enter the to unit: ");
    fgets(input_buffer, 100, stdin);
    strcpy(to_unit, input_buffer);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            for (int j = 0; j < num_units; j++) {
                if (strcmp(to_unit, units[j].name) == 0) {
                    result = value * units[j].factor;
                    printf("Result: %.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);
                    break;
                }
            }
            break;
        }
    }

    return 0;
}