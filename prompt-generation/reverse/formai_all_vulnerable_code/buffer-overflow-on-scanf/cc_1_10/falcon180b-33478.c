//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_UNITS 10

struct unit_conversion {
    char *name;
    double factor;
};

int main() {
    char input[100];
    char unit_name[20];
    int i;
    double value, result;
    struct unit_conversion units[MAX_UNITS];
    int num_units;

    // Initialize unit conversion table
    units[0] = (struct unit_conversion) {"meters", 1.0};
    units[1] = (struct unit_conversion) {"centimeters", 0.01};
    units[2] = (struct unit_conversion) {"inches", 0.393701};
    units[3] = (struct unit_conversion) {"feet", 3.28084};
    units[4] = (struct unit_conversion) {"yards", 1.09361};
    units[5] = (struct unit_conversion) {"miles", 0.000621371};
    units[6] = (struct unit_conversion) {"kilograms", 1.0};
    units[7] = (struct unit_conversion) {"grams", 0.001};
    units[8] = (struct unit_conversion) {"ounces", 0.035274};
    units[9] = (struct unit_conversion) {"pounds", 2.20462};

    num_units = 10;

    // Prompt user for input
    printf("Enter a value to convert:\n");
    scanf("%s", input);

    // Prompt user for desired unit
    printf("Enter the desired unit (e.g. meters, kilograms):\n");
    scanf("%s", unit_name);

    // Find the corresponding unit in the conversion table
    for (i = 0; i < num_units; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            break;
        }
    }

    // Convert the input value to the desired unit
    if (i == num_units) {
        printf("Invalid unit.\n");
        return 1;
    } else {
        value = atof(input);
        result = value * units[i].factor;
        printf("%.2f %s = %.2f %s\n", value, unit_name, result, units[i].name);
    }

    return 0;
}