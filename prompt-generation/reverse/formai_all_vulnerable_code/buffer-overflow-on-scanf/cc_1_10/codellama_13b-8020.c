//Code Llama-13B DATASET v1.0 Category: Temperature Converter ; Style: Donald Knuth
/*
 * A unique C Temperature Converter example program in a Donald Knuth style
 *
 * This program converts a temperature from one scale to another.
 * The program supports the following temperature scales:
 * 1. Celsius (C)
 * 2. Fahrenheit (F)
 * 3. Kelvin (K)
 *
 * Usage:
 * 1. Run the program
 * 2. Enter the temperature value you want to convert
 * 3. Enter the temperature scale you want to convert from
 * 4. Enter the temperature scale you want to convert to
 * 5. The program will output the converted temperature value
 *
 * Author: [Your Name]
 */

#include <stdio.h>

int main() {
    float temperature;
    char scale_from;
    char scale_to;

    printf("Enter the temperature value: ");
    scanf("%f", &temperature);

    printf("Enter the temperature scale (C, F, or K): ");
    scanf(" %c", &scale_from);

    printf("Enter the temperature scale you want to convert to (C, F, or K): ");
    scanf(" %c", &scale_to);

    switch (scale_from) {
        case 'C':
            switch (scale_to) {
                case 'F':
                    temperature = (temperature * 9 / 5) + 32;
                    break;
                case 'K':
                    temperature += 273.15;
                    break;
            }
            break;
        case 'F':
            switch (scale_to) {
                case 'C':
                    temperature = (temperature - 32) * 5 / 9;
                    break;
                case 'K':
                    temperature = (temperature + 459.67) * 5 / 9;
                    break;
            }
            break;
        case 'K':
            switch (scale_to) {
                case 'C':
                    temperature -= 273.15;
                    break;
                case 'F':
                    temperature = (temperature - 273.15) * 9 / 5 + 32;
                    break;
            }
            break;
    }

    printf("The temperature is %f degrees %c.\n", temperature, scale_to);

    return 0;
}