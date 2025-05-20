//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Variables for input and output
    double input, output;
    char unit[10];

    // Prompt user for input
    printf("Enter a value to convert: ");
    scanf("%lf", &input);

    // Prompt user for input unit
    printf("Enter the input unit (e.g. meters, feet, etc.): ");
    scanf("%s", unit);

    // Prompt user for output unit
    printf("Enter the output unit (e.g. meters, feet, etc.): ");
    scanf("%s", unit);

    // Convert input to meters
    if (strcmp(unit, "meters")!= 0) {
        if (strcmp(unit, "feet") == 0) {
            input *= 0.3048;
        } else if (strcmp(unit, "inches") == 0) {
            input *= 0.0254;
        } else if (strcmp(unit, "yards") == 0) {
            input *= 0.9144;
        } else if (strcmp(unit, "miles") == 0) {
            input *= 160934.4;
        } else {
            printf("Invalid input unit.\n");
            return 1;
        }
    }

    // Convert output to meters
    if (strcmp(unit, "meters")!= 0) {
        if (strcmp(unit, "feet") == 0) {
            output = input / 0.3048;
        } else if (strcmp(unit, "inches") == 0) {
            output = input / 0.0254;
        } else if (strcmp(unit, "yards") == 0) {
            output = input / 0.9144;
        } else if (strcmp(unit, "miles") == 0) {
            output = input / 160934.4;
        } else {
            printf("Invalid output unit.\n");
            return 1;
        }
    } else {
        output = input;
    }

    // Print result
    printf("%.2lf %s = %.2lf %s\n", input, unit, output, unit);

    return 0;
}