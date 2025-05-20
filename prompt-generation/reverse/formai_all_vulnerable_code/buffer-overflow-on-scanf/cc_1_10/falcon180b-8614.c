//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERTERS 10

typedef struct {
    char *name;
    double (*convert)(double);
} Converter;

Converter converters[MAX_CONVERTERS];
int num_converters;

void add_converter(char *name, double (*convert)(double)) {
    if (num_converters >= MAX_CONVERTERS) {
        printf("Error: Maximum number of converters reached.\n");
        return;
    }
    converters[num_converters].name = name;
    converters[num_converters].convert = convert;
    num_converters++;
}

double length_converter(double value) {
    return value;
}

double weight_converter(double value) {
    return value;
}

double temperature_converter(double value) {
    return value;
}

double volume_converter(double value) {
    return value;
}

int main() {
    add_converter("Length", length_converter);
    add_converter("Weight", weight_converter);
    add_converter("Temperature", temperature_converter);
    add_converter("Volume", volume_converter);

    char input[100];
    while (1) {
        printf("Enter a unit to convert: ");
        scanf("%s", input);

        int i;
        for (i = 0; i < num_converters; i++) {
            if (strcmp(input, converters[i].name) == 0) {
                double value;
                printf("Enter a value to convert: ");
                scanf("%lf", &value);
                printf("%.2lf %s = %.2lf %s\n", value, input, converters[i].convert(value), converters[i].name);
                break;
            }
        }

        if (i == num_converters) {
            printf("Error: Invalid unit.\n");
        }
    }

    return 0;
}