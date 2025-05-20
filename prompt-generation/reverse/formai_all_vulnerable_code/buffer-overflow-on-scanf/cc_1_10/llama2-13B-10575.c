//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_OPERATIONS 5

// Structure to hold unit information
typedef struct {
    char *name;   // Unit name (e.g. "cm", "m", "km")
    double factor; // Conversion factor (e.g. 100 for cm to m)
} unit_t;

// Structure to hold operation information
typedef struct {
    char *op;    // Operation (e.g. "convert", "multiply", "divide")
    double num1; // Operand 1
    double num2; // Operand 2
} op_t;

// Array to hold unit information
unit_t units[UNIT_CONVERTER_MAX_UNITS] = {
    {"cm", 100.0},
    {"m", 1000.0},
    {"km", 1000000.0},
    {"inch", 2.54},
    {"foot", 12.0},
    {"yard", 36.0},
    {"mile", 5280.0}
};

// Array to hold operation information
op_t ops[UNIT_CONVERTER_MAX_OPERATIONS] = {
    {"convert", 1.0, 1.0},
    {"multiply", 2.0, 3.0},
    {"divide", 4.0, 2.0},
    {"add", 5.0, 6.0}
};

// Function to perform a unit conversion
double unit_convert(double num, char *from_unit, char *to_unit) {
    int i = 0;
    for (i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            break;
        }
    }
    if (i == UNIT_CONVERTER_MAX_UNITS) {
        printf("Invalid unit: %s\n", from_unit);
        return 0.0;
    }
    double factor = units[i].factor;
    for (i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        if (strcmp(to_unit, units[i].name) == 0) {
            break;
        }
    }
    if (i == UNIT_CONVERTER_MAX_UNITS) {
        printf("Invalid unit: %s\n", to_unit);
        return 0.0;
    }
    double result = num * factor / units[i].factor;
    return result;
}

// Function to perform an operation
double op_perform(double num1, double num2, char *op) {
    int i = 0;
    for (i = 0; i < UNIT_CONVERTER_MAX_OPERATIONS; i++) {
        if (strcmp(op, ops[i].op) == 0) {
            break;
        }
    }
    if (i == UNIT_CONVERTER_MAX_OPERATIONS) {
        printf("Invalid operation: %s\n", op);
        return 0.0;
    }
    double result = ops[i].num1 * num1 + ops[i].num2 * num2;
    return result;
}

int main() {
    double num1 = 5.0;
    double num2 = 3.0;
    char op[10];
    char from_unit[10];
    char to_unit[10];

    // Example usage
    printf("Enter a number: ");
    scanf("%lf", &num1);
    printf("Enter a unit (e.g. 'cm' or 'm'): ");
    scanf("%s", from_unit);
    printf("Enter a target unit (e.g. 'cm' or 'm'): ");
    scanf("%s", to_unit);
    printf("Enter an operation (e.g. 'convert', 'multiply', or 'divide'): ");
    scanf("%s", op);

    // Perform the operation
    double result = op_perform(num1, num2, op);
    printf("Result: %lf\n", result);

    // Perform the unit conversion
    result = unit_convert(num1, from_unit, to_unit);
    printf("Result (converted to %s): %lf\n", to_unit, result);

    return 0;
}