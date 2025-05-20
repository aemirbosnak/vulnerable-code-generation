//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LENGTH 100
#define MAX_UNITS 4

typedef struct {
    char* name;
    float multiplier;
} Unit;

Unit units[MAX_UNITS] = {
    {"meter", 1.0},
    {"centimeter", 0.01},
    {"millimeter", 0.001},
    {"kilometer", 1000.0}
};

void convert(float value, char* from, char* to) {
    int from_index = get_unit_index(from);
    int to_index = get_unit_index(to);

    if (from_index == -1 || to_index == -1) {
        printf("Invalid unit\n");
        return;
    }

    float from_multiplier = units[from_index].multiplier;
    float to_multiplier = units[to_index].multiplier;

    float converted_value = value * (to_multiplier / from_multiplier);

    printf("%.2f %s = %.2f %s\n", value, from, converted_value, to);
}

int get_unit_index(char* unit) {
    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, unit) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    float value;
    char from[MAX_LENGTH];
    char to[MAX_LENGTH];

    printf("Enter a value: ");
    scanf("%f", &value);

    printf("Enter the unit of the value (e.g. meter, centimeter, millimeter, kilometer): ");
    scanf("%s", from);

    printf("Enter the unit to convert to (e.g. meter, centimeter, millimeter, kilometer): ");
    scanf("%s", to);

    convert(value, from, to);

    return 0;
}