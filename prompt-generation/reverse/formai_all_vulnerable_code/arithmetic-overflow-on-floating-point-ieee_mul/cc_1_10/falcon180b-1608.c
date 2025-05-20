//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_SIZE 1024
#define DELIMITER " "

typedef struct {
    char *name;
    double factor;
} Unit;

Unit celsius = {"Celsius", 1.0};
Unit fahrenheit = {"Fahrenheit", 1.8};
Unit kelvin = {"Kelvin", 1.0};

int main(int argc, char *argv[]) {
    char input[MAX_LINE_SIZE];
    char *token;
    double value, result;
    Unit *from_unit, *to_unit;
    
    printf("Enter a temperature value and its units (e.g. 100 C):\n");
    fgets(input, MAX_LINE_SIZE, stdin);
    
    // Parse input
    token = strtok(input, DELIMITER);
    if (token == NULL) {
        printf("Invalid input.\n");
        return 1;
    }
    value = strtod(token, NULL);
    
    token = strtok(NULL, DELIMITER);
    if (token == NULL) {
        printf("Invalid input.\n");
        return 1;
    }
    from_unit = &celsius;
    to_unit = &celsius;
    if (strcmp(token, "F") == 0) {
        from_unit = &fahrenheit;
        to_unit = &celsius;
    } else if (strcmp(token, "K") == 0) {
        from_unit = &kelvin;
        to_unit = &celsius;
    } else if (strcmp(token, "C") == 0) {
        from_unit = &celsius;
        to_unit = &fahrenheit;
    } else if (strcmp(token, "F") == 0) {
        from_unit = &fahrenheit;
        to_unit = &fahrenheit;
    } else if (strcmp(token, "K") == 0) {
        from_unit = &kelvin;
        to_unit = &kelvin;
    } else {
        printf("Invalid units.\n");
        return 1;
    }
    
    // Convert temperature
    result = (value * from_unit->factor) + 32;
    result = (result - 32) / 1.8;
    result = (result * to_unit->factor) + 273.15;
    
    // Print result
    printf("%.2f %s = %.2f %s\n", value, from_unit->name, result, to_unit->name);
    
    return 0;
}