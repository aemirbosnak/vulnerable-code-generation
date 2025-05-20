//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define the unit conversion functions
double convert_length(double value, char from_unit, char to_unit) {
    // Convert the value from the from_unit to the to_unit
    if (from_unit == 'm' && to_unit == 'cm') {
        return value * 100;
    } else if (from_unit == 'cm' && to_unit == 'm') {
        return value / 100;
    } else if (from_unit == 'm' && to_unit == 'in') {
        return value * 39.3701;
    } else if (from_unit == 'in' && to_unit == 'm') {
        return value / 39.3701;
    } else {
        printf("Unsupported unit conversion\n");
        return -1;
    }
}

double convert_weight(double value, char from_unit, char to_unit) {
    // Convert the value from the from_unit to the to_unit
    if (from_unit == 'kg' && to_unit == 'g') {
        return value * 1000;
    } else if (from_unit == 'g' && to_unit == 'kg') {
        return value / 1000;
    } else if (from_unit == 'kg' && to_unit == 'lb') {
        return value * 2.20462;
    } else if (from_unit == 'lb' && to_unit == 'kg') {
        return value / 2.20462;
    } else {
        printf("Unsupported unit conversion\n");
        return -1;
    }
}

double convert_volume(double value, char from_unit, char to_unit) {
    // Convert the value from the from_unit to the to_unit
    if (from_unit == 'l' && to_unit == 'ml') {
        return value * 1000;
    } else if (from_unit == 'ml' && to_unit == 'l') {
        return value / 1000;
    } else if (from_unit == 'l' && to_unit == 'gal') {
        return value * 0.264172;
    } else if (from_unit == 'gal' && to_unit == 'l') {
        return value / 0.264172;
    } else {
        printf("Unsupported unit conversion\n");
        return -1;
    }
}

// Define the main function
int main() {
    // Get the user input
    printf("Enter the value to convert: ");
    double value;
    scanf("%lf", &value);

    printf("Enter the from unit (m, cm, in, kg, g, lb, l, ml, gal): ");
    char from_unit;
    scanf(" %c", &from_unit);

    printf("Enter the to unit (m, cm, in, kg, g, lb, l, ml, gal): ");
    char to_unit;
    scanf(" %c", &to_unit);

    // Convert the value
    double converted_value;
    if (from_unit == 'm' || from_unit == 'cm' || from_unit == 'in') {
        converted_value = convert_length(value, from_unit, to_unit);
    } else if (from_unit == 'kg' || from_unit == 'g' || from_unit == 'lb') {
        converted_value = convert_weight(value, from_unit, to_unit);
    } else if (from_unit == 'l' || from_unit == 'ml' || from_unit == 'gal') {
        converted_value = convert_volume(value, from_unit, to_unit);
    } else {
        printf("Unsupported unit conversion\n");
        return -1;
    }

    // Print the converted value
    printf("The converted value is: %.2f %c\n", converted_value, to_unit);

    return 0;
}