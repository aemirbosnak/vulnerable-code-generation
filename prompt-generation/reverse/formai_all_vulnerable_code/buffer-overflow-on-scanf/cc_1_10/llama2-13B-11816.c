//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_UNITS 10

struct unit {
    char name[20];
    int conversion_factor;
};

struct unit units[MAX_UNITS] = {
    {"inch", 1},
    {"foot", 12},
    {"yard", 36},
    {"mile", 5280},
    {"pound", 16},
    {"ounce", 16 / 128},
    {"gram", 16 / 1000},
    {"kilogram", 1000},
    {"meter", 39.37},
    {"centimeter", 39.37 / 100}
};

int main() {
    int choice;
    double value;
    char input_unit[20];
    char output_unit[20];

    do {
        printf("Welcome to the Unit Converter! \n");
        printf("Choose a unit to convert from: ");
        scanf("%s", input_unit);

        for (int i = 0; i < MAX_UNITS; i++) {
            if (strcmp(input_unit, units[i].name) == 0) {
                choice = i;
                break;
            }
        }

        printf("Enter a value to convert: ");
        scanf("%lf", &value);

        for (int i = 0; i < MAX_UNITS; i++) {
            if (choice == i) {
                sprintf(output_unit, "%s%.*g", units[i].name, (int)log10(value), value * units[i].conversion_factor);
                break;
            }
        }

        printf("The value is %s%.*g%s\n", output_unit, (int)log10(value), value * units[choice].conversion_factor, units[choice].name);
    } while (1);

    return 0;
}