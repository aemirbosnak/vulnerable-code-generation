//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

// Function to convert from one unit to another
double convert(char from_unit[MAX_UNITS], char to_unit[MAX_UNITS]) {
    if (strcmp(from_unit, "m") == 0 && strcmp(to_unit, "km") == 0) {
        return 0.001;
    } else if (strcmp(from_unit, "km") == 0 && strcmp(to_unit, "m") == 0) {
        return 1000;
    } else if (strcmp(from_unit, "m") == 0 && strcmp(to_unit, "cm") == 0) {
        return 100;
    } else if (strcmp(from_unit, "cm") == 0 && strcmp(to_unit, "m") == 0) {
        return 0.01;
    } else if (strcmp(from_unit, "kg") == 0 && strcmp(to_unit, "lb") == 0) {
        return 2.20462;
    } else if (strcmp(from_unit, "lb") == 0 && strcmp(to_unit, "kg") == 0) {
        return 0.453592;
    } else if (strcmp(from_unit, "l") == 0 && strcmp(to_unit, "gal") == 0) {
        return 0.264172;
    } else if (strcmp(from_unit, "gal") == 0 && strcmp(to_unit, "l") == 0) {
        return 3.78541;
    } else if (strcmp(from_unit, "C") == 0 && strcmp(to_unit, "F") == 0) {
        return 1.8;
    } else if (strcmp(from_unit, "F") == 0 && strcmp(to_unit, "C") == 0) {
        return 0.5555556;
    } else {
        return 1.0;
    }
}

int main() {
    char from_unit[MAX_UNITS];
    char to_unit[MAX_UNITS];
    double value;
    double result;

    // Get the input from the user
    printf("Enter the unit you want to convert from: ");
    scanf("%s", from_unit);
    printf("Enter the unit you want to convert to: ");
    scanf("%s", to_unit);
    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    // Convert the value and display the result
    result = convert(from_unit, to_unit) * value;
    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);

    return 0;
}