//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char unit_from[10], unit_to[10];
    double value, result;
    int choice;

    // Units of measurement
    char *units[] = {"length", "weight", "volume", "temperature"};

    // Conversion factors
    double factors[][4] = {
        {1, 0.3048, 0.453592, 1},
        {0.453592, 1, 0.264172, 1},
        {0.264172, 0.453592, 1, 1},
        {1, 5/9, 1, 1}
    };

    printf("Welcome to the Unit Converter!\n\n");
    printf("Please select a unit of measurement:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i+1, units[i]);
    }
    scanf("%d", &choice);

    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit of measurement for the value: ");
    scanf("%s", unit_from);

    printf("Enter the unit of measurement you want to convert to: ");
    scanf("%s", unit_to);

    if (unit_from[0] == '\0' || unit_to[0] == '\0') {
        printf("Error: Please enter valid units of measurement.\n");
        return 1;
    }

    int index_from = -1, index_to = -1;
    for (int i = 0; i < 4; i++) {
        if (strcmp(units[i], unit_from) == 0) {
            index_from = i;
        }
        if (strcmp(units[i], unit_to) == 0) {
            index_to = i;
        }
    }

    if (index_from == -1 || index_to == -1) {
        printf("Error: Invalid units of measurement.\n");
        return 1;
    }

    result = value * factors[index_from][index_to];

    printf("%.2lf %s is equal to %.2lf %s.\n", value, unit_from, result, unit_to);

    return 0;
}