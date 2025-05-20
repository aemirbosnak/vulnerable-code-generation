//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>
#include <math.h>
#include <ctype.h>

// Function to convert length units
float convertLength(char unit) {
    switch (unit) {
        case'm':
            return 1;
        case 'cm':
            return 0.01;
        case 'km':
            return 1000;
        case 'in':
            return 2.54;
        case 'ft':
            return 0.3048;
        case 'yd':
            return 1.094;
        case'mi':
            return 1609.34;
        default:
            return 0;
    }
}

// Function to convert weight units
float convertWeight(char unit) {
    switch (unit) {
        case 'g':
            return 1;
        case 'kg':
            return 1000;
        case 'oz':
            return 0.0283495;
        case 'lb':
            return 0.453592;
        case 't':
            return 1000;
        case 'p':
            return 1000;
        default:
            return 0;
    }
}

// Function to convert temperature units
float convertTemperature(char unit) {
    switch (unit) {
        case 'c':
            return 1;
        case 'f':
            return 1.8 + 0.0312 * pow(9.0, -5.0);
        case 'k':
            return 273.15;
        case 'r':
            return 0;
        default:
            return 0;
    }
}

int main() {
    char input[10];
    char output[10];
    char unit;

    // Prompt the user for input
    printf("Enter a value and unit: ");
    scanf("%s", input);

    // Convert the input to a float
    float value = atof(input);

    // Get the unit from the input
    unit = input[strlen(input) - 1];

    // Convert the value to the desired unit
    float convertedValue = value;
    switch (unit) {
        case'm':
            convertedValue *= convertLength(unit);
            break;
        case 'g':
            convertedValue *= convertWeight(unit);
            break;
        case 'c':
            convertedValue *= convertTemperature(unit);
            break;
        default:
            printf("Invalid unit.\n");
            return 1;
    }

    // Format the output string
    snprintf(output, sizeof(output), "%.2f %s", convertedValue, unit);

    // Print the output
    printf("Converted value: %s\n", output);

    return 0;
}