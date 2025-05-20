//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    double factor;
} unit_t;

int main(void) {
    unit_t units[] = {
        {"m", 1.0},
        {"km", 1000.0},
        {"cm", 0.01},
        {"mm", 0.001},
        {"in", 0.0254},
        {"ft", 0.3048},
        {"yd", 0.9144},
        {"mi", 160934.4},
        {"l", 1.0},
        {"ml", 0.001},
        {"dl", 0.01},
        {"cl", 0.0001},
        {"gal", 3.78541},
        {"fl oz", 0.000264172},
        {"c", 1.0},
        {"f", 1.8},
        {"k", -273.15},
        {"celsius", 0.0},
        {"fahrenheit", 32.0},
        {"kelvin", 0.0},
        {NULL, 0.0}
    };
    char input[50], unit[50];
    double value, result;
    int i;

    printf("Welcome to the Unit Converter!\n");
    printf("Enter a value and its unit (e.g. 10.5 m): ");
    scanf("%s %s", input, unit);

    for (i = 0; units[i].name!= NULL; i++) {
        if (strcmp(unit, units[i].name) == 0) {
            value = atof(input);
            result = value * units[i].factor;
            printf("%.2f %s = %.2f %s\n", value, unit, result, units[i+1].name);
            break;
        }
    }

    return 0;
}