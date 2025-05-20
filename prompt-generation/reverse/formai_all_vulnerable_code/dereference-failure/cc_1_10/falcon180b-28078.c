//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    int num_units = 0;
    Unit *units = NULL;
    char input[100];
    char choice;
    double value, result;

    printf("Welcome to the Sherlock Holmes Unit Converter!\n");
    printf("Please enter the base unit and its value:\n");
    fgets(input, 100, stdin);
    value = atof(input);

    // Initialize units
    units = (Unit *)malloc(MAX_UNITS * sizeof(Unit));
    num_units = 0;

    // Add base unit
    units[num_units].name = "base";
    units[num_units].factor = 1;
    num_units++;

    while (1) {
        printf("\nEnter a new unit name (or 'q' to quit):\n");
        fgets(input, 100, stdin);
        choice = toupper(input[0]);
        if (choice == 'Q') {
            break;
        } else if (choice!= 'A' && num_units >= MAX_UNITS) {
            printf("Maximum number of units reached.\n");
            continue;
        }
        printf("Enter the conversion factor for %s:\n", input);
        fgets(input, 100, stdin);
        units[num_units].factor = atof(input);
        num_units++;
    }

    // Convert value
    printf("\nEnter the target unit name:\n");
    fgets(input, 100, stdin);
    for (int i = 0; i < num_units; i++) {
        if (strcmp(input, units[i].name) == 0) {
            result = value * units[i].factor;
            printf("%.2f %s = %.2f %s\n", value, units[i].name, result, input);
            break;
        }
    }

    free(units);
    return 0;
}