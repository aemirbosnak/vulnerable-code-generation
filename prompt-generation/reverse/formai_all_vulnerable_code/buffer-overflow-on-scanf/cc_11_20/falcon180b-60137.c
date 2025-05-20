//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main() {
    double value, result;
    char unit, fromUnit, toUnit;

    // Get the value and unit from user
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the unit of the value: ");
    scanf(" %c", &unit);

    // Get the unit to convert to
    printf("Enter the unit to convert to: ");
    scanf(" %c", &toUnit);

    // Convert the value to the desired unit
    switch(toUnit) {
        case'm': // meters
            result = value;
            break;
        case 'cm': // centimeters
            result = value * 100;
            break;
        case'mm': // millimeters
            result = value * 1000;
            break;
        case 'km': // kilometers
            result = value / 1000;
            break;
        case'mi': // miles
            result = value * 0.000621371;
            break;
        case 'ft': // feet
            result = value * 3.28084;
            break;
        case 'in': // inches
            result = value * 39.3701;
            break;
        case 'yd': // yards
            result = value * 1.09361;
            break;
        case 'lb': // pounds
            result = value * 2.20462;
            break;
        case 'kg': // kilograms
            result = value * 0.453592;
            break;
        case 'g': // grams
            result = value * 1000;
            break;
        case'mg': // milligrams
            result = value * 1000000;
            break;
        case 'oz': // ounces
            result = value * 35.274;
            break;
        case 'l': // liters
            result = value * 1000;
            break;
        case'ml': // milliliters
            result = value * 1000000;
            break;
        case 'gal': // gallons
            result = value * 3.78541;
            break;
        case 'fl oz': // fluid ounces
            result = value * 33.814;
            break;
        case 'c': // Celsius
            result = value + 32;
            break;
        case 'f': // Fahrenheit
            result = (value * 9/5) + 32;
            break;
        default:
            printf("Invalid unit.\n");
            return 0;
    }

    // Print the result
    printf("%.2lf %c = %.2lf %c\n", value, unit, result, toUnit);

    return 0;
}