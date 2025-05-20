//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    char input[100];
    char from_unit[20], to_unit[20];
    double value, result;
    Unit units[MAX_UNITS];
    int num_units = 0;

    // Initialize units
    units[num_units++] = (Unit) {"meters", 1.0};
    units[num_units++] = (Unit) {"centimeters", 0.01};
    units[num_units++] = (Unit) {"inches", 0.393701};
    units[num_units++] = (Unit) {"feet", 3.28084};
    units[num_units++] = (Unit) {"yards", 1.09361};
    units[num_units++] = (Unit) {"miles", 0.000621371};
    units[num_units++] = (Unit) {"kilograms", 1.0};
    units[num_units++] = (Unit) {"grams", 0.001};
    units[num_units++] = (Unit) {"ounces", 0.035274};
    units[num_units++] = (Unit) {"pounds", 0.453592};

    // Get user input
    printf("Enter a value to convert:\n");
    scanf("%lf", &value);

    printf("From unit:\n");
    scanf("%s", from_unit);

    printf("To unit:\n");
    scanf("%s", to_unit);

    // Convert value
    for (int i = 0; i < num_units; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            for (int j = 0; j < num_units; j++) {
                if (strcmp(to_unit, units[j].name) == 0) {
                    result = value * units[j].factor;
                    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);
                    return 0;
                }
            }
        }
    }

    printf("Invalid units.\n");

    return 0;
}