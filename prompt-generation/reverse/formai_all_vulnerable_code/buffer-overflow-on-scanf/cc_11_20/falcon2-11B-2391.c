//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <math.h>

double convert(double value, char from_unit, char to_unit) {
    double conversion_factor;
    double result = value;

    if (from_unit == 'T' && to_unit == 'F') {
        conversion_factor = 9.0 / 5.0 * pow(5.0, 1.0 / 9.0);
        result = value * conversion_factor;
    } else if (from_unit == 'T' && to_unit == 'C') {
        conversion_factor = 5.0 / 9.0 * pow(5.0, -1.0 / 9.0);
        result = value * conversion_factor;
    } else if (from_unit == 'L' && to_unit =='m') {
        conversion_factor = 1.0 / 1000.0;
        result = value * conversion_factor;
    } else if (from_unit == 'L' && to_unit == 'ft') {
        conversion_factor = 3.28084;
        result = value * conversion_factor;
    } else if (from_unit == 'L' && to_unit == 'yd') {
        conversion_factor = 1.09361;
        result = value * conversion_factor;
    } else if (from_unit == 'L' && to_unit =='mi') {
        conversion_factor = 0.000621371;
        result = value * conversion_factor;
    } else if (from_unit == 'M' && to_unit == 'g') {
        conversion_factor = 0.035274;
        result = value * conversion_factor;
    } else if (from_unit == 'M' && to_unit == 'kg') {
        conversion_factor = 1.0;
        result = value * conversion_factor;
    } else if (from_unit == 'V' && to_unit == 'L') {
        conversion_factor = 1.0;
        result = value * conversion_factor;
    } else if (from_unit == 'V' && to_unit =='ml') {
        conversion_factor = 0.001;
        result = value * conversion_factor;
    } else if (from_unit == 'V' && to_unit == 'gal') {
        conversion_factor = 3.78541;
        result = value * conversion_factor;
    } else {
        printf("Invalid input. Please enter a valid unit.\n");
        return -1.0;
    }

    return result;
}

int main() {
    double value, converted_value;
    char from_unit, to_unit;

    printf("Enter the value in the unit you want to convert from: ");
    scanf("%lf %c %c", &value, &from_unit, &to_unit);

    converted_value = convert(value, from_unit, to_unit);

    printf("Converted value: %.2f\n", converted_value);

    return 0;
}