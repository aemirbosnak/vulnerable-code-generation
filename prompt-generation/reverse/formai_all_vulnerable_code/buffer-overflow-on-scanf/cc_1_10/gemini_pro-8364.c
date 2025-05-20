//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Declare the unit conversion functions
double convert_inches_to_centimeters(double inches);
double convert_centimeters_to_inches(double centimeters);
double convert_pounds_to_kilograms(double pounds);
double convert_kilograms_to_pounds(double kilograms);

// Declare the main function
int main() {
    // Set up the user interface
    printf("Welcome to the Post-Apocalyptic Unit Converter!\n");
    printf("Enter 'q' to quit.\n");

    // Get the user's input
    char input[100];
    while (1) {
        printf("> ");
        scanf("%s", input);

        // Check if the user wants to quit
        if (strcmp(input, "q") == 0) {
            break;
        }

        // Convert the user's input to a double
        double value = atof(input);

        // Get the unit of measurement
        char unit[100];
        scanf("%s", unit);

        // Convert the value to the desired unit
        double converted_value;
        if (strcmp(unit, "in") == 0) {
            converted_value = convert_inches_to_centimeters(value);
        } else if (strcmp(unit, "cm") == 0) {
            converted_value = convert_centimeters_to_inches(value);
        } else if (strcmp(unit, "lb") == 0) {
            converted_value = convert_pounds_to_kilograms(value);
        } else if (strcmp(unit, "kg") == 0) {
            converted_value = convert_kilograms_to_pounds(value);
        } else {
            printf("Invalid unit of measurement.\n");
            continue;
        }

        // Print the converted value
        printf("%f %s\n", converted_value, unit);
    }

    return 0;
}

// Define the unit conversion functions
double convert_inches_to_centimeters(double inches) {
    return inches * 2.54;
}

double convert_centimeters_to_inches(double centimeters) {
    return centimeters / 2.54;
}

double convert_pounds_to_kilograms(double pounds) {
    return pounds * 0.453592;
}

double convert_kilograms_to_pounds(double kilograms) {
    return kilograms * 2.20462;
}