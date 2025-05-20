//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double factor;
} unit;

unit units[] = {
    {"meters", 1},
    {"kilometers", 1000},
    {"grams", 1},
    {"kilograms", 1000},
    {"seconds", 1},
    {"minutes", 60},
    {"hours", 3600},
    {"liters", 1},
    {"gallons", 3.78541},
    {"fahrenheit", 1},
    {"celsius", 1.8},
    {"kelvin", 1},
};

int main() {
    char input[100], output[100];
    int i, j, n;
    unit from, to;

    printf("Welcome to the Futuristic Unit Converter!\n");
    printf("Enter the unit you want to convert from: ");
    scanf("%s", input);

    for (i = 0; i < sizeof(units) / sizeof(units[0]); i++) {
        if (strcmp(units[i].name, input) == 0) {
            from = units[i];
            break;
        }
    }

    printf("Enter the unit you want to convert to: ");
    scanf("%s", output);

    for (j = 0; j < sizeof(units) / sizeof(units[0]); j++) {
        if (strcmp(units[j].name, output) == 0) {
            to = units[j];
            break;
        }
    }

    printf("Enter the value you want to convert: ");
    scanf("%lf", &n);

    printf("%.2lf %s is equal to %.2lf %s.\n", n, from.name, n * to.factor, to.name);

    return 0;
}