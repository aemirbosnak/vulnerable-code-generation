//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: recursive
#include <stdio.h>

// Function to convert units
double convert_units(double value, char from_unit, char to_unit) {
    if (from_unit =='m' && to_unit == 'ft') {
        return value * 3.28084;
    } else if (from_unit == 'ft' && to_unit =='m') {
        return value / 3.28084;
    } else if (from_unit == 'kg' && to_unit == 'lb') {
        return value * 2.20462;
    } else if (from_unit == 'lb' && to_unit == 'kg') {
        return value / 2.20462;
    } else if (from_unit == 'c' && to_unit == 'f') {
        return (value * 9 / 5) + 32;
    } else if (from_unit == 'f' && to_unit == 'c') {
        return (value - 32) * 5 / 9;
    } else {
        printf("Invalid unit conversion.\n");
        return 0;
    }
}

// Recursive function to convert units
double recursive_convert_units(double value, char from_unit, char to_unit, int iterations) {
    if (iterations == 0) {
        return value;
    } else {
        char temp_unit ='m';
        if (from_unit == 'ft') {
            temp_unit = 'ft';
        } else if (from_unit == 'kg') {
            temp_unit = 'lb';
        } else if (from_unit == 'c') {
            temp_unit = 'f';
        }
        return recursive_convert_units(convert_units(value, from_unit, temp_unit), temp_unit, to_unit, iterations - 1);
    }
}

int main() {
    double value;
    char from_unit, to_unit;
    int iterations;

    printf("Enter the value to be converted: ");
    scanf("%lf", &value);

    printf("Enter the unit of the value (m/ft/kg/lb/c/f): ");
    scanf(" %c", &from_unit);

    printf("Enter the unit to convert to (m/ft/kg/lb/c/f): ");
    scanf(" %c", &to_unit);

    printf("Enter the number of iterations (1-10): ");
    scanf("%d", &iterations);

    printf("The converted value is: %.2lf\n", recursive_convert_units(value, from_unit, to_unit, iterations));

    return 0;
}