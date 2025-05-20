//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    Unit units[MAX_UNITS];
    int num_units = 0;
    char input[100];
    double value, result = 0;
    char from_unit[10], to_unit[10];

    printf("Welcome to the Unit Converter!\n");
    printf("Enter units separated by commas:\n");
    scanf("%s", input);

    char *token = strtok(input, ",");
    while (token!= NULL) {
        if (num_units >= MAX_UNITS) {
            printf("Error: Too many units.\n");
            exit(1);
        }
        units[num_units].name = token;
        scanf("%lf", &units[num_units].factor);
        num_units++;
        token = strtok(NULL, ",");
    }

    printf("Enter a value to convert:\n");
    scanf("%lf", &value);

    printf("Enter the unit to convert from:\n");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to:\n");
    scanf("%s", to_unit);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(from_unit, units[i].name) == 0 && strcmp(to_unit, units[i].name)!= 0) {
            result = value * units[i].factor;
            break;
        } else if (strcmp(from_unit, units[i].name)!= 0 && strcmp(to_unit, units[i].name) == 0) {
            result = value / units[i].factor;
            break;
        }
    }

    if (result == 0) {
        printf("Error: Invalid units.\n");
    } else {
        printf("The result is %.2lf %s.\n", result, to_unit);
    }

    return 0;
}