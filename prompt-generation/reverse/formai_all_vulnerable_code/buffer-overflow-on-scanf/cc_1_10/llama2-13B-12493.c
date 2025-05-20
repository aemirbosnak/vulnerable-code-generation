//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

struct unit {
    char name[20];
    double factor;
};

struct conversion {
    char from[20];
    char to[20];
    double factor;
};

int main() {
    struct unit units[MAX_UNITS] = {
        {"m", 1.0},
        {"cm", 0.01},
        {"mm", 0.001},
        {"km", 1000},
        {"mi", 1609.34},
        {"ft", 0.3048},
        {"in", 0.0254}
    };

    struct conversion conversions[MAX_CONVERSIONS] = {
        {"m", "cm", 0.01},
        {"cm", "mm", 0.001},
        {"mm", "km", 0.001},
        {"km", "mi", 0.621371},
        {"mi", "ft", 1609.34 / 12.0},
        {"ft", "in", 12.0 / 0.3048}
    };

    int choice;
    double value, converted_value;
    char input_unit[20], output_unit[20];

    do {
        printf("Welcome to the Unit Converter!\n");
        printf("Please enter a value (e.g. 100): ");
        scanf("%lf", &value);

        printf("Please enter the unit of the value (e.g. m): ");
        scanf("%19s", input_unit);

        for (int i = 0; i < MAX_UNITS; i++) {
            if (strcmp(input_unit, units[i].name) == 0) {
                converted_value = value * units[i].factor;
                break;
            }
        }

        for (int i = 0; i < MAX_CONVERSIONS; i++) {
            if (strcmp(input_unit, conversions[i].from) == 0) {
                converted_value = converted_value * conversions[i].factor;
                break;
            }
        }

        printf("The value in %s is %lf\n", output_unit, converted_value);

        printf("Would you like to convert again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}