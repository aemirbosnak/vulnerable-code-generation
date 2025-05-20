//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    Unit units[MAX_UNITS];
    int num_units;
    char input_unit[20];
    char output_unit[20];
    double value;

    // Initialize units
    units[0].name = "meter";
    units[0].factor = 1.0;

    units[1].name = "kilometer";
    units[1].factor = 1000.0;

    units[2].name = "gram";
    units[2].factor = 1.0;

    units[3].name = "kilogram";
    units[3].factor = 1000.0;

    units[4].name = "liter";
    units[4].factor = 1.0;

    units[5].name = "milliliter";
    units[5].factor = 0.001;

    units[6].name = "second";
    units[6].factor = 1.0;

    units[7].name = "minute";
    units[7].factor = 60.0;

    units[8].name = "hour";
    units[8].factor = 3600.0;

    units[9].name = "degree Celsius";
    units[9].factor = 1.0;

    // Get number of units from user
    printf("Enter the number of units: ");
    scanf("%d", &num_units);

    // Get input and output units from user
    printf("Enter the input unit: ");
    scanf("%s", input_unit);

    printf("Enter the output unit: ");
    scanf("%s", output_unit);

    // Convert value
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            for (int j = 0; j < num_units; j++) {
                if (strcmp(output_unit, units[j].name) == 0) {
                    printf("%.2lf %s = %.2lf %s\n", value, input_unit, value * units[i].factor / units[j].factor, output_unit);
                    break;
                }
            }
            break;
        }
    }

    return 0;
}