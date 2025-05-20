//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 5
#define MAX_CONVERTIONS 5

typedef struct {
    char name[20];
    double factor;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12},
    {"yard", 36},
    {"mile", 5280},
    {"centimeter", 0.01}
};

int main() {
    int i, j;
    double conversion;
    char input[50];

    printf("Welcome to the Unit Converter!\n");

    while (1) {
        printf("Enter a unit to convert (e.g. 'inch', 'foot', etc.): ");
        fgets(input, 50, stdin);

        for (i = 0; i < MAX_UNITS; i++) {
            if (strcmp(input, units[i].name) == 0) {
                break;
            }
        }

        if (i == MAX_UNITS) {
            printf("Invalid unit. Please try again.\n");
            continue;
        }

        printf("Enter a value to convert (e.g. '5 foot'): ");
        double value = strtod(input, NULL);

        for (j = 0; j < MAX_CONVERTIONS; j++) {
            conversion = value * units[i].factor / units[j].factor;
            printf("Conversion: %c%s = %f %c%s\n",
                   units[i].name[0] == 'c' ? 'C' : 'c',
                   units[i].name, conversion,
                   units[j].name[0] == 'c' ? 'C' : 'c',
                   units[j].name);
        }
    }

    return 0;
}