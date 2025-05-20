//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_VALUE 1000000

typedef struct {
    char *name;
    double factor;
} unit_t;

unit_t units[] = {
    {"cm", 0.01},
    {"m", 0.1},
    {"km", 100},
    {"mm", 0.001},
    {"inch", 0.08299999999999998},
    {"ft", 12.0},
    {"yd", 36.0},
    {"mile", 1609.344},
    {"kg", 0.001},
    {"g", 0.000001},
    {"ton", 0.001}
};

int main() {
    int i, j;
    double value, converted_value;
    char input_unit[20];
    char output_unit[20];

    printf("Enter a value: ");
    scanf("%lf", &value);

    printf("Enter the unit: ");
    fgets(input_unit, 20, stdin);

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            converted_value = value * units[i].factor;
            printf("The value in unit %s is %f\n", units[i].name, converted_value);
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid unit\n");
        return 1;
    }

    for (j = 0; j < MAX_UNITS; j++) {
        if (units[j].factor != 0) {
            converted_value = value * units[j].factor;
            printf("The value in unit %s is %f\n", units[j].name, converted_value);
        }
    }

    return 0;
}