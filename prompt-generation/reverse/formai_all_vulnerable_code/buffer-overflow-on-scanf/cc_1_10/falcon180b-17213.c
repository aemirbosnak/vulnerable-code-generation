//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 5

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    Unit units[MAX_UNITS];
    int num_units;
    char input[50];
    char *token;
    double value, result;
    int i;

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the units you want to convert from and to (separated by spaces):\n");
    scanf("%s", input);
    token = strtok(input, " ");
    num_units = 0;

    while (token!= NULL) {
        for (i = 0; i < MAX_UNITS; i++) {
            if (strcmp(token, units[i].name) == 0) {
                break;
            }
        }

        if (i == MAX_UNITS) {
            printf("Invalid unit: %s\n", token);
            return 1;
        }

        num_units++;
        token = strtok(NULL, " ");
    }

    if (num_units!= 2) {
        printf("Please enter exactly two units to convert between.\n");
        return 1;
    }

    printf("Enter the value you want to convert:\n");
    scanf("%lf", &value);

    for (i = 0; i < num_units; i++) {
        result = value * units[i].factor;
        printf("%s = %.2lf %s\n", units[i].name, result, units[(i+1)%num_units].name);
    }

    return 0;
}