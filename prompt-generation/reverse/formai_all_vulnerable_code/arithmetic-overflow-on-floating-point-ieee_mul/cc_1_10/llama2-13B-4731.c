//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 5
#define MAX_CONVERTIONS 5

typedef struct unit {
    char name[20];
    double conversion[MAX_CONVERTIONS];
} unit_t;

unit_t units[MAX_UNITS] = {
    {"meter", {1, 1, 100, 10000, 1000000}}, // length
    {"kilogram", {1, 1, 1000, 1000000, 1000000000}}, // mass
    {"second", {1, 1, 60, 3600, 86400}}, // time
    {"celsius", {1, 1, 0.5, 10, 32, 273.15}}, // temperature
    {"ampere", {1, 1, 10, 100, 1000, 1000000}} // electric current
};

void init_units(void);
void convert_units(unit_t *from, unit_t *to, double value);

int main(void) {
    init_units();

    unit_t from, to;
    double value;

    printf("Enter a value to convert: ");
    scanf("%lf", &value);

    printf("Choose the source unit (meter, kilogram, second, celsius, ampere): ");
    char unit_choice[20];
    fgets(unit_choice, 20, stdin);

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(unit_choice, units[i].name) == 0) {
            from = units[i];
            break;
        }
    }

    printf("Choose the destination unit (meter, kilogram, second, celsius, ampere): ");
    char unit_choice2[20];
    fgets(unit_choice2, 20, stdin);

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(unit_choice2, units[i].name) == 0) {
            to = units[i];
            break;
        }
    }

    convert_units(&from, &to, value);

    printf("The value in %s is %f\n", to.name, value);

    return 0;
}

void init_units(void) {
    for (int i = 0; i < MAX_UNITS; i++) {
        for (int j = 0; j < MAX_CONVERTIONS; j++) {
            units[i].conversion[j] = pow(10, (j * (i == 0 || i == 3)) / 2);
        }
    }
}

void convert_units(unit_t *from, unit_t *to, double value) {
    double result = value;

    for (int i = 0; i < MAX_CONVERTIONS; i++) {
        if (from->name[i] == to->name[i]) {
            result *= from->conversion[i];
        } else {
            result /= from->conversion[i];
        }
    }

    to->name[0] = result;
}