//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_UNITS 10

// Function to convert value from one unit to another
double convert_value(double value, char from_unit[MAX_UNITS], char to_unit[MAX_UNITS]) {
    if (strcmp(from_unit, "m") == 0 && strcmp(to_unit, "km") == 0) {
        return value / 1000;
    } else if (strcmp(from_unit, "km") == 0 && strcmp(to_unit, "m") == 0) {
        return value * 1000;
    } else if (strcmp(from_unit, "kg") == 0 && strcmp(to_unit, "g") == 0) {
        return value * 1000;
    } else if (strcmp(from_unit, "g") == 0 && strcmp(to_unit, "kg") == 0) {
        return value / 1000;
    } else if (strcmp(from_unit, "l") == 0 && strcmp(to_unit, "ml") == 0) {
        return value * 1000;
    } else if (strcmp(from_unit, "ml") == 0 && strcmp(to_unit, "l") == 0) {
        return value / 1000;
    } else {
        printf("Invalid unit conversion.\n");
        exit(1);
    }
}

// Function to get user input for value and units
void get_input(double *value, char from_unit[MAX_UNITS], char to_unit[MAX_UNITS]) {
    printf("Enter the value to be converted: ");
    scanf("%lf", value);
    printf("Enter the unit of the value: ");
    scanf("%s", from_unit);
    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);
}

// Function to display results
void display_result(double result) {
    printf("The converted value is: %.2lf\n", result);
}

int main() {
    double value;
    char from_unit[MAX_UNITS], to_unit[MAX_UNITS];

    // Get user input
    get_input(&value, from_unit, to_unit);

    // Convert value and display result
    double result = convert_value(value, from_unit, to_unit);
    display_result(result);

    return 0;
}