//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct {
    char name[20];
    double value;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"foot", 0.3048},
    {"yard", 0.9144},
    {"mile", 1609.344},
    {"inch", 0.0254},
    {"pound", 0.453592},
    {"ounce", 0.0283495},
    {"gram", 0.001},
    {"kilogram", 1000.0}
};

void print_units(void) {
    int i;
    for (i = 0; i < MAX_UNITS; i++) {
        printf("%d. %s (%f)\n", i + 1, units[i].name, units[i].value);
    }
}

void convert_units(unit_t *from, unit_t *to, double value) {
    double factor = 1.0;
    for (int i = 0; i < MAX_CONVERTIONS; i++) {
        if (from->name == to->name) break;
        factor *= (to->value / from->value);
    }
    value *= factor;
}

int main(void) {
    srand(time(NULL));

    unit_t from, to;
    double value;

    printf("Welcome to the Unit Converter! \n");

    do {
        printf("Enter a unit to convert (meter, kilometer, foot, yard, mile, inch, pound, ounce, gram, or kilogram): ");
        fgets(from.name, 20, stdin);
        sscanf(from.name, "%lf", &from.value);

        printf("Enter a unit to convert to (meter, kilometer, foot, yard, mile, inch, pound, ounce, gram, or kilogram): ");
        fgets(to.name, 20, stdin);
        sscanf(to.name, "%lf", &to.value);

        value = from.value;
        convert_units(&from, &to, value);

        printf("Conversion complete! %f %s is equal to %f %s.\n", from.value, from.name, value, to.name);

    } while (1);

    return 0;
}