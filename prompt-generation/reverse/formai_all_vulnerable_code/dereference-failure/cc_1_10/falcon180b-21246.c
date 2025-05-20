//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    double (*convert)(double);
} Unit;

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double fahrenheit_to_kelvin(double fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvin_to_fahrenheit(double kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

Unit units[] = {
    {"Celsius", celsius_to_fahrenheit},
    {"Fahrenheit", fahrenheit_to_celsius},
    {"Kelvin", kelvin_to_celsius}
};

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    char *input_line = NULL;
    char *token = NULL;
    char *endptr = NULL;
    double temperature = 0.0;
    double result = 0.0;
    char *from_unit = NULL;
    char *to_unit = NULL;
    int from_unit_index = -1;
    int to_unit_index = -1;
    int i = 0;

    printf("Enter temperature: ");
    fgets(input_buffer, MAX_LINE_LENGTH, stdin);
    input_line = strdup(input_buffer);
    token = strtok(input_line, " ");
    temperature = strtod(token, &endptr);

    token = strtok(NULL, " ");
    from_unit = strdup(token);

    token = strtok(NULL, " ");
    to_unit = strdup(token);

    for (i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            from_unit_index = i;
        } else if (strcmp(units[i].name, to_unit) == 0) {
            to_unit_index = i;
        }
    }

    if (from_unit_index == -1 || to_unit_index == -1) {
        printf("Invalid unit\n");
        exit(1);
    }

    result = units[from_unit_index].convert(temperature);
    result = units[to_unit_index].convert(result);

    printf("%.2f %s = %.2f %s\n", temperature, from_unit, result, to_unit);

    free(input_line);
    free(from_unit);
    free(to_unit);

    return 0;
}