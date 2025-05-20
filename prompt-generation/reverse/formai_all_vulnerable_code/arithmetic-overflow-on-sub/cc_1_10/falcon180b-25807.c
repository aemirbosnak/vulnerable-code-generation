//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_UNITS 10

struct unit {
    char *name;
    double factor;
};

int main() {
    int choice;
    double value, result;
    char input[50];
    struct unit units[MAX_UNITS] = {
        {"meters", 1.0},
        {"kilometers", 0.001},
        {"inches", 0.0254},
        {"feet", 0.3048},
        {"yards", 0.9144},
        {"miles", 0.000621371},
        {"liters", 1.0},
        {"gallons", 0.264172},
        {"pounds", 0.453592},
        {"kilograms", 2.20462}
    };

    printf("Welcome to the Post-Apocalyptic Unit Converter!\n");
    printf("Select a unit to convert from:\n");

    for (int i = 0; i < MAX_UNITS; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }

    scanf("%d", &choice);

    printf("Enter a value to convert from %s:\n", units[choice - 1].name);
    scanf("%lf", &value);

    printf("Select a unit to convert to:\n");

    for (int i = 0; i < MAX_UNITS; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }

    scanf("%d", &choice);

    result = value * units[choice - 1].factor;

    printf("The converted value is: %.2lf %s\n", result, units[choice - 1].name);

    return 0;
}