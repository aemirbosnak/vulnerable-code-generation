//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert units
void convert_units(double value, char from_unit, char to_unit) {
    switch (to_unit) {
        case'm': // Meters
            switch (from_unit) {
                case 'f': // Feet
                    value *= 0.3048;
                    break;
                case 'i': // Inches
                    value *= 0.0254;
                    break;
                case 'y': // Yards
                    value *= 0.9144;
                    break;
                default:
                    printf("Invalid unit conversion!\n");
                    exit(1);
            }
            break;
        case 'f': // Feet
            switch (from_unit) {
                case'm': // Meters
                    value /= 0.3048;
                    break;
                case 'i': // Inches
                    value /= 0.0254;
                    break;
                case 'y': // Yards
                    value /= 0.9144;
                    break;
                default:
                    printf("Invalid unit conversion!\n");
                    exit(1);
            }
            break;
        case 'i': // Inches
            switch (from_unit) {
                case'm': // Meters
                    value /= 0.3048;
                    break;
                case 'f': // Feet
                    value /= 0.0254;
                    break;
                case 'y': // Yards
                    value /= 0.9144;
                    break;
                default:
                    printf("Invalid unit conversion!\n");
                    exit(1);
            }
            break;
        case 'y': // Yards
            switch (from_unit) {
                case'm': // Meters
                    value /= 0.9144;
                    break;
                case 'f': // Feet
                    value /= 0.3048;
                    break;
                case 'i': // Inches
                    value /= 0.0254;
                    break;
                default:
                    printf("Invalid unit conversion!\n");
                    exit(1);
            }
            break;
        default:
            printf("Invalid unit conversion!\n");
            exit(1);
    }
    printf("%.2f %c = %.2f %c\n", value, from_unit, value, to_unit);
}

int main() {
    double value;
    char from_unit, to_unit;

    // Get user input
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the unit to convert from: ");
    scanf(" %c", &from_unit);
    printf("Enter the unit to convert to: ");
    scanf(" %c", &to_unit);

    // Convert units
    convert_units(value, from_unit, to_unit);

    return 0;
}