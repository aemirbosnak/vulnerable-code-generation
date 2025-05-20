//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct {
    char name[50];
    double value;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12},
    {"yard", 36},
    {"mile", 1760},
    {"centimeter", 0.01},
    {"meter", 100},
    {"kilometer", 100000},
    {"gram", 0.001},
    {"kilogram", 1000},
    {"ounce", 0.0283495},
    {"pound", 453.592}
};

void print_units(void) {
    int i;
    for (i = 0; i < MAX_UNITS; i++) {
        printf("%d. %s (%f)\n", i + 1, units[i].name, units[i].value);
    }
}

void convert_units(double value, char from_unit[50], char to_unit[50]) {
    int from_index = -1, to_index = -1;
    double conversion_factor = 1;

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            from_index = i;
        } else if (strcmp(to_unit, units[i].name) == 0) {
            to_index = i;
        }
    }

    if (from_index == -1 || to_index == -1) {
        printf("Invalid unit\n");
        return;
    }

    conversion_factor = units[to_index].value / units[from_index].value;

    printf("Conversion factor: %f\n", conversion_factor);

    double converted_value = value * conversion_factor;

    printf("Converted value: %f %s\n", converted_value, to_unit);
}

int main(void) {
    int choice;
    double value;
    char from_unit[50];
    char to_unit[50];

    do {
        printf("1. Convert value from one unit to another\n");
        printf("2. Print all units\n");
        printf("3. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%lf", &value);

                printf("Enter from unit (%s): ", "");
                fgets(from_unit, 50, stdin);

                printf("Enter to unit (%s): ", "");
                fgets(to_unit, 50, stdin);

                convert_units(value, from_unit, to_unit);
                break;

            case 2:
                print_units();
                break;

            case 3:
                printf("Quitting...\n");
                break;
        }
    } while (choice != 3);

    return 0;
}