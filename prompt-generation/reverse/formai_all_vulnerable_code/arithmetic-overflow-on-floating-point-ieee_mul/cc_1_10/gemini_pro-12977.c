//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define the unit conversion functions
double convert_length(double value, char from, char to) {
    if (from == 'm' && to == 'cm') {
        return value * 100;
    } else if (from == 'cm' && to == 'm') {
        return value / 100;
    } else {
        printf("Invalid unit conversion specified.\n");
        return 0;
    }
}

double convert_mass(double value, char from, char to) {
    if (from == 'kg' && to == 'g') {
        return value * 1000;
    } else if (from == 'g' && to == 'kg') {
        return value / 1000;
    } else {
        printf("Invalid unit conversion specified.\n");
        return 0;
    }
}

double convert_temperature(double value, char from, char to) {
    if (from == 'c' && to == 'f') {
        return (value * 9 / 5) + 32;
    } else if (from == 'f' && to == 'c') {
        return (value - 32) * 5 / 9;
    } else {
        printf("Invalid unit conversion specified.\n");
        return 0;
    }
}

// Define the main function
int main() {
    // Get the input from the user
    printf("Enter the value to be converted: ");
    double value;
    scanf("%lf", &value);

    printf("Enter the unit of the value (m/cm/kg/g/c/f): ");
    char from;
    scanf(" %c", &from);

    printf("Enter the desired unit (m/cm/kg/g/c/f): ");
    char to;
    scanf(" %c", &to);

    // Convert the value using the appropriate function
    double result;
    if (from == 'm' || from == 'cm') {
        result = convert_length(value, from, to);
    } else if (from == 'kg' || from == 'g') {
        result = convert_mass(value, from, to);
    } else if (from == 'c' || from == 'f') {
        result = convert_temperature(value, from, to);
    } else {
        printf("Invalid unit specified.\n");
        return 1;
    }

    // Print the result
    printf("The converted value is: %.2f %c\n", result, to);

    return 0;
}