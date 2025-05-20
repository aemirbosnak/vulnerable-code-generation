//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define E 2.71828182845904523536

// Convert degrees to radians
double deg2rad(double deg) {
    return deg * PI / 180;
}

// Convert radians to degrees
double rad2deg(double rad) {
    return rad * 180 / PI;
}

// Convert meters to feet
double m2ft(double m) {
    return m * 3.28084;
}

// Convert feet to meters
double ft2m(double ft) {
    return ft / 3.28084;
}

// Convert pounds to kilograms
double lb2kg(double lb) {
    return lb * 0.453592;
}

// Convert kilograms to pounds
double kg2lb(double kg) {
    return kg / 0.453592;
}

// Convert gallons to liters
double gal2l(double gal) {
    return gal * 3.78541;
}

// Convert liters to gallons
double l2gal(double l) {
    return l / 3.78541;
}

// Convert Celsius to Fahrenheit
double c2f(double c) {
    return c * 9 / 5 + 32;
}

// Convert Fahrenheit to Celsius
double f2c(double f) {
    return (f - 32) * 5 / 9;
}

int main() {
    // Get the input values
    double value, from_unit, to_unit;
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the unit to convert from (e.g., m, ft, lb, kg, gal, l, c, f): ");
    scanf("%lf", &from_unit);
    printf("Enter the unit to convert to (e.g., m, ft, lb, kg, gal, l, c, f): ");
    scanf("%lf", &to_unit);

    // Convert the value
    double converted_value;
    if (from_unit == 'm' && to_unit == 'ft') {
        converted_value = m2ft(value);
    } else if (from_unit == 'ft' && to_unit == 'm') {
        converted_value = ft2m(value);
    } else if (from_unit == 'lb' && to_unit == 'kg') {
        converted_value = lb2kg(value);
    } else if (from_unit == 'kg' && to_unit == 'lb') {
        converted_value = kg2lb(value);
    } else if (from_unit == 'gal' && to_unit == 'l') {
        converted_value = gal2l(value);
    } else if (from_unit == 'l' && to_unit == 'gal') {
        converted_value = l2gal(value);
    } else if (from_unit == 'c' && to_unit == 'f') {
        converted_value = c2f(value);
    } else if (from_unit == 'f' && to_unit == 'c') {
        converted_value = f2c(value);
    } else {
        printf("Invalid unit conversion specified.\n");
        return 1;
    }

    // Print the converted value
    printf("The converted value is: %lf\n", converted_value);

    return 0;
}