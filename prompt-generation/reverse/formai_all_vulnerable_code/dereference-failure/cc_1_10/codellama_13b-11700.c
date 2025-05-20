//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: modular
/*
 * unit_converter.c
 *
 * A program to convert between different units of measurement.
 *
 * Usage:
 *   unit_converter <unit1> <unit2> <value>
 *
 * Example:
 *   unit_converter cm in 10
 *   unit_converter km m 100
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the conversion factors for each unit
const double cm_to_in = 0.393700787;
const double in_to_cm = 2.54;
const double km_to_m = 1000;
const double m_to_km = 0.001;

// Define the unit types
enum unit_type {
    CM,
    IN,
    KM,
    M
};

// Define the conversion function
double convert(double value, enum unit_type unit1, enum unit_type unit2) {
    double result;

    switch (unit1) {
        case CM:
            switch (unit2) {
                case IN:
                    result = value * cm_to_in;
                    break;
                case KM:
                    result = value * cm_to_in * in_to_cm * km_to_m;
                    break;
                case M:
                    result = value * cm_to_in * in_to_cm;
                    break;
                default:
                    result = 0.0;
                    break;
            }
            break;
        case IN:
            switch (unit2) {
                case CM:
                    result = value * in_to_cm;
                    break;
                case KM:
                    result = value * in_to_cm * km_to_m;
                    break;
                case M:
                    result = value * in_to_cm / 1000;
                    break;
                default:
                    result = 0.0;
                    break;
            }
            break;
        case KM:
            switch (unit2) {
                case CM:
                    result = value * km_to_m * 100000;
                    break;
                case IN:
                    result = value * km_to_m * 39370.0787;
                    break;
                case M:
                    result = value * km_to_m;
                    break;
                default:
                    result = 0.0;
                    break;
            }
            break;
        case M:
            switch (unit2) {
                case CM:
                    result = value * 100;
                    break;
                case IN:
                    result = value * 39.3700787;
                    break;
                case KM:
                    result = value / 1000;
                    break;
                default:
                    result = 0.0;
                    break;
            }
            break;
        default:
            result = 0.0;
            break;
    }

    return result;
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 4) {
        printf("Usage: %s <unit1> <unit2> <value>\n", argv[0]);
        return 1;
    }

    // Get the unit types
    enum unit_type unit1 = atoi(argv[1]);
    enum unit_type unit2 = atoi(argv[2]);

    // Get the value to convert
    double value = atof(argv[3]);

    // Convert the value
    double result = convert(value, unit1, unit2);

    // Print the result
    printf("%f %s = %f %s\n", value, unit1, result, unit2);

    return 0;
}