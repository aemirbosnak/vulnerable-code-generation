//FormAI DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>

int main() {
    int inUnit, outUnit, input;
    float output;

    // Ask for input unit
    printf("Select your input unit:\n1. Feet\n2. Inches\n3. Centimeters\n");
    scanf("%d", &inUnit);

    // Ask for output unit
    printf("Select your output unit:\n1. Feet\n2. Inches\n3. Centimeters\n");
    scanf("%d", &outUnit);

    // Ask for input value
    printf("Enter input value:\n");
    scanf("%d", &input);

    // Convert input to centimeters
    float centimeters;
    switch (inUnit) {
        case 1:
            centimeters = input * 30.48;
            break;
        case 2:
            centimeters = input * 2.54;
            break;
        case 3:
            centimeters = input;
            break;
        default:
            printf("Invalid input unit\n");
            return 1;
    }

    // Convert centimeters to output unit
    switch (outUnit) {
        case 1:
            output = centimeters / 30.48;
            break;
        case 2:
            output = centimeters / 2.54;
            break;
        case 3:
            output = centimeters;
            break;
        default:
            printf("Invalid output unit\n");
            return 1;
    }

    // Print result
    printf("%d %s = %.2f %s\n", input, (inUnit == 1) ? "feet" : (inUnit == 2) ? "inches" : "centimeters",
                                  output, (outUnit == 1) ? "feet" : (outUnit == 2) ? "inches" : "centimeters");
    return 0;
}