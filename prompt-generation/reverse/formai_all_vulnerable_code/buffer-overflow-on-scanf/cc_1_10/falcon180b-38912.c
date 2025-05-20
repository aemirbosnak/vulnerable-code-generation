//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    Unit units[MAX_UNITS];
    int num_units = 0;
    char input[100];

    units[num_units++] = (Unit) {"meters", 1.0};
    units[num_units++] = (Unit) {"centimeters", 0.01};
    units[num_units++] = (Unit) {"inches", 0.0393701};
    units[num_units++] = (Unit) {"feet", 0.3048};
    units[num_units++] = (Unit) {"yards", 0.9144};
    units[num_units++] = (Unit) {"miles", 160934.4};
    units[num_units++] = (Unit) {"kilograms", 1.0};
    units[num_units++] = (Unit) {"grams", 0.001};
    units[num_units++] = (Unit) {"ounces", 0.035274};
    units[num_units++] = (Unit) {"pounds", 0.453592};

    printf("Enter the value to convert:\n");
    scanf("%s", input);

    printf("Enter the unit of measurement:\n");
    scanf("%s", input);

    int i;
    for (i = 0; i < num_units; i++) {
        if (strcmp(input, units[i].name) == 0) {
            break;
        }
    }

    if (i == num_units) {
        printf("Invalid unit of measurement.\n");
        return 1;
    }

    double value = atof(input);
    double result = value * units[i].factor;

    printf("%.2f %s = %.2f %s\n", value, input, result, units[i].name);

    return 0;
}