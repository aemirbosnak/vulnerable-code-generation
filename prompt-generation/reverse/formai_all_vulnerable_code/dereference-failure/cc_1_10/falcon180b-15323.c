//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 50

typedef struct {
    char *name;
    double factor;
} unit;

int main() {
    unit units[MAX_UNITS];
    int num_units = 0;
    char input[100];
    char *token;

    printf("Enter units separated by spaces:\n");
    fgets(input, sizeof(input), stdin);

    // Parse input and add units to array
    token = strtok(input, " ");
    while (token!= NULL) {
        if (num_units >= MAX_UNITS) {
            printf("Error: Too many units specified.\n");
            exit(1);
        }
        units[num_units].name = strdup(token);
        units[num_units].factor = 1.0; // Default factor is 1.0
        num_units++;
        token = strtok(NULL, " ");
    }

    // Prompt user for input value and unit
    printf("Enter a value and unit (e.g. 10 meters):\n");
    fgets(input, sizeof(input), stdin);
    token = strtok(input, " ");
    char *value_str = strtok(NULL, " ");

    // Convert input value to double
    double value = atof(value_str);

    // Convert input unit to lowercase for case-insensitive comparison
    for (int i = 0; i < strlen(token); i++) {
        token[i] = tolower(token[i]);
    }

    // Find matching unit in array
    unit *match = NULL;
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, token) == 0) {
            match = &units[i];
            break;
        }
    }

    if (match == NULL) {
        printf("Error: Invalid unit specified.\n");
        exit(1);
    }

    // Convert value to target unit
    double result = value * match->factor;
    printf("%.2f %s = %.2f %s\n", value, token, result, match->name);

    return 0;
}