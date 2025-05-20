//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_UNITS 10

struct unit {
    char *name;
    double factor;
};

int main() {
    int num_units, i, j;
    struct unit units[MAX_UNITS];
    char input[100], unit_name[20];
    double value, result;

    num_units = 0;
    printf("Enter the number of units (max %d): ", MAX_UNITS);
    scanf("%d", &num_units);

    for (i = 0; i < num_units; i++) {
        printf("Enter unit name: ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0';
        strcpy(units[i].name, input);

        printf("Enter unit factor: ");
        scanf("%lf", &units[i].factor);
    }

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert to: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';
    strcpy(unit_name, input);

    for (i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, unit_name) == 0) {
            result = value * units[i].factor;
            printf("Result: %lf %s\n", result, units[i].name);
            return 0;
        }
    }

    printf("Invalid unit\n");
    return 1;
}