//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_UNITS 10

typedef struct {
    char name[20];
    double factor;
} Unit;

Unit units[MAX_UNITS] = {
    {"meters", 1.0},
    {"kilometers", 1000.0},
    {"centimeters", 0.01},
    {"millimeters", 0.001},
    {"inches", 0.0254},
    {"feet", 0.3048},
    {"yards", 0.9144},
    {"miles", 160934.4},
    {"pounds", 0.453592},
    {"kilograms", 2.20462}
};

int main() {
    int choice, num_units;
    char input[50];
    double value, result = 0.0;
    bool valid_input = true;

    printf("Welcome to the Unit Converter!\n");
    printf("Please select a unit of measurement:\n");

    for (int i = 0; i < MAX_UNITS; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }

    scanf("%d", &choice);

    printf("Enter a value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit you want to convert %lf %s to:\n", value, units[choice-1].name);
    scanf("%s", input);

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input, units[i].name) == 0) {
            result = value * units[i].factor;
            break;
        }
    }

    if (result == 0.0) {
        printf("Invalid unit of measurement.\n");
        valid_input = false;
    }

    if (valid_input) {
        printf("%.2lf %s is equal to %.2lf %s.\n", value, input, result, units[choice-1].name);
    }

    return 0;
}