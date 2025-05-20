//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare variables for unit conversion
double value; // value to be converted
char unit_from[20]; // unit being converted from
char unit_to[20]; // unit being converted to

// Function to convert a value from one unit to another
void convert_unit(double value, char *unit_from, char *unit_to) {
    // Check for invalid input
    if (unit_from[0] == '\0' || unit_to[0] == '\0') {
        printf("Invalid input. Please enter a valid unit.\n");
        return;
    }

    // Perform the conversion
    if (strcmp(unit_from, "cm") == 0) {
        if (strcmp(unit_to, "m") == 0) {
            value *= 0.1;
        } else if (strcmp(unit_to, "ft") == 0) {
            value *= 0.3048;
        } else {
            printf("Invalid unit conversion. Only cm to m and cm to ft are supported.\n");
            return;
        }
    } else if (strcmp(unit_from, "m") == 0) {
        if (strcmp(unit_to, "cm") == 0) {
            value /= 0.1;
        } else if (strcmp(unit_to, "ft") == 0) {
            value *= 0.3048;
        } else {
            printf("Invalid unit conversion. Only m to cm and m to ft are supported.\n");
            return;
        }
    } else if (strcmp(unit_from, "ft") == 0) {
        if (strcmp(unit_to, "cm") == 0) {
            value *= 0.3048;
        } else if (strcmp(unit_to, "m") == 0) {
            value /= 0.3048;
        } else {
            printf("Invalid unit conversion. Only ft to cm and ft to m are supported.\n");
            return;
        }
    } else {
        printf("Invalid unit conversion. Only cm, m, and ft are supported.\n");
        return;
    }

    // Print the result
    printf("Value in %s is %f\n", unit_to, value);
}

int main() {
    // Prompt the user for input
    printf("Enter a value in the unit you want to convert from: ");
    scanf("%lf", &value);
    printf("Enter the unit you want to convert to: ");
    fgets(unit_from, 20, stdin);
    fgets(unit_to, 20, stdin);

    // Call the conversion function
    convert_unit(value, unit_from, unit_to);

    return 0;
}