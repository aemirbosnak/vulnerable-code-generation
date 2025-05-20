//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define UNITS 7

typedef struct {
    char *name;
    double factor;
} unit_t;

unit_t units[] = {
    {"meters", 1.0},
    {"kilometers", 1000.0},
    {"centimeters", 0.01},
    {"inches", 2.54},
    {"feet", 30.48},
    {"yards", 91.44},
    {"miles", 1609.34}
};

void print_units() {
    for (int i = 0; i < UNITS; i++) {
        printf("%s\n", units[i].name);
    }
}

double convert(double value, char *from, char *to) {
    int i, j;
    for (i = 0; i < UNITS; i++) {
        if (strcmp(units[i].name, from) == 0) {
            break;
        }
    }
    if (i == UNITS) {
        printf("Invalid unit: %s\n", from);
        return -1;
    }
    for (j = 0; j < UNITS; j++) {
        if (strcmp(units[j].name, to) == 0) {
            break;
        }
    }
    if (j == UNITS) {
        printf("Invalid unit: %s\n", to);
        return -1;
    }
    return value * units[i].factor / units[j].factor;
}

int main() {
    double value;
    char from[20], to[20];
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the unit to convert from: ");
    scanf("%s", from);
    printf("Enter the unit to convert to: ");
    scanf("%s", to);
    double result = convert(value, from, to);
    if (result == -1) {
        printf("Error: invalid unit conversion\n");
    } else {
        printf("%lf %s is equal to %lf %s\n", value, from, result, to);
    }
    return 0;
}