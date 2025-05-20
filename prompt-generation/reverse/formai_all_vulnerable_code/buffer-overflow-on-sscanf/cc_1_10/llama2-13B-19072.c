//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

struct unit {
    const char *name;
    double factor;
};

struct unit units[] = {
    {"cm", 1.0},
    {"m", 100.0},
    {"km", 100000.0},
    {"mm", 0.1},
    {"mi", 1609.34},
    {"yd", 0.9144},
    {"ft", 12.0},
    {"in", 0.0254},
    {"pt", 0.0001},
    {"px", 0.000001}
};

int main() {
    char input[100];
    double value, converted_value;
    int i;

    printf("Enter a value: ");
    fgets(input, 100, stdin);

    // Parse the input string to extract the value
    sscanf(input, "%lf", &value);

    // Loop through the list of units to find the best match
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, input) == 0) {
            converted_value = value * units[i].factor;
            printf("The value of %s is %f\n", units[i].name, converted_value);
            break;
        }
    }

    // If no match is found, print an error message
    if (i == MAX_UNITS) {
        printf("Invalid unit: %s\n", input);
    }

    return 0;
}