//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 100
#define MAX_CONVERSION_FACTOR 100

typedef struct {
    char *name;
    double conversion_factor;
} unit;

int main() {
    unit units[MAX_UNITS];
    int num_units = 0;
    char input[100];
    char *token;

    printf("Welcome to the unit converter!\n");
    printf("Enter units and their conversion factors:\n");

    // Read in units and their conversion factors
    while (num_units < MAX_UNITS) {
        printf("Enter unit name: ");
        fgets(input, 100, stdin);
        token = strtok(input, " ");
        strcpy(units[num_units].name, token);

        printf("Enter conversion factor for %s: ", units[num_units].name);
        scanf("%lf", &units[num_units].conversion_factor);
        num_units++;
    }

    // Convert between units
    while (1) {
        printf("\nEnter the unit you want to convert from:\n");
        for (int i = 0; i < num_units; i++) {
            printf("%s\n", units[i].name);
        }

        char from_unit[50];
        scanf("%s", from_unit);

        printf("Enter the value you want to convert:\n");
        double value;
        scanf("%lf", &value);

        printf("Enter the unit you want to convert to:\n");
        for (int i = 0; i < num_units; i++) {
            printf("%s\n", units[i].name);
        }

        char to_unit[50];
        scanf("%s", to_unit);

        double result = value * units[get_unit_index(units, num_units, from_unit)].conversion_factor / units[get_unit_index(units, num_units, to_unit)].conversion_factor;
        printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);

        printf("Convert another value? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    return 0;
}

// Get the index of a unit in the units array
int get_unit_index(unit units[], int num_units, char *unit_name) {
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, unit_name) == 0) {
            return i;
        }
    }
    return -1;
}