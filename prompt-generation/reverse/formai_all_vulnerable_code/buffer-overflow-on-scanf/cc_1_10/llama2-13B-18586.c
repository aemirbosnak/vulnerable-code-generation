//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159
#define INF 1e30

struct unit {
    char name[20];
    double factor;
};

typedef struct unit Unit;

Unit units[] = {
    {"m", 1},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"mi", 1609.34},
    {"ft", 0.3048},
    {"in", 0.0254},
    {"yd", 0.9144},
    {"lb", 0.453592},
    {"oz", 0.0283495},
    {"g", 0.001},
    {"kg", 1000},
    {"ton", 1000000},
    {"hr", 3600},
    {"min", 60},
    {"sec", 1},
    {"mph", 1609.34 / 3600},
    {"kmh", 1000 / 3600},
    {"ft/s", 3280.84 / 3600},
    {"in/s", 0.254 / 3600},
    {"yd/s", 3.28084 / 3600},
    {"lb/s", 0.453592 / 3600},
    {"oz/s", 0.0283495 / 3600},
    {"g/s", 0.001 / 3600},
    {"kg/s", 1000 / 3600},
    {"ton/s", 1000000 / 3600},
};

int main() {
    int i, j;
    char input[100];
    double value, conversion_factor;

    printf("Welcome to the Unit Converter!\n");

    // Initialize user input
    printf("Enter the value you want to convert: ");
    fgets(input, 100, stdin);

    // Convert string to double
    value = atof(input);

    // Find the unit of the input value
    for (i = 0; i < sizeof(units) / sizeof(units[0]); i++) {
        if (strcmp(input, units[i].name) == 0) {
            conversion_factor = units[i].factor;
            break;
        }
    }

    // Print the conversion
    printf("The value of %s is %f %s\n", input, value / conversion_factor, units[i].name);

    // Ask user for another conversion
    printf("Do you want to convert another value? (y/n): ");
    scanf(" %c", &j);

    if (j == 'y') {
        // Repeat the conversion process
        main();
    } else {
        printf("Goodbye!\n");
    }

    return 0;
}