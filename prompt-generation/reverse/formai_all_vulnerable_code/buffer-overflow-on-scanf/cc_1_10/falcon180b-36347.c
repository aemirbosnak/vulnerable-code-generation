//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} unit;

void print_units(unit *units, int n) {
    printf("Available units:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
}

int main() {
    unit units[MAX_UNITS] = {{"meters", 1.0}, {"kilometers", 1000.0}, {"centimeters", 0.01}, {"millimeters", 0.001}, {"inches", 0.0254}, {"feet", 0.3048}, {"yards", 0.9144}, {"miles", 160934.4}, {"pounds", 0.453592}, {"kilograms", 1.0}};
    int n_units = sizeof(units)/sizeof(units[0]);

    char input[100];
    double value, result;
    int from_unit, to_unit;

    while (1) {
        printf("Enter a value to convert: ");
        scanf("%lf", &value);

        printf("Enter the unit of the value: ");
        scanf("%s", input);

        from_unit = -1;
        for (int i = 0; i < n_units; i++) {
            if (strcmp(input, units[i].name) == 0) {
                from_unit = i;
                break;
            }
        }

        if (from_unit == -1) {
            printf("Invalid unit.\n");
            continue;
        }

        printf("Enter the unit to convert to: ");
        scanf("%s", input);

        to_unit = -1;
        for (int i = 0; i < n_units; i++) {
            if (strcmp(input, units[i].name) == 0) {
                to_unit = i;
                break;
            }
        }

        if (to_unit == -1) {
            printf("Invalid unit.\n");
            continue;
        }

        result = value * units[to_unit].factor / units[from_unit].factor;

        printf("%.2lf %s = %.2lf %s\n", value, units[from_unit].name, result, units[to_unit].name);
    }

    return 0;
}