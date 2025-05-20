//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} unit;

int main() {
    int choice, i;
    double value, result = 0;
    char input[50];
    unit units[MAX_UNITS] = {{"meters", 1}, {"kilometers", 1000}, {"grams", 1}, {"kilograms", 1000}, {"liters", 1}, {"milliliters", 0.001}, {"seconds", 1}, {"minutes", 60}, {"hours", 3600}, {"days", 86400}};

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter a value and select the units you want to convert from and to:\n");
    scanf("%lf %s %s", &value, input, input);

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, input) == 0) {
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid unit entered.\n");
        return 1;
    }

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, input) == 0) {
            continue;
        }
        printf("%s\n", units[i].name);
    }

    printf("Enter the unit you want to convert to:\n");
    scanf("%s", input);

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, input) == 0) {
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid unit entered.\n");
        return 1;
    }

    result = value * units[i].factor / units[0].factor;

    printf("%.2lf %s = %.2lf %s\n", value, input, result, units[i].name);

    return 0;
}