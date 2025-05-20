//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert between different units of measurement
void convert(char *input, char *output, double value) {
    // Define a list of common unit conversions
    static const char *units[] = {
        "cm", "m", "km", "ft", "in", "yd", "mi", "km", "deg", "rad",
        "s", "min", "hr", "d", "wk", "mo", "yr"
    };
    int i, j;

    // Check if the input unit is valid
    for (i = 0; i < sizeof(units) / sizeof(units[0]); i++) {
        if (strcasecmp(input, units[i]) == 0) {
            break;
        }
    }

    // If the input unit is not valid, print an error message
    if (i == sizeof(units) / sizeof(units[0])) {
        printf("Invalid unit: %s\n", input);
        return;
    }

    // Convert the value to the corresponding unit
    for (j = i + 1; j < sizeof(units) / sizeof(units[0]); j++) {
        if (strcasecmp(units[j], output) == 0) {
            break;
        }
    }

    // If the output unit is not found, print an error message
    if (j == sizeof(units) / sizeof(units[0])) {
        printf("Invalid output unit: %s\n", output);
        return;
    }

    // Perform the conversion
    switch (i) {
        case 0: // cm
            value *= 0.01;
            break;
        case 1: // m
            value *= 0.001;
            break;
        case 2: // km
            value *= 0.000001;
            break;
        case 3: // ft
            value *= 0.0003048;
            break;
        case 4: // in
            value *= 0.00003048;
            break;
        case 5: // yd
            value *= 0.00036088;
            break;
        case 6: // mi
            value *= 0.00000036;
            break;
        case 7: // rad
            value *= 0.01745329;
            break;
        case 8: // s
            value *= 3.6;
            break;
        case 9: // min
            value *= 60;
            break;
        case 10: // hr
            value *= 3600;
            break;
        case 11: // d
            value *= 86400;
            break;
        case 12: // wk
            value *= 604800;
            break;
        case 13: // mo
            value *= 2629743;
            break;
        case 14: // yr
            value *= 31536000;
            break;
        default:
            break;
    }

    // Print the result in the desired unit
    printf("%.2f %s = %.2f %s\n", value, input, value, output);
}

int main() {
    double value;
    char input[50], output[50];

    // Get the input value and unit from the user
    printf("Enter a value: ");
    scanf("%lf", &value);
    printf("Enter a unit: ");
    fgets(input, 50, stdin);
    printf("Enter an output unit: ");
    fgets(output, 50, stdin);

    // Call the convert function
    convert(input, output, value);

    return 0;
}