//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the supported units and their symbols
#define UNIT_NONE  0x00000000
#define UNIT_METric 0x00000001
#define UNIT_Centi 0x00000010
#define UNIT_Mili 0x00000100
#define UNIT_Micro 0x00001000
#define UNIT_Nano 0x00010000
#define UNIT_Pico 0x00100000
#define UNIT_Femto 0x01000000
#define UNIT_Atto 0x10000000

// Define the unit conversion table
#define CONV_NONE  0
#define CONV_METric 1
#define CONV_Centi 2
#define CONV_Mili 3
#define CONV_Micro 4
#define CONV_Nano 5
#define CONV_Pico 6
#define CONV_Femto 7
#define CONV_Atto 8

// Function to convert a value from one unit to another
int convert_unit(int value, int from_unit, int to_unit) {
    int factor = 1;

    switch (from_unit) {
        case UNIT_NONE:
            break;
        case UNIT_METric:
            factor = 1000;
            break;
        case UNIT_Centi:
            factor = 100;
            break;
        case UNIT_Mili:
            factor = 10;
            break;
        case UNIT_Micro:
            factor = 0.1;
            break;
        case UNIT_Nano:
            factor = 0.01;
            break;
        case UNIT_Pico:
            factor = 0.001;
            break;
        case UNIT_Femto:
            factor = 0.0001;
            break;
        case UNIT_Atto:
            factor = 0.00001;
            break;
    }

    switch (to_unit) {
        case UNIT_NONE:
            break;
        case UNIT_METric:
            return value * factor;
        case UNIT_Centi:
            return value * factor / 100;
        case UNIT_Mili:
            return value * factor / 10;
        case UNIT_Micro:
            return value * factor / 0.1;
        case UNIT_Nano:
            return value * factor / 0.01;
        case UNIT_Pico:
            return value * factor / 0.001;
        case UNIT_Femto:
            return value * factor / 0.0001;
        case UNIT_Atto:
            return value * factor / 0.00001;
    }

    return -1; // invalid input
}

int main() {
    int value, from_unit, to_unit;

    // Example usage
    printf("Enter a value in meters (m): ");
    scanf("%d", &value);

    // Convert to other units
    from_unit = UNIT_METric;
    to_unit = UNIT_Centi;
    value = convert_unit(value, from_unit, to_unit);
    printf("Value in centimeters (cm): %d\n", value);

    from_unit = UNIT_Centi;
    to_unit = UNIT_Mili;
    value = convert_unit(value, from_unit, to_unit);
    printf("Value in millimeters (mm): %d\n", value);

    return 0;
}