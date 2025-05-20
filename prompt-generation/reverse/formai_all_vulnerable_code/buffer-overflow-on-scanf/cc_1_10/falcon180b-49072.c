//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 100

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    Unit units[MAX_UNITS];
    int num_units = 0;

    units[num_units++] = (Unit) {"meter", 1.0};
    units[num_units++] = (Unit) {"centimeter", 0.01};
    units[num_units++] = (Unit) {"kilometer", 1000.0};

    char input[100];
    while (1) {
        printf("Enter a value to convert: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        int i;
        for (i = 0; i < num_units; i++) {
            if (strcmp(units[i].name, input) == 0) {
                break;
            }
        }

        if (i == num_units) {
            printf("Invalid unit.\n");
            continue;
        }

        printf("Enter the value to convert from: ");
        scanf("%s", input);

        int j;
        for (j = 0; j < num_units; j++) {
            if (strcmp(units[j].name, input) == 0) {
                break;
            }
        }

        if (j == num_units) {
            printf("Invalid unit.\n");
            continue;
        }

        double value = strtod(input, NULL);
        double result = value * units[i].factor / units[j].factor;

        printf("Result: %.2f %s = %.2f %s\n", value, units[j].name, result, units[i].name);
    }

    return 0;
}