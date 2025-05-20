//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 5
#define MAX_CONVERSIONS 5

typedef struct {
    const char *name;
    double factor;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"cm", 1.0},
    {"m", 10.0},
    {"km", 100.0},
    {"inch", 2.54},
    {"ft", 12.0}
};

int main() {
    double value;
    char unit[20];
    int i, j;

    printf("Enter a value: ");
    scanf("%lf", &value);

    printf("Enter the unit you want to convert from (cm, m, km, inch, ft): ");
    fgets(unit, sizeof(unit), stdin);

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(unit, units[i].name) == 0) {
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid unit. Please try again.\n");
        return 1;
    }

    for (j = 0; j < MAX_CONVERSIONS; j++) {
        double converted_value = value * units[i].factor;
        printf("%.2f %s is equal to %.2f %s\n", value, unit, converted_value, units[j].name);
    }

    return 0;
}