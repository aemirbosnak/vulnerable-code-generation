//Code Llama-13B DATASET v1.0 Category: Temperature Converter ; Style: enthusiastic
/*
*  C Temperature Converter
*  by [Your Name]
*
*  This program converts a temperature from one scale to another.
*  It is a simple command-line program that takes the temperature and
*  the scale as arguments, and then converts it to the specified scale.
*
*  Usage:
*    ./temperature <temperature> <scale>
*
*  Examples:
*    ./temperature 32 F
*    ./temperature 22.2 C
*    ./temperature 100 K
*
*  Supported scales:
*    C: Celsius
*    F: Fahrenheit
*    K: Kelvin
*/

#include <stdio.h>
#include <stdlib.h>

// Define the scales
#define CELSIUS 'C'
#define FAHRENHEIT 'F'
#define KELVIN 'K'

// Define the conversion factors
#define C_TO_F 9.0 / 5.0
#define C_TO_K 273.15
#define F_TO_C 5.0 / 9.0
#define F_TO_K 459.67
#define K_TO_C -273.15
#define K_TO_F -459.67

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: ./temperature <temperature> <scale>\n");
        return 1;
    }

    // Get the temperature and scale from the command line
    double temperature = atof(argv[1]);
    char scale = argv[2][0];

    // Convert the temperature
    double converted_temperature = 0.0;
    switch (scale) {
        case CELSIUS:
            converted_temperature = temperature;
            break;
        case FAHRENHEIT:
            converted_temperature = temperature * C_TO_F;
            break;
        case KELVIN:
            converted_temperature = temperature + K_TO_C;
            break;
        default:
            printf("Error: invalid scale\n");
            return 1;
    }

    // Print the converted temperature
    printf("Converted temperature: %.2f\n", converted_temperature);

    return 0;
}