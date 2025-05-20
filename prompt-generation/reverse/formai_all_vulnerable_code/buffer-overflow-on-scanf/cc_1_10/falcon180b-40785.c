//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_UNITS 20

typedef struct {
    char *name;
    double value;
} unit;

unit units[MAX_UNITS];

int main(int argc, char **argv) {
    int i;
    char input[100];
    unit from, to;

    printf("Welcome to the Ultraprecise Unit Converter!\n");
    printf("Enter a unit to convert from: ");
    scanf("%s", input);
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input, units[i].name) == 0) {
            from = units[i];
            break;
        }
    }
    if (i == MAX_UNITS) {
        printf("Invalid unit.\n");
        return 1;
    }

    printf("Enter a unit to convert to: ");
    scanf("%s", input);
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input, units[i].name) == 0) {
            to = units[i];
            break;
        }
    }
    if (i == MAX_UNITS) {
        printf("Invalid unit.\n");
        return 1;
    }

    printf("Enter a value to convert: ");
    scanf("%lf", &from.value);

    to.value = from.value * to.value;

    printf("%.2lf %s = %.2lf %s\n", from.value, from.name, to.value, to.name);

    return 0;
}