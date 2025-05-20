//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define TRUE 1
#define FALSE 0
#define MAX_UNITS 10

typedef struct {
    char *unit;
    double conversion_factor;
} unit_t;

unit_t units[MAX_UNITS];
int num_units;

void add_unit(char *unit, double conversion_factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }

    units[num_units].unit = unit;
    units[num_units].conversion_factor = conversion_factor;
    num_units++;
}

int main() {
    add_unit("meter", 1.0);
    add_unit("centimeter", 0.01);
    add_unit("kilometer", 1000.0);
    add_unit("inch", 0.0254);
    add_unit("foot", 0.3048);
    add_unit("yard", 0.9144);
    add_unit("mile", 160934.4);

    char input[100];
    double value;
    int i;

    printf("Enter a value and its unit (e.g. 5 meter): ");
    scanf("%s %lf", input, &value);

    for (i = 0; i < num_units; i++) {
        if (strcmp(units[i].unit, input) == 0) {
            printf("%.2f %s = %.2f %s\n", value, input, value * units[i].conversion_factor, units[i+1].unit);
            break;
        }
    }

    return 0;
}