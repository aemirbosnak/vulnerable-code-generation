//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>
#include <math.h>

// Function to convert a value from one unit to another
double convert(double value, char from_unit, char to_unit) {
    double result = value;

    // Convert length units
    if (from_unit =='m' && to_unit == 'ft') {
        result = value * 3.28084;
    } else if (from_unit == 'ft' && to_unit =='m') {
        result = value / 3.28084;
    }

    // Convert weight units
    else if (from_unit == 'kg' && to_unit == 'lb') {
        result = value * 2.20462;
    } else if (from_unit == 'lb' && to_unit == 'kg') {
        result = value / 2.20462;
    }

    // Convert temperature units
    else if (from_unit == 'C' && to_unit == 'F') {
        result = (value * 9.0 / 5.0) + 32;
    } else if (from_unit == 'F' && to_unit == 'C') {
        result = (value - 32) * 5.0 / 9.0;
    }

    return result;
}

int main() {
    double value;
    char from_unit, to_unit;

    // Get user input
    printf("Enter a value: ");
    scanf("%lf", &value);

    printf("Enter the unit you want to convert from: ");
    scanf(" %c", &from_unit);

    printf("Enter the unit you want to convert to: ");
    scanf(" %c", &to_unit);

    // Convert the value and display the result
    double result = convert(value, from_unit, to_unit);
    printf("%.2lf %c is equal to %.2lf %c\n", value, from_unit, result, to_unit);

    return 0;
}