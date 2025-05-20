//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_UNITS 10
#define MAX_VALUE 10000

// Structure to hold unit information
typedef struct {
    char name[20];  // Unit name (e.g. "meter", "pound", "celsius")
    double factor;  // Conversion factor (e.g. 1000 for meters to feet)
} unit_t;

// Array to hold all available units
unit_t units[MAX_UNITS] = {
    {"meter", 1.0},
    {"foot", 0.3048},
    {"inch", 0.0254},
    {"pound", 0.453592},
    {"ounce", 0.0283495},
    {"temperature", 1.0},
    {"celsius", 1.0},
    {"farenheit", 1.8}
};

// Function to convert a value from one unit to another
double convert(double value, unit_t from, unit_t to) {
    return value * from.factor / to.factor;
}

// Function to calculate the result of a calculation
double calculate(double value1, double value2, char op) {
    double result;
    if (op == '+') {
        result = value1 + value2;
    } else if (op == '-') {
        result = value1 - value2;
    } else if (op == '*') {
        result = value1 * value2;
    } else if (op == '/') {
        result = value1 / value2;
    } else {
        printf("Invalid operator\n");
        return 0;
    }
    return result;
}

int main() {
    double value1, value2, result;
    char op, unit1, unit2;

    // Display the menu
    printf("Unit Converter\n");
    printf("-----------------\n");
    printf("Convert units of length, weight, and temperature\n");
    printf("Type 'h' for help\n");

    // Get the first value from the user
    printf("Enter a value: ");
    scanf("%lf", &value1);

    // Get the unit for the first value
    printf("Enter the unit for value1 (m/ft/in): ");
    scanf(" %c", &unit1);

    // Convert the value to the unit specified
    value1 = convert(value1, units[unit1 - '0'], units[0]);

    // Get the second value from the user
    printf("Enter another value: ");
    scanf("%lf", &value2);

    // Get the unit for the second value
    printf("Enter the unit for value2 (m/ft/in): ");
    scanf(" %c", &unit2);

    // Convert the value to the unit specified
    value2 = convert(value2, units[unit2 - '0'], units[0]);

    // Display the calculation result
    result = calculate(value1, value2, '+');
    printf("Result: %f\n", result);

    // Check if the user wants to calculate again
    printf("Do you want to calculate again? (y/n): ");
    scanf(" %c", &op);

    // Loop until the user enters "n"
    while (op == 'y' || op == 'Y') {
        // Get the next value from the user
        printf("Enter another value: ");
        scanf("%lf", &value1);

        // Get the unit for the next value
        printf("Enter the unit for value1 (m/ft/in): ");
        scanf(" %c", &unit1);

        // Convert the value to the unit specified
        value1 = convert(value1, units[unit1 - '0'], units[0]);

        // Calculate the result
        result = calculate(value1, value2, '+');
        printf("Result: %f\n", result);

        // Ask the user if they want to calculate again
        printf("Do you want to calculate again? (y/n): ");
        scanf(" %c", &op);
    }

    // Display the random unit generator
    printf("Random Unit Generator\n");
    printf("-------------------------\n");
    printf("Here's a random unit of measurement: %s\n", units[rand() % MAX_UNITS].name);

    // Display the built-in calculator
    printf("Built-in Calculator\n");
    printf("---------------------\n");
    printf("Enter two numbers separated by a space, and a math operator (e.g. 2 3 +): ");
    scanf("%lf %lf %c", &value1, &value2, &op);
    result = calculate(value1, value2, op);
    printf("Result: %f\n", result);

    return 0;
}