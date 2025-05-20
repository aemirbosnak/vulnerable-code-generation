//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_UNITS 8

typedef struct {
    char *name;
    double factor;
} Unit;

void print_units(Unit units[]) {
    printf("Available units:\n");
    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%s\n", units[i].name);
    }
}

int main() {
    Unit units[NUM_UNITS] = {{"meters", 1}, {"feet", 3.28084}, {"inches", 39.3701}, {"kilograms", 1}, {"pounds", 2.20462}, {"grams", 0.001}, {"gallons", 3.78541}, {"liters", 1}};
    char input[100];
    double value, result;
    int choice;

    printf("Enter a value to convert:\n");
    scanf("%lf", &value);

    printf("Enter the unit of the value:\n");
    scanf("%s", input);

    printf("Enter the unit to convert to:\n");
    scanf("%s", input);

    choice = -1;
    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(input, units[i].name) == 0) {
            choice = i;
            break;
        }
    }

    if (choice == -1) {
        printf("Invalid unit.\n");
        return 1;
    }

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(input, units[i].name) == 0) {
            result = value / units[choice].factor;
            printf("%.2lf %s = %.2lf %s\n", value, units[i].name, result, units[choice].name);
            break;
        }
    }

    return 0;
}