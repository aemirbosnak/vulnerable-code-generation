//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    Unit units[MAX_UNITS] = {{"meters", 1.0}, {"kilometers", 1000.0}, {"centimeters", 0.01}, {"millimeters", 0.001}, {"inches", 0.0254}, {"feet", 0.3048}, {"yards", 0.9144}, {"miles", 160934.4}, {"pounds", 0.453592}, {"ounces", 0.0283495}};
    int num_units = 0;
    char input[100];
    char *token;
    double value, result = 0.0;
    char from_unit[20], to_unit[20];

    printf("Welcome to the Unit Converter!\n");
    printf("Enter the units you want to convert from and to (e.g. meters to feet): ");
    scanf("%s", input);
    token = strtok(input, " ");
    strcpy(from_unit, token);
    token = strtok(NULL, " ");
    strcpy(to_unit, token);

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            num_units++;
            break;
        }
    }

    if (num_units == 0) {
        printf("Invalid input. Please enter a valid unit.\n");
        return 1;
    }

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, to_unit) == 0) {
            result = value * units[i].factor;
            printf("%.2f %s = %.2f %s\n", value, from_unit, result, to_unit);
            return 0;
        }
    }

    printf("Invalid input. Please enter a valid unit.\n");
    return 1;
}