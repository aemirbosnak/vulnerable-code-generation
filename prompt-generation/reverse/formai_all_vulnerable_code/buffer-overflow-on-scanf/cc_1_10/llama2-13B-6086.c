//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define UNIT_CONVERTER_MAX_LENGTH 20
#define UNIT_CONVERTER_DEFAULT_UNIT "cm"

struct unit_converter {
    char name[UNIT_CONVERTER_MAX_LENGTH];
    double value;
};

struct unit_converter units[] = {
    {"cm", 100},
    {"m", 1000},
    {"km", 1000000},
    {"mm", 1},
    {"inch", 2.54},
    {"ft", 12},
    {"yd", 36},
    {"mile", 1609.344},
    {"pt", 0.0254},
    {"px", 0.000254},
    {"deg", 0.0174532925199432957}
};

int main() {
    int choice;
    char input_unit[UNIT_CONVERTER_MAX_LENGTH];
    char output_unit[UNIT_CONVERTER_MAX_LENGTH];
    double value;

    printf("Welcome to the Unit Converter!\n");

    while (1) {
        printf("Select a unit to convert: ");
        fgets(input_unit, UNIT_CONVERTER_MAX_LENGTH, stdin);

        for (int i = 0; i < sizeof(units) / sizeof(struct unit_converter); i++) {
            if (strcmp(input_unit, units[i].name) == 0) {
                value = units[i].value;
                break;
            }
        }

        if (value == 0) {
            printf("Invalid unit selected. Please try again.\n");
            continue;
        }

        printf("Enter the value to convert: ");
        scanf("%lf", &value);

        for (int i = 0; i < sizeof(units) / sizeof(struct unit_converter); i++) {
            if (units[i].value == value) {
                strcpy(output_unit, units[i].name);
                break;
            }
        }

        if (output_unit[0] == '\0') {
            printf("Invalid value. Please try again.\n");
            continue;
        }

        printf("Value in %s is %g\n", output_unit, value);
        printf("Enter a new unit to convert (type 'q' to quit): ");
    }

    return 0;
}