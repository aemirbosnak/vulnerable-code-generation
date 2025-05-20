//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_VALUE 1000000000

struct unit {
    char name[20];
    double value;
};

int main() {
    struct unit units[MAX_UNITS] = {
        {"foot", 12},
        {"yard", 3},
        {"mile", 5280},
        {"inch", 1},
        {"pound", 16},
        {"ounce", 0.0625},
        {"gallon", 8},
        {"fluid_ounce", 0.035},
        {"cup", 0.08333333333333333},
        {"teaspoon", 0.0025}
    };

    int choice;
    double value;

    do {
        printf("Welcome to the Unit Converter!\n");
        printf("Choose a unit to convert from: ");
        scanf("%d", &choice);

        if (choice < 0 || choice >= MAX_UNITS) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        printf("Enter a value to convert: ");
        scanf("%lf", &value);

        for (int i = 0; i < MAX_UNITS; i++) {
            if (units[i].name == NULL) {
                continue;
            }

            if (value == units[i].value) {
                printf("The value %lf is equal to %s\n", value, units[i].name);
                break;
            }
        }
    } while (1);

    return 0;
}