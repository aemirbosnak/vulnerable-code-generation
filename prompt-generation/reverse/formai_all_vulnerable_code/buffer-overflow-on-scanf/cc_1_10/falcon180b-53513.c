//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>

#define NUM_UNITS 7

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"meters", 1.0},
    {"kilometers", 1000.0},
    {"inches", 0.0254},
    {"feet", 0.3048},
    {"yards", 0.9144},
    {"miles", 160934.4},
    {"pounds", 0.453592}
};

int main() {
    char input[50];
    double value, result;
    int choice;

    printf("Welcome to the Unit Converter!\n\n");
    printf("Enter a value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit you want to convert from (e.g. meters): ");
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

    printf("Enter the unit you want to convert to (e.g. kilometers): ");
    scanf("%s", input);

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(input, units[i].name) == 0) {
            result = value * units[i].factor;
            printf("%lf %s = %lf %s\n", value, units[choice].name, result, units[i].name);
            break;
        }
    }

    return 0;
}