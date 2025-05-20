//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    int choice, num_units = 0;
    char input[100];
    Unit units[MAX_UNITS];

    units[num_units++] = (Unit) {"m", 1.0};
    units[num_units++] = (Unit) {"cm", 0.01};
    units[num_units++] = (Unit) {"mm", 0.001};
    units[num_units++] = (Unit) {"in", 0.0254};
    units[num_units++] = (Unit) {"ft", 0.3048};
    units[num_units++] = (Unit) {"yd", 0.9144};
    units[num_units++] = (Unit) {"mi", 160934.4};
    units[num_units++] = (Unit) {"kg", 1.0};
    units[num_units++] = (Unit) {"g", 0.001};
    units[num_units++] = (Unit) {"lb", 0.453592};

    printf("Select a unit to convert from:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }

    scanf("%d", &choice);

    printf("Enter a value to convert: ");
    scanf("%s", input);

    double value = atof(input);

    printf("Select a unit to convert to:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }

    scanf("%d", &choice);

    double result = value * units[choice-1].factor;

    printf("%.2f %s = %.2f %s\n", value, units[choice-1].name, result, units[0].name);

    return 0;
}