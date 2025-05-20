//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100
#define MAX_UNITS 10

typedef struct {
    char name[MAX_LENGTH];
    double conversion_factor;
} Unit;

int main() {
    char input[MAX_LENGTH];
    char *unit_name;
    double value, converted_value;
    int choice;
    Unit units[MAX_UNITS];

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter a value to convert (e.g. 10 kg): ");
    fgets(input, MAX_LENGTH, stdin);

    // Parse input
    char *token = strtok(input, " ");
    value = strtod(token, NULL);
    unit_name = strtok(NULL, " ");

    // Convert to base unit
    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            converted_value = value / units[i].conversion_factor;
            printf("%.2f %s = %.2f %s\n", value, unit_name, converted_value, units[i].name);
            break;
        }
    }

    // Convert to other units
    printf("Select a unit to convert to:\n");
    for (int i = 0; i < MAX_UNITS; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
    scanf("%d", &choice);

    converted_value = value / units[choice-1].conversion_factor;
    printf("%.2f %s = %.2f %s\n", value, unit_name, converted_value, units[choice-1].name);

    return 0;
}