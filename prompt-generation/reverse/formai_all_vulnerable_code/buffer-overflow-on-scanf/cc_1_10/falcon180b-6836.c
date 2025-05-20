//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert units
int convert_unit(char* input, char* unit, char* output_unit) {
    double value = 0.0;
    char* endptr = NULL;

    // Convert input string to a number
    value = strtod(input, &endptr);

    // Check if input string is a number
    if (endptr == NULL) {
        printf("Error: Invalid input\n");
        return 1;
    }

    // Convert units
    switch (unit[0]) {
        case'm':
            // Convert meters to feet
            value *= 3.28084;
            strcpy(output_unit, "ft");
            break;
        case 'f':
            // Convert feet to meters
            value /= 3.28084;
            strcpy(output_unit, "m");
            break;
        case 'k':
            // Convert kilograms to pounds
            value *= 2.20462;
            strcpy(output_unit, "lb");
            break;
        case 'p':
            // Convert pounds to kilograms
            value /= 2.20462;
            strcpy(output_unit, "kg");
            break;
        default:
            printf("Error: Invalid unit\n");
            return 1;
    }

    // Format output string
    printf("%.2f %s = %.2f %s\n", value, unit, value, output_unit);

    return 0;
}

int main() {
    char input[100];
    char unit[10];
    char output_unit[10];

    // Prompt user for input
    printf("Enter a value to convert: ");
    scanf("%s", input);

    // Prompt user for units
    printf("Enter the input unit (m, f, k, p): ");
    scanf("%s", unit);

    // Convert units
    convert_unit(input, unit, output_unit);

    return 0;
}