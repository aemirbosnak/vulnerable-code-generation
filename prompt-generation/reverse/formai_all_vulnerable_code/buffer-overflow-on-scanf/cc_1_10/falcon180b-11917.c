//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 5
#define MAX_RATIOS 5

typedef struct {
    char *name;
    double ratio;
} unit;

void add_unit(unit *units, char *name, double ratio) {
    int i;
    for (i = 0; i < MAX_UNITS; i++) {
        if (units[i].name == NULL) {
            strcpy(units[i].name, name);
            units[i].ratio = ratio;
            return;
        }
    }
}

int main() {
    unit units[MAX_UNITS];
    int num_units = 0;
    char input[MAX_UNITS][50];
    int i, j;
    double value, result;
    char from_unit[50], to_unit[50];

    printf("Enter up to %d units (name:ratio):\n", MAX_UNITS);
    while (num_units < MAX_UNITS && scanf("%s:%lf", input[num_units], &value) == 2) {
        add_unit(units, input[num_units], value);
        num_units++;
    }

    printf("Select a unit to convert from:\n");
    for (i = 0; i < num_units; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
    scanf("%d", &i);

    printf("Enter the value to convert:\n");
    scanf("%lf", &value);

    printf("Select a unit to convert to:\n");
    for (j = 0; j < num_units; j++) {
        if (j!= i) {
            printf("%d. %s\n", j+1, units[j].name);
        }
    }
    scanf("%d", &j);

    result = value * units[j].ratio / units[i].ratio;

    printf("The result is %.2lf %s\n", result, units[j].name);

    return 0;
}