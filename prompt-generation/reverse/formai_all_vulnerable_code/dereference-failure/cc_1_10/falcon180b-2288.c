//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 20

struct unit_conversion {
    char *name;
    double factor;
};

struct unit_conversion units[MAX_UNITS];

int add_unit(char *name, double factor) {
    int i;

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, name) == 0) {
            return -1; // unit already exists
        }
    }

    strcpy(units[MAX_UNITS - 1].name, name);
    units[MAX_UNITS - 1].factor = factor;

    return 0;
}

int main() {
    char input[100];
    char from_unit[20], to_unit[20];
    double value, result;
    int i, j;

    printf("Welcome to the Unit Converter!\n");

    // add some default units
    add_unit("meter", 1.0);
    add_unit("kilometer", 1000.0);
    add_unit("gram", 1.0);
    add_unit("kilogram", 1000.0);
    add_unit("liter", 1.0);
    add_unit("milliliter", 0.001);
    add_unit("second", 1.0);
    add_unit("minute", 60.0);
    add_unit("hour", 3600.0);

    while (1) {
        printf("Enter a value to convert, followed by the original unit and desired unit (e.g. 10 meter to kilometer):\n");
        scanf("%s %s %s", input, from_unit, to_unit);

        value = atof(input);

        for (i = 0; i < MAX_UNITS; i++) {
            if (strcmp(from_unit, units[i].name) == 0) {
                for (j = 0; j < MAX_UNITS; j++) {
                    if (strcmp(to_unit, units[j].name) == 0) {
                        result = value * units[i].factor / units[j].factor;
                        printf("%s %s is %s %s\n", input, from_unit, to_unit, result < 1? "less than" : "greater than or equal to");
                        break;
                    }
                }

                if (j == MAX_UNITS) {
                    printf("Invalid unit '%s'\n", to_unit);
                }

                break;
            }
        }
    }

    return 0;
}