//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define UNIT_NAMES "m,kg,s,A,K,mol,cd,rad,sr,Hz"

struct unit {
    char *name;
    double factor;
};

struct unit units[MAX_UNITS];

double convert(double value, int from, int to) {
    return value * units[to].factor / units[from].factor;
}

void add_unit(char *name, double factor) {
    int i;
    for (i = 0; i < MAX_UNITS; i++) {
        if (units[i].name == NULL) {
            units[i].name = strdup(name);
            units[i].factor = factor;
            return;
        }
    }
    printf("Error: Maximum number of units reached.\n");
    exit(1);
}

int main() {
    int i, j, choice;
    char input[50];
    double value;

    printf("Enter units separated by commas:\n");
    scanf("%s", input);

    char *token = strtok(input, ",");
    while (token!= NULL) {
        add_unit(token, 1.0);
        token = strtok(NULL, ",");
    }

    printf("Enter a value to convert:\n");
    scanf("%lf", &value);

    printf("Enter the unit to convert from (0-%d):\n", MAX_UNITS - 1);
    scanf("%d", &choice);

    printf("Enter the unit to convert to (0-%d):\n", MAX_UNITS - 1);
    scanf("%d", &j);

    double result = convert(value, choice, j);

    printf("Result: %.2lf %s = %.2lf %s\n", value, units[choice].name, result, units[j].name);

    return 0;
}