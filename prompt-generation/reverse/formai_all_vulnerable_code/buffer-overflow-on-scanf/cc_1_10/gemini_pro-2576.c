//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>

// Define the unit conversion functions
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

double celsius_to_fahrenheit(double celsius) {
    return celsius * 1.8 + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Define the main function
int main() {
    // Get the user's input
    char input_unit[20];
    char output_unit[20];
    double input_value;

    printf("Enter the input unit: ");
    scanf("%s", input_unit);

    printf("Enter the output unit: ");
    scanf("%s", output_unit);

    printf("Enter the input value: ");
    scanf("%lf", &input_value);

    // Convert the input value to the output unit
    double output_value;
    if (strcmp(input_unit, "meters") == 0 && strcmp(output_unit, "feet") == 0) {
        output_value = meters_to_feet(input_value);
    } else if (strcmp(input_unit, "feet") == 0 && strcmp(output_unit, "meters") == 0) {
        output_value = feet_to_meters(input_value);
    } else if (strcmp(input_unit, "kilograms") == 0 && strcmp(output_unit, "pounds") == 0) {
        output_value = kilograms_to_pounds(input_value);
    } else if (strcmp(input_unit, "pounds") == 0 && strcmp(output_unit, "kilograms") == 0) {
        output_value = pounds_to_kilograms(input_value);
    } else if (strcmp(input_unit, "celsius") == 0 && strcmp(output_unit, "fahrenheit") == 0) {
        output_value = celsius_to_fahrenheit(input_value);
    } else if (strcmp(input_unit, "fahrenheit") == 0 && strcmp(output_unit, "celsius") == 0) {
        output_value = fahrenheit_to_celsius(input_value);
    } else {
        printf("Invalid unit conversion!\n");
        return 1;
    }

    // Print the output value
    printf("The output value is: %.2f\n", output_value);

    return 0;
}