#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 50

double convert_length(const char *unit_from, const char *unit_to, double value) {
    if (strcmp(unit_from, "m") == 0 && strcmp(unit_to, "ft") == 0)
        return value * 3.28084;
    else if (strcmp(unit_from, "ft") == 0 && strcmp(unit_to, "m") == 0)
        return value / 3.28084;
    else if (strcmp(unit_from, "kg") == 0 && strcmp(unit_to, "lb") == 0)
        return value * 2.20462;
    else if (strcmp(unit_from, "lb") == 0 && strcmp(unit_to, "kg") == 0)
        return value / 2.20462;
    else
        return -1; // Error: Unsupported conversion
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter the length to convert (e.g., 10 m ft): ");
    fgets(input, sizeof(input), stdin);
    char *value_str = strtok(input, " ");
    char *unit_from = strtok(NULL, " ");
    char *unit_to = strtok(NULL, " ");

    if (value_str == NULL || unit_from == NULL || unit_to == NULL) {
        printf("Invalid input format.\n");
        return 1;
    }

    double value = atof(value_str);
    double result = convert_length(unit_from, unit_to, value);

    if (result == -1) {
        printf("Conversion not supported.\n");
    } else {
        printf("%.2f %s is %.2f %s\n", value, unit_from, result, unit_to);
    }

    return 0;
}
