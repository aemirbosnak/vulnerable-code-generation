//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 80
#define MAX_TOKEN_SIZE 20

enum {
    TEMP_CELSIUS = 0,
    TEMP_FAHRENHEIT,
    TEMP_KELVIN,
    TEMP_RANKINE
};

struct temp_unit {
    char *name;
    int conversion_factor;
};

static struct temp_unit temp_units[] = {
    { "Celsius", 1 },
    { "Fahrenheit", 9 / 5 },
    { "Kelvin", 1 },
    { "Rankine", 9 / 5 }
};

int get_temp_unit_index(const char *unit_name) {
    int i;

    for (i = 0; i < sizeof(temp_units) / sizeof(temp_units[0]); i++) {
        if (strcmp(temp_units[i].name, unit_name) == 0) {
            return i;
        }
    }

    return -1;
}

int parse_temp_unit(const char *unit_name) {
    int i;

    for (i = 0; i < sizeof(temp_units) / sizeof(temp_units[0]); i++) {
        if (strcmp(temp_units[i].name, unit_name) == 0) {
            return i;
        }
    }

    return -1;
}

double convert_temp(double temp, int from_unit_index, int to_unit_index) {
    return (temp * temp_units[to_unit_index].conversion_factor) + temp_units[from_unit_index].conversion_factor;
}

int main() {
    char input_line[MAX_LINE_SIZE];
    char *token;
    double temp;
    int from_unit_index, to_unit_index;

    printf("Enter a temperature in the format <temperature> <unit>\n");
    fgets(input_line, MAX_LINE_SIZE, stdin);

    token = strtok(input_line, " ");
    temp = strtod(token, NULL);

    token = strtok(NULL, " ");
    from_unit_index = get_temp_unit_index(token);

    token = strtok(NULL, " ");
    to_unit_index = parse_temp_unit(token);

    if (from_unit_index == -1 || to_unit_index == -1) {
        printf("Invalid unit\n");
        return 1;
    }

    temp = convert_temp(temp, from_unit_index, to_unit_index);

    printf("%.2f %s = %.2f %s\n", temp, temp_units[from_unit_index].name, temp, temp_units[to_unit_index].name);

    return 0;
}