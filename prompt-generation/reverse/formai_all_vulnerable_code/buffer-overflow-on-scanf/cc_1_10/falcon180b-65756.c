//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 10

typedef struct {
    char symbol[5];
    double conversion_factor;
} Unit;

int main() {
    char input[100];
    char from_unit[5];
    char to_unit[5];
    double value;
    int i, j;

    Unit units[MAX_UNITS] = {
        {"m", 1.0},
        {"cm", 0.01},
        {"mm", 0.001},
        {"km", 1000.0},
        {"g", 1.0},
        {"kg", 1000.0},
        {"l", 1.0},
        {"ml", 0.001},
        {"dl", 0.01},
        {"cl", 0.1}
    };

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the value you want to convert: ");
    scanf("%lf", &value);

    printf("Please enter the unit you want to convert from: ");
    scanf("%s", from_unit);

    printf("Please enter the unit you want to convert to: ");
    scanf("%s", to_unit);

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].symbol) == 0) {
            for (j = 0; j < MAX_UNITS; j++) {
                if (strcmp(to_unit, units[j].symbol) == 0) {
                    printf("%.2lf %s = %.2lf %s\n", value, from_unit, value * units[i].conversion_factor / units[j].conversion_factor, to_unit);
                    break;
                }
            }
            break;
        }
    }

    return 0;
}