//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 5
#define MAX_VALUE 100000

// Function to convert units
void convert_units(int value, char *from_unit, char *to_unit) {
    int factor = 1;
    switch (from_unit[0]) {
        case 'm':
            factor = 1000;
            break;
        case 'cm':
            factor = 100;
            break;
        case 'mm':
            factor = 10;
            break;
        case 'km':
            factor = 100000;
            break;
        default:
            printf("Error: Unknown unit %s\n", from_unit);
            return;
    }
    switch (to_unit[0]) {
        case 'm':
            value *= factor;
            break;
        case 'cm':
            value *= 100 / factor;
            break;
        case 'mm':
            value *= 1000 / factor;
            break;
        case 'km':
            value /= factor;
            break;
        default:
            printf("Error: Unknown unit %s\n", to_unit);
            return;
    }
    printf("Value in %s is %d\n", to_unit, value);
}

int main() {
    int value, from_unit, to_unit;
    char from_unit_str[5];
    char to_unit_str[5];

    // Get the value to convert
    printf("Enter a value: ");
    scanf("%d", &value);

    // Get the from unit
    printf("Enter the from unit (m/cm/mm/km): ");
    scanf("%4s", from_unit_str);

    // Get the to unit
    printf("Enter the to unit (m/cm/mm/km): ");
    scanf("%4s", to_unit_str);

    // Convert the value
    convert_units(value, from_unit_str, to_unit_str);

    return 0;
}