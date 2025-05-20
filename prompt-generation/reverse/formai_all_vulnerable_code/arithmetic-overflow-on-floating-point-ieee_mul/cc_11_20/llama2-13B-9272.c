//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

typedef struct {
    char *name;
    double value;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"mm", 1},
    {"cm", 10},
    {"m", 100},
    {"km", 100000},
    {"inch", 2.54},
    {"ft", 12},
    {"yd", 36},
    {"mile", 1609.34},
    {"kg", 0.001},
    {"g", 0.01}
};

int main() {
    int i, j, k;
    char input[100];
    double value, conversion;

    printf("Welcome to the Unit Converter!\n");

    // Get the first unit from the user
    printf("Enter the first unit: ");
    fgets(input, 100, stdin);
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input, units[i].name) == 0) {
            break;
        }
    }
    if (i == MAX_UNITS) {
        printf("Invalid unit. Please try again.\n");
        return 1;
    }

    // Get the second unit from the user
    printf("Enter the second unit: ");
    fgets(input, 100, stdin);
    for (j = 0; j < MAX_UNITS; j++) {
        if (strcmp(input, units[j].name) == 0) {
            break;
        }
    }
    if (j == MAX_UNITS) {
        printf("Invalid unit. Please try again.\n");
        return 1;
    }

    // Calculate the conversion
    value = units[i].value * atof(input);
    conversion = value / units[j].value;

    // Print the result
    printf("%s is %f %s\n", units[i].name, conversion, units[j].name);

    // Ask the user if they want to convert again
    printf("Do you want to convert again? (y/n): ");
    scanf(" %c", &input);
    if (input == 'n') {
        return 0;
    }

    // Repeat the conversion process
    for (k = 0; k < MAX_CONVERSIONS; k++) {
        printf("Enter the first unit: ");
        fgets(input, 100, stdin);
        for (i = 0; i < MAX_UNITS; i++) {
            if (strcmp(input, units[i].name) == 0) {
                break;
            }
        }
        if (i == MAX_UNITS) {
            printf("Invalid unit. Please try again.\n");
            continue;
        }

        printf("Enter the second unit: ");
        fgets(input, 100, stdin);
        for (j = 0; j < MAX_UNITS; j++) {
            if (strcmp(input, units[j].name) == 0) {
                break;
            }
        }
        if (j == MAX_UNITS) {
            printf("Invalid unit. Please try again.\n");
            continue;
        }

        value = units[i].value * atof(input);
        conversion = value / units[j].value;

        printf("%s is %f %s\n", units[i].name, conversion, units[j].name);
    }

    return 0;
}