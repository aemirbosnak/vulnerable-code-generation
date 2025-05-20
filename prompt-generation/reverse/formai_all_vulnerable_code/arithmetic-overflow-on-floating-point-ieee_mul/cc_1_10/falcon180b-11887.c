//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 7

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"meters", 1.0},
    {"feet", 3.28084},
    {"inches", 39.37008},
    {"kilograms", 1.0},
    {"pounds", 2.20462},
    {"gallons", 3.78541},
    {"liters", 1.0}
};

int main() {
    char input[100];
    char *token;
    int choice;
    double value, result;

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the unit you want to convert from:\n");
    scanf("%s", input);

    token = strtok(input, " ");
    while (units[choice].name!= NULL && strcmp(token, units[choice].name)!= 0) {
        choice++;
    }

    if (units[choice].name == NULL) {
        printf("Invalid unit.\n");
        return 1;
    }

    printf("Please enter the value you want to convert:\n");
    scanf("%lf", &value);

    printf("Please enter the unit you want to convert to:\n");
    scanf("%s", input);

    token = strtok(input, " ");
    while (units[choice].name!= NULL && strcmp(token, units[choice].name)!= 0) {
        choice++;
    }

    if (units[choice].name == NULL) {
        printf("Invalid unit.\n");
        return 1;
    }

    result = value * units[choice].factor;

    printf("%.2lf %s = %.2lf %s\n", value, units[choice - 1].name, result, units[choice].name);

    return 0;
}