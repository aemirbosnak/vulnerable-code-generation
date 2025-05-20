//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert units of length
void length_convert(double value, const char *from_unit, const char *to_unit) {
    double converted_value;

    switch (from_unit[0]) {
        case 'm':
            converted_value = value / 1000.0;
            break;
        case 'cm':
            converted_value = value / 100.0;
            break;
        case 'mm':
            converted_value = value;
            break;
        default:
            fprintf(stderr, "Invalid input unit\n");
            return;
    }

    switch (to_unit[0]) {
        case 'm':
            converted_value *= 1000.0;
            break;
        case 'cm':
            converted_value *= 100.0;
            break;
        case 'mm':
            converted_value;
            break;
        default:
            fprintf(stderr, "Invalid output unit\n");
            return;
    }

    printf("Converted value: %f %s\n", converted_value, to_unit);
}

// Function to convert units of weight
void weight_convert(double value, const char *from_unit, const char *to_unit) {
    double converted_value;

    switch (from_unit[0]) {
        case 'g':
            converted_value = value / 1000.0;
            break;
        case 'kg':
            converted_value = value;
            break;
        default:
            fprintf(stderr, "Invalid input unit\n");
            return;
    }

    switch (to_unit[0]) {
        case 'g':
            converted_value *= 1000.0;
            break;
        case 'kg':
            converted_value;
            break;
        default:
            fprintf(stderr, "Invalid output unit\n");
            return;
    }

    printf("Converted value: %f %s\n", converted_value, to_unit);
}

int main() {
    double value;
    char from_unit[3];
    char to_unit[3];

    printf("Enter value: ");
    scanf("%lf", &value);

    printf("Enter from unit (m/cm/mm or g/kg): ");
    scanf("%2s", from_unit);

    printf("Enter to unit (m/cm/mm or g/kg): ");
    scanf("%2s", to_unit);

    length_convert(value, from_unit, to_unit);
    weight_convert(value, from_unit, to_unit);

    return 0;
}