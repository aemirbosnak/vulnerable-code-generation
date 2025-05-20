//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert units of measurement
void convert(double value, char from_unit, char to_unit) {
    switch (from_unit) {
        case 'm': // meters
            if (to_unit == 'cm') {
                value *= 100;
            } else if (to_unit == 'mm') {
                value *= 1000;
            } else {
                value *= 0.01;
            }
            break;
        case 'cm': // centimeters
            if (to_unit == 'm') {
                value /= 100;
            } else if (to_unit == 'mm') {
                value /= 10;
            } else {
                value /= 0.01;
            }
            break;
        case 'mm': // millimeters
            if (to_unit == 'm') {
                value /= 1000;
            } else if (to_unit == 'cm') {
                value /= 10;
            } else {
                value /= 0.01;
            }
            break;
        default:
            printf("Invalid unit: %c\n", from_unit);
            return;
    }
    printf("Value in %c is %f\n", to_unit, value);
}

int main() {
    double value = 50; // initialize value
    char from_unit = 'm'; // initialize unit
    char to_unit = 'cm'; // initialize unit to convert to

    do {
        printf("Enter value in %c: ", from_unit);
        scanf("%lf", &value);

        convert(value, from_unit, to_unit);

        printf("Enter new unit (m/cm/mm): ");
        scanf("%c", &from_unit);

        to_unit = from_unit; // switch units for next conversion
    } while (from_unit != 'm' && from_unit != 'cm' && from_unit != 'mm');

    return 0;
}