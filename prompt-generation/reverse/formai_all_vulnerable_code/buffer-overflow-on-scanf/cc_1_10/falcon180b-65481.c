//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert from one unit to another
void convert(double value, char from_unit, char to_unit) {
    if (from_unit =='m' && to_unit == 'ft') {
        value *= 3.28084;
    } else if (from_unit == 'ft' && to_unit =='m') {
        value /= 3.28084;
    } else if (from_unit == 'kg' && to_unit == 'lb') {
        value *= 2.20462;
    } else if (from_unit == 'lb' && to_unit == 'kg') {
        value /= 2.20462;
    } else if (from_unit == 'l' && to_unit == 'gal') {
        value *= 3.78541;
    } else if (from_unit == 'gal' && to_unit == 'l') {
        value /= 3.78541;
    } else {
        printf("Invalid unit conversion\n");
    }
}

// Function to print the conversion result
void print_result(double value, char from_unit, char to_unit) {
    printf("%.2f %c = %.2f %c\n", value, from_unit, value, to_unit);
}

// Function to get user input for the value, from unit and to unit
void get_input(double *value, char *from_unit, char *to_unit) {
    printf("Enter the value to convert: ");
    scanf("%lf", value);

    printf("Enter the unit to convert from (m, kg, l): ");
    scanf("%c", from_unit);

    printf("Enter the unit to convert to (ft, lb, gal): ");
    scanf("%c", to_unit);
}

int main() {
    double value;
    char from_unit, to_unit;

    // Get user input
    get_input(&value, &from_unit, &to_unit);

    // Convert the value and print the result
    convert(value, from_unit, to_unit);
    print_result(value, from_unit, to_unit);

    return 0;
}