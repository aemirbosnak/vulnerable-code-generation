//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define the unit conversion functions
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double meters_to_feet(double meters) {
    return meters * 3.28084;
}

double feet_to_meters(double feet) {
    return feet / 3.28084;
}

double kilograms_to_pounds(double kilograms) {
    return kilograms * 2.20462;
}

double pounds_to_kilograms(double pounds) {
    return pounds / 2.20462;
}

// Define the main function
int main() {
    // Get the input from the user
    char input_unit;
    double input_value;
    printf("Enter the input unit (C/F/M/FT/KG/LB): ");
    scanf(" %c", &input_unit);
    printf("Enter the input value: ");
    scanf(" %lf", &input_value);

    // Convert the input value to the desired unit
    double output_value;
    char output_unit;
    switch (input_unit) {
        case 'C':
            output_unit = 'F';
            output_value = celsius_to_fahrenheit(input_value);
            break;
        case 'F':
            output_unit = 'C';
            output_value = fahrenheit_to_celsius(input_value);
            break;
        case 'M':
            output_unit = 'FT';
            output_value = meters_to_feet(input_value);
            break;
        case 'FT':
            output_unit = 'M';
            output_value = feet_to_meters(input_value);
            break;
        case 'KG':
            output_unit = 'LB';
            output_value = kilograms_to_pounds(input_value);
            break;
        case 'LB':
            output_unit = 'KG';
            output_value = pounds_to_kilograms(input_value);
            break;
        default:
            printf("Invalid input unit.\n");
            return EXIT_FAILURE;
    }

    // Print the output value
    printf("The converted value is: %.2f %c\n", output_value, output_unit);

    return EXIT_SUCCESS;
}