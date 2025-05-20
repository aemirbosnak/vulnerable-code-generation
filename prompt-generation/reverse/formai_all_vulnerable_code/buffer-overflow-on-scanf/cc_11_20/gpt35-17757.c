//FormAI DATASET v1.0 Category: Unit converter ; Style: Donald Knuth
/*
 * Donald Knuth Style C Unit Converter Example Program
 *
 * Description:
 * This program converts a given input value from one unit to another.
 * The available units for conversion are length units (km, m, cm, mm),
 * temperature units (Celsius, Fahrenheit, Kelvin), and weight units
 * (kg, g, mg). The program prompts the user for the input value and the
 * input and output units. It then converts the value to the output unit
 * and prints the result.
 *
 * Author: [Your Name]
 */

#include <stdio.h>

int main(void)
{
    /* Variables */
    float input, output;

    /* Prompt user for input value */
    printf("Enter the input value: ");
    scanf("%f", &input);

    /* Prompt user for input unit */
    printf("Enter the input unit (km/m/cm/mm/C/F/K/kg/g/mg): ");
    char input_unit[3];
    scanf("%s", input_unit);

    /* Prompt user for output unit */
    printf("Enter the output unit (km/m/cm/mm/C/F/K/kg/g/mg): ");
    char output_unit[3];
    scanf("%s", output_unit);

    /* Convert input to standard units */
    if (strcmp(input_unit, "km") == 0) {
        input *= 1000;
    } else if (strcmp(input_unit, "cm") == 0) {
        input /= 100;
    } else if (strcmp(input_unit, "mm") == 0) {
        input /= 1000;
    } else if (strcmp(input_unit, "F") == 0) {
        input = (input - 32) * 5 / 9;
    } else if (strcmp(input_unit, "K") == 0) {
        input -= 273.15;
    } else if (strcmp(input_unit, "g") == 0) {
        input /= 1000;
    } else if (strcmp(input_unit, "mg") == 0) {
        input /= 1000000;
    }

    /* Convert standard units to output */
    if (strcmp(output_unit, "km") == 0) {
        output = input / 1000;
    } else if (strcmp(output_unit, "cm") == 0) {
        output = input * 100;
    } else if (strcmp(output_unit, "mm") == 0) {
        output = input * 1000;
    } else if (strcmp(output_unit, "F") == 0) {
        output = (input * 9 / 5) + 32;
    } else if (strcmp(output_unit, "K") == 0) {
        output = input + 273.15;
    } else if (strcmp(output_unit, "g") == 0) {
        output = input * 1000;
    } else if (strcmp(output_unit, "mg") == 0) {
        output = input * 1000000;
    }

    /* Print result */
    printf("%f %s is equal to %f %s\n", input, input_unit, output, output_unit);

    return 0;
}