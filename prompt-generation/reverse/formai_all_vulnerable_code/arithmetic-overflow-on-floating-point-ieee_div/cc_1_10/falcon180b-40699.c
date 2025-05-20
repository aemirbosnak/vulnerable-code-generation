//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNITS 6

struct unit {
    char *name;
    int factor;
};

struct unit units[UNITS] = {
    {"meters", 1},
    {"centimeters", 100},
    {"kilometers", 100000},
    {"grams", 1},
    {"kilograms", 1000},
    {"liters", 1}
};

// Function to convert between units
double convert(double value, int from, int to) {
    double result = value * units[from].factor / units[to].factor;
    return result;
}

int main() {
    int choice, from, to;
    double value;
    char unit[100];

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the unit you want to convert from:\n");
    for (int i = 0; i < UNITS; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }
    scanf("%d", &from);

    printf("Please enter the unit you want to convert to:\n");
    for (int i = 0; i < UNITS; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }
    scanf("%d", &to);

    printf("Please enter the value you want to convert:\n");
    scanf("%lf", &value);

    switch (from) {
        case 0:
            printf("%.2lf %s is equal to %.2lf %s.\n", value, units[from].name, convert(value, from, to), units[to].name);
            break;
        case 1:
            printf("%.2lf %s is equal to %.2lf %s.\n", value, units[from].name, convert(value, from, to), units[to].name);
            break;
        case 2:
            printf("%.2lf %s is equal to %.2lf %s.\n", value, units[from].name, convert(value, from, to), units[to].name);
            break;
        case 3:
            printf("%.2lf %s is equal to %.2lf %s.\n", value, units[from].name, convert(value, from, to), units[to].name);
            break;
        case 4:
            printf("%.2lf %s is equal to %.2lf %s.\n", value, units[from].name, convert(value, from, to), units[to].name);
            break;
        case 5:
            printf("%.2lf %s is equal to %.2lf %s.\n", value, units[from].name, convert(value, from, to), units[to].name);
            break;
    }

    return 0;
}