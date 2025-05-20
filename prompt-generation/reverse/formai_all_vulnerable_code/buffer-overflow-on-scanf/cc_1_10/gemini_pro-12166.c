//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the unit conversion functions
double convert_celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double convert_fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double convert_meters_to_feet(double meters) {
    return meters * 3.28084;
}

double convert_feet_to_meters(double feet) {
    return feet / 3.28084;
}

double convert_kilograms_to_pounds(double kilograms) {
    return kilograms * 2.20462;
}

double convert_pounds_to_kilograms(double pounds) {
    return pounds / 2.20462;
}

// Define the main function
int main() {
    // Get the user's input
    printf("Enter the value to be converted: ");
    double value;
    scanf("%lf", &value);

    printf("Enter the unit of the value (C, F, M, FT, KG, or LB): ");
    char unit;
    scanf(" %c", &unit);

    // Convert the value to the desired unit
    double converted_value;
    switch (unit) {
        case 'C':
            converted_value = convert_celsius_to_fahrenheit(value);
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", value, converted_value);
            break;
        case 'F':
            converted_value = convert_fahrenheit_to_celsius(value);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", value, converted_value);
            break;
        case 'M':
            converted_value = convert_meters_to_feet(value);
            printf("%.2f meters is equal to %.2f feet\n", value, converted_value);
            break;
        case 'FT':
            converted_value = convert_feet_to_meters(value);
            printf("%.2f feet is equal to %.2f meters\n", value, converted_value);
            break;
        case 'KG':
            converted_value = convert_kilograms_to_pounds(value);
            printf("%.2f kilograms is equal to %.2f pounds\n", value, converted_value);
            break;
        case 'LB':
            converted_value = convert_pounds_to_kilograms(value);
            printf("%.2f pounds is equal to %.2f kilograms\n", value, converted_value);
            break;
        default:
            printf("Invalid unit entered\n");
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}