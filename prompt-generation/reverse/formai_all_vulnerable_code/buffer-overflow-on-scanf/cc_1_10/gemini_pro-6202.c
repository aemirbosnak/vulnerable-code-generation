//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the conversion functions
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double miles_to_kilometers(double miles) {
    return miles * 1.60934;
}

double kilometers_to_miles(double kilometers) {
    return kilometers / 1.60934;
}

double pounds_to_kilograms(double pounds) {
    return pounds * 0.453592;
}

double kilograms_to_pounds(double kilograms) {
    return kilograms / 0.453592;
}

// Define the main function
int main() {
    // Get the user's input
    char input[256];
    printf("Enter the value and the unit you want to convert (e.g., 100C, 50F, 10mi, 20km, 15lb, 25kg): ");
    scanf("%s", input);

    // Parse the user's input
    char *value = strtok(input, " ");
    char *unit = strtok(NULL, " ");

    // Convert the value to a double
    double value_double = atof(value);

    // Convert the value to the desired unit
    double converted_value;
    if (strcmp(unit, "C") == 0) {
        converted_value = celsius_to_fahrenheit(value_double);
        printf("%s Celsius is equal to %f Fahrenheit.\n", value, converted_value);
    } else if (strcmp(unit, "F") == 0) {
        converted_value = fahrenheit_to_celsius(value_double);
        printf("%s Fahrenheit is equal to %f Celsius.\n", value, converted_value);
    } else if (strcmp(unit, "mi") == 0) {
        converted_value = miles_to_kilometers(value_double);
        printf("%s miles is equal to %f kilometers.\n", value, converted_value);
    } else if (strcmp(unit, "km") == 0) {
        converted_value = kilometers_to_miles(value_double);
        printf("%s kilometers is equal to %f miles.\n", value, converted_value);
    } else if (strcmp(unit, "lb") == 0) {
        converted_value = pounds_to_kilograms(value_double);
        printf("%s pounds is equal to %f kilograms.\n", value, converted_value);
    } else if (strcmp(unit, "kg") == 0) {
        converted_value = kilograms_to_pounds(value_double);
        printf("%s kilograms is equal to %f pounds.\n", value, converted_value);
    } else {
        printf("Invalid unit.\n");
    }

    return 0;
}