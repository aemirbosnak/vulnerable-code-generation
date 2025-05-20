//FormAI DATASET v1.0 Category: Unit converter ; Style: Ada Lovelace
#include <stdio.h>

// function prototypes
void print_menu();
double convert_length(double value, int from_unit, int to_unit);
double convert_mass(double value, int from_unit, int to_unit);
double convert_temperature(double value, int from_unit, int to_unit);

int main() {
    int option, from_unit, to_unit;
    double value, result;

    print_menu();
    scanf("%d", &option);

    switch (option) {
        // length conversion
        case 1:
            printf("\nEnter the value and unit from (1. Feet, 2. Meter, 3. Kilometer, 4. Inch):\n");
            scanf("%lf %d", &value, &from_unit);
            printf("\nEnter the unit to convert (1. Feet, 2. Meter, 3. Kilometer, 4. Inch):\n");
            scanf("%d", &to_unit);
            result = convert_length(value, from_unit, to_unit);
            printf("\nResult: %.2lf\n", result);
            break;

        // mass conversion
        case 2:
            printf("\nEnter the value and unit from (1. Pound, 2. Kilogram, 3. Ounce, 4. Gram):\n");
            scanf("%lf %d", &value, &from_unit);
            printf("\nEnter the unit to convert (1. Pound, 2. Kilogram, 3. Ounce, 4. Gram):\n");
            scanf("%d", &to_unit);
            result = convert_mass(value, from_unit, to_unit);
            printf("\nResult: %.2lf\n", result);
            break;

        // temperature conversion
        case 3:
            printf("\nEnter the value and unit from (1. Celsius, 2. Fahrenheit, 3. Kelvin):\n");
            scanf("%lf %d", &value, &from_unit);
            printf("\nEnter the unit to convert (1. Celsius, 2. Fahrenheit, 3. Kelvin):\n");
            scanf("%d", &to_unit);
            result = convert_temperature(value, from_unit, to_unit);
            printf("\nResult: %.2lf\n", result);
            break;

        default:
            printf("\nError: Invalid option selected.\n");
            break;
    }

    return 0;
}

// prints the conversion menu
void print_menu() {
    printf("Select the type of conversion:\n");
    printf("\t1. Length\n");
    printf("\t2. Mass\n");
    printf("\t3. Temperature\n");
    printf("Enter your choice: ");
}

// converts between different length units
double convert_length(double value, int from_unit, int to_unit) {
    double factor = 1.0;

    // convert from input unit to feet
    switch (from_unit) {
        case 1: // feet
            break;
        case 2: // meter
            factor = 3.28084;
            break;
        case 3: // kilometer
            factor = 3280.84;
            break;
        case 4: // inch
            factor = 0.0833333;
            break;
        default:
            printf("\nError: Invalid unit selected.\n");
            return 0.0;
            break;
    }

    // convert from feet to output unit
    switch (to_unit) {
        case 1: // feet
            break;
        case 2: // meter
            factor *= 0.3048;
            break;
        case 3: // kilometer
            factor *= 0.0003048;
            break;
        case 4: // inch
            factor *= 12;
            break;
        default:
            printf("\nError: Invalid unit selected.\n");
            return 0.0;
            break;
    }

    return value * factor;
}

// converts between different mass units
double convert_mass(double value, int from_unit, int to_unit) {
    double factor = 1.0;

    // convert from input unit to pound
    switch (from_unit) {
        case 1: // pound
            break;
        case 2: // kilogram
            factor = 2.20462;
            break;
        case 3: // ounce
            factor = 0.0625;
            break;
        case 4: // gram
            factor = 0.00220462;
            break;
        default:
            printf("\nError: Invalid unit selected.\n");
            return 0.0;
            break;
    }

    // convert from pound to output unit
    switch (to_unit) {
        case 1: // pound
            break;
        case 2: // kilogram
            factor *= 0.453592;
            break;
        case 3: // ounce
            factor *= 16;
            break;
        case 4: // gram
            factor *= 453.592;
            break;
        default:
            printf("\nError: Invalid unit selected.\n");
            return 0.0;
            break;
    }

    return value * factor;
}

// converts between different temperature units
double convert_temperature(double value, int from_unit, int to_unit) {
    double result = 0.0;

    switch (from_unit) {
        case 1: // celsius
            if (to_unit == 2) {
                // celsius to fahrenheit
                result = (value * 1.8) + 32;
            }
            else if (to_unit == 3) {
                // celsius to kelvin
                result = value + 273.15;
            }
            break;
        case 2: // fahrenheit
            if (to_unit == 1) {
                // fahrenheit to celsius
                result = (value - 32) / 1.8;
            }
            else if (to_unit == 3) {
                // fahrenheit to kelvin
                result = (value + 459.67) / 1.8;
            }
            break;
        case 3: // kelvin
            if (to_unit == 1) {
                // kelvin to celsius
                result = value - 273.15;
            }
            else if (to_unit == 2) {
                // kelvin to fahrenheit
                result = (value * 1.8) - 459.67;
            }
            break;
        default:
            printf("\nError: Invalid unit selected.\n");
            return 0.0;
            break;
    }

    return result;
}