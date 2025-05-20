//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define NUM_UNITS 7

typedef struct {
    char *name;
    double factor;
} unit;

unit units[NUM_UNITS] = {
    {"meters", 1.0},
    {"feet", 0.3048},
    {"inches", 0.0254},
    {"kilograms", 1.0},
    {"pounds", 2.20462},
    {"liters", 1.0},
    {"gallons", 3.78541}
};

int main() {
    int choice;
    double value, result;
    char unit_name[20];

    printf("Welcome to the Unit Converter!\n");
    printf("Select a unit to convert from:\n");

    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }

    scanf("%d", &choice);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Select a unit to convert to:\n");

    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }

    scanf("%d", &choice);

    printf("Enter the name of the unit: ");
    scanf("%s", unit_name);

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            result = value * units[i].factor;
            printf("%.2lf %s = %.2lf %s\n", value, units[choice-1].name, result, units[i].name);
            break;
        }
    }

    return 0;
}