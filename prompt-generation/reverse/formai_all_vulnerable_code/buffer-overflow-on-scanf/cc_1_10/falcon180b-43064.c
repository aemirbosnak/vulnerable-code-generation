//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

struct unit {
    char *name;
    char *abbreviation;
    double factor;
};

int main() {
    struct unit units[MAX_UNITS] = {{"meter", "m", 1.0},
                                     {"kilometer", "km", 1000.0},
                                     {"gram", "g", 1.0},
                                     {"kilogram", "kg", 1000.0},
                                     {"liter", "l", 1.0},
                                     {"milliliter", "ml", 0.001},
                                     {"second", "s", 1.0},
                                     {"minute", "min", 60.0},
                                     {"hour", "h", 3600.0},
                                     {"day", "d", 86400.0}};

    int num_units = sizeof(units) / sizeof(struct unit);
    char input_unit[50], output_unit[50];
    double input_value, output_value;

    printf("Enter the unit to convert from: ");
    scanf("%s", input_unit);
    printf("Enter the unit to convert to: ");
    scanf("%s", output_unit);
    printf("Enter the value to convert: ");
    scanf("%lf", &input_value);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].abbreviation, input_unit) == 0) {
            for (int j = 0; j < num_units; j++) {
                if (strcmp(units[j].abbreviation, output_unit) == 0) {
                    output_value = input_value * units[i].factor / units[j].factor;
                    printf("%.2lf %s = %.2lf %s\n", input_value, input_unit, output_value, output_unit);
                    return 0;
                }
            }
        }
    }

    printf("Invalid input units or output units.\n");
    return 1;
}