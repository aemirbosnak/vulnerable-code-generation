//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_UNITS 20

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[MAX_UNITS];

int num_units = 0;

void add_unit(char *name, double factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }

    units[num_units].name = strdup(name);
    units[num_units].factor = factor;

    num_units++;
}

void print_units() {
    printf("Available units:\n");

    for (int i = 0; i < num_units; i++) {
        printf("%s (%c)\n", units[i].name, i + 65);
    }
}

void convert(double value, char from_unit, char to_unit) {
    for (int i = 0; i < num_units; i++) {
        if (units[i].name[0] == to_unit) {
            double factor = units[i].factor;

            if (from_unit == to_unit) {
                printf("1 %c = 1 %c\n", from_unit, to_unit);
            } else {
                for (int j = 0; j < num_units; j++) {
                    if (units[j].name[0] == from_unit) {
                        factor *= units[j].factor;
                        break;
                    }
                }

                printf("%f %c = %f %c\n", value, from_unit, value * factor, to_unit);
            }

            return;
        }
    }

    printf("Error: Unit conversion not possible.\n");
}

int main() {
    add_unit("meters", 1.0);
    add_unit("kilometers", 1000.0);
    add_unit("grams", 1.0);
    add_unit("kilograms", 1000.0);
    add_unit("liters", 1.0);
    add_unit("milliliters", 0.001);
    add_unit("seconds", 1.0);
    add_unit("minutes", 60.0);
    add_unit("hours", 3600.0);

    print_units();

    double value;
    char from_unit, to_unit;

    printf("Enter a value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit of the value: ");
    scanf(" %c", &from_unit);

    printf("Enter the unit to convert to: ");
    scanf(" %c", &to_unit);

    convert(value, from_unit, to_unit);

    return 0;
}