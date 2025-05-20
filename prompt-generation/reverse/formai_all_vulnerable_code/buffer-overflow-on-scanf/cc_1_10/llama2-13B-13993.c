//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

struct unit {
    char name[20];
    double conversion_factor;
};

int main() {
    struct unit units[MAX_UNITS] = {
        {"inch", 2.54},
        {"foot", 12 * 2.54},
        {"yard", 3 * 2.54},
        {"mile", 5280 * 2.54},
        {"pound", 0.453592},
        {"ounce", 0.0283495},
        {"fluid_ounce", 0.0236588},
        {"gallon", 0.264172},
        {"teaspoon", 0.0625},
        {"tablespoon", 0.375}
    };

    char input_unit[20];
    double input_value;
    char output_unit[20];

    printf("Welcome to the Unit Converter!\n");

    while (1) {
        printf("Enter a value: ");
        scanf("%lf", &input_value);

        printf("Enter the unit you want to convert from (e.g. 'inch'): ");
        fgets(input_unit, 20, stdin);

        for (int i = 0; i < MAX_UNITS; i++) {
            if (strcmp(units[i].name, input_unit) == 0) {
                double conversion_factor = units[i].conversion_factor;
                double output_value = input_value * conversion_factor;

                printf("The value in %s is %lf\n", units[i].name, output_value);

                break;
            }
        }

        if (input_unit[0] == '\0') {
            printf("Invalid unit. Please try again.\n");
        }
    }

    return 0;
}