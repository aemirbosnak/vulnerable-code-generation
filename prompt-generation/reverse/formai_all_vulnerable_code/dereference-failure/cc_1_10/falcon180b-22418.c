//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 50
#define MAX_CONVERTED_UNITS 10

typedef struct {
    char *name;
    double factor;
    int is_metric;
} Unit;

int main() {
    char input[100];
    char *token;
    Unit units[MAX_UNITS];
    int num_units = 0;
    int metric_units = 0;
    int i;

    printf("Enter units and their conversion factors (e.g. \"miles 1.60934\"):\n");

    while (fgets(input, sizeof(input), stdin)!= NULL) {
        token = strtok(input, " ");
        if (token == NULL) {
            continue;
        }

        units[num_units].name = strdup(token);
        units[num_units].factor = strtod(strtok(NULL, " "), NULL);
        units[num_units].is_metric = (strcmp(units[num_units].name, "meter") == 0);
        num_units++;
    }

    printf("Enter a value to convert:\n");
    fgets(input, sizeof(input), stdin);
    token = strtok(input, " ");
    if (token == NULL) {
        printf("Invalid input.\n");
        return 1;
    }

    double value = strtod(token, NULL);
    int num_converted_units = 0;

    for (i = 0; i < num_units; i++) {
        if (units[i].is_metric!= metric_units) {
            continue;
        }

        double converted_value = value * units[i].factor;
        printf("%s = %.2f %s\n", units[i].name, converted_value, units[i].name);
        if (num_converted_units >= MAX_CONVERTED_UNITS) {
            break;
        }
        num_converted_units++;
    }

    return 0;
}