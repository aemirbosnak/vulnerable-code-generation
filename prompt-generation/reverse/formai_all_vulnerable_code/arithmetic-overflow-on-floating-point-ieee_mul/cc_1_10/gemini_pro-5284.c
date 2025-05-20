//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables
    double input, output;
    char inputUnit, outputUnit;

    // Get input from user
    printf("Enter the value to be converted: ");
    scanf("%lf", &input);
    printf("Enter the input unit (e.g., cm, m, in, ft): ");
    scanf(" %c", &inputUnit);
    printf("Enter the output unit (e.g., cm, m, in, ft): ");
    scanf(" %c", &outputUnit);

    // Convert input to base units (meters)
    switch (inputUnit) {
        case 'c':
            input *= 0.01;
            break;
        case 'i':
            input *= 0.0254;
            break;
        case 'f':
            input *= 0.3048;
            break;
    }

    // Convert from base units (meters) to output units
    switch (outputUnit) {
        case 'c':
            output = input * 100;
            break;
        case 'i':
            output = input * 39.3701;
            break;
        case 'f':
            output = input * 3.28084;
            break;
        case 'm':
            output = input;
            break;
    }

    // Print the output
    printf("The converted value is: %.2lf %c\n", output, outputUnit);

    return 0;
}