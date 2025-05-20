//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert meters to feet
float meters_to_feet(float meters) {
    return meters * 3.28084;
}

// Function to convert feet to meters
float feet_to_meters(float feet) {
    return feet / 3.28084;
}

// Function to convert kilograms to pounds
float kilograms_to_pounds(float kilograms) {
    return kilograms * 2.20462;
}

// Function to convert pounds to kilograms
float pounds_to_kilograms(float pounds) {
    return pounds / 2.20462;
}

// Function to convert liters to gallons
float liters_to_gallons(float liters) {
    return liters * 0.264172;
}

// Function to convert gallons to liters
float gallons_to_liters(float gallons) {
    return gallons / 0.264172;
}

// Function to print the conversion results
void print_conversion_results(float input, float output, char *input_unit, char *output_unit) {
    printf("%.2f %s is equal to %.2f %s\n", input, input_unit, output, output_unit);
}

int main() {
    // Get the input from the user
    float input_value;
    char input_unit[10];
    char output_unit[10];
    printf("Enter the input value: ");
    scanf("%f", &input_value);
    printf("Enter the input unit (e.g., C, F, m, ft, kg, lb, l, gal): ");
    scanf("%s", input_unit);
    printf("Enter the output unit (e.g., C, F, m, ft, kg, lb, l, gal): ");
    scanf("%s", output_unit);

    // Convert the input value to the output unit
    float output_value;
    if (strcmp(input_unit, "C") == 0 && strcmp(output_unit, "F") == 0) {
        output_value = celsius_to_fahrenheit(input_value);
    } else if (strcmp(input_unit, "F") == 0 && strcmp(output_unit, "C") == 0) {
        output_value = fahrenheit_to_celsius(input_value);
    } else if (strcmp(input_unit, "m") == 0 && strcmp(output_unit, "ft") == 0) {
        output_value = meters_to_feet(input_value);
    } else if (strcmp(input_unit, "ft") == 0 && strcmp(output_unit, "m") == 0) {
        output_value = feet_to_meters(input_value);
    } else if (strcmp(input_unit, "kg") == 0 && strcmp(output_unit, "lb") == 0) {
        output_value = kilograms_to_pounds(input_value);
    } else if (strcmp(input_unit, "lb") == 0 && strcmp(output_unit, "kg") == 0) {
        output_value = pounds_to_kilograms(input_value);
    } else if (strcmp(input_unit, "l") == 0 && strcmp(output_unit, "gal") == 0) {
        output_value = liters_to_gallons(input_value);
    } else if (strcmp(input_unit, "gal") == 0 && strcmp(output_unit, "l") == 0) {
        output_value = gallons_to_liters(input_value);
    } else {
        printf("Invalid input or output unit.\n");
        return 1;
    }

    // Print the conversion results
    print_conversion_results(input_value, output_value, input_unit, output_unit);

    return 0;
}