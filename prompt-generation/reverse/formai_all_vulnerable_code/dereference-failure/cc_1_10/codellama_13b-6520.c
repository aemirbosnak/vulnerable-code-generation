//Code Llama-13B DATASET v1.0 Category: Temperature Converter ; Style: funny
/*
 * Temperature Converter - Funny Edition
 *
 * Converts Celsius, Fahrenheit, and Kelvin temperatures.
 *
 * Usage:
 *  -c <Celsius temperature>  Converts Celsius to Fahrenheit and Kelvin
 *  -f <Fahrenheit temperature>  Converts Fahrenheit to Celsius and Kelvin
 *  -k <Kelvin temperature>  Converts Kelvin to Celsius and Fahrenheit
 *
 * Example:
 *  $ ./tempconverter -c 25
 *  Celsius: 25°C
 *  Fahrenheit: 77°F
 *  Kelvin: 298.15K
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    float celsius, fahrenheit, kelvin;
    char unit;

    if (argc < 3) {
        printf("Usage: %s -c <Celsius temperature> | -f <Fahrenheit temperature> | -k <Kelvin temperature>\n", argv[0]);
        return 1;
    }

    unit = argv[1][1];

    switch (unit) {
        case 'c':
            celsius = atof(argv[2]);
            fahrenheit = (celsius * 9 / 5) + 32;
            kelvin = celsius + 273.15;
            break;
        case 'f':
            fahrenheit = atof(argv[2]);
            celsius = (fahrenheit - 32) * 5 / 9;
            kelvin = (fahrenheit + 459.67) * 5 / 9;
            break;
        case 'k':
            kelvin = atof(argv[2]);
            celsius = kelvin - 273.15;
            fahrenheit = (kelvin - 459.67) * 9 / 5;
            break;
        default:
            printf("Invalid unit '%c'.\n", unit);
            return 1;
    }

    printf("Celsius: %.1f°C\n", celsius);
    printf("Fahrenheit: %.1f°F\n", fahrenheit);
    printf("Kelvin: %.1fK\n", kelvin);

    return 0;
}