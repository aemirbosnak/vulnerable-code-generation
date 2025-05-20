//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 4

struct unit {
    char *name;
    double factor;
};

struct unit temperature_units[] = {
    {"Celsius", 1.0},
    {"Fahrenheit", 1.8},
    {"Kelvin", 1.0},
    {"Rankine", 1.8}
};

int main() {
    int num_units;
    char input[80];
    double temperature, result;
    struct unit *units;

    printf("Enter the temperature value: ");
    scanf("%lf", &temperature);

    printf("Enter the original temperature unit (Celsius/Fahrenheit/Kelvin/Rankine): ");
    scanf("%s", input);

    num_units = 0;
    units = malloc(sizeof(struct unit) * num_units);

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input, temperature_units[i].name) == 0) {
            units[num_units] = temperature_units[i];
            num_units++;
            break;
        }
    }

    if (num_units == 0) {
        printf("Invalid temperature unit.\n");
        exit(1);
    }

    printf("Enter the target temperature unit (Celsius/Fahrenheit/Kelvin/Rankine): ");
    scanf("%s", input);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(input, units[i].name) == 0) {
            result = temperature * units[i].factor;
            printf("%.2lf %s = %.2lf %s\n", temperature, units[i].name, result, input);
            break;
        }
    }

    for (int i = 0; i < num_units; i++) {
        free(units[i].name);
    }
    free(units);

    return 0;
}