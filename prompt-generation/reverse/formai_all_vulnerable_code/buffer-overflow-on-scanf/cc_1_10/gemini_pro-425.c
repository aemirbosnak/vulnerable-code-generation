//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define the unit conversion functions
double feet_to_meters(double feet) {
    return feet * 0.3048;
}

double meters_to_feet(double meters) {
    return meters * 3.281;
}

double pounds_to_kilograms(double pounds) {
    return pounds * 0.453592;
}

double kilograms_to_pounds(double kilograms) {
    return kilograms * 2.205;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Define the main function
int main() {
    // Get the user's input
    char input[100];
    printf("Enter your conversion: ");
    scanf("%s", input);

    // Parse the user's input
    char *unit1 = strtok(input, " ");
    char *unit2 = strtok(NULL, " ");
    double value = atof(strtok(NULL, " "));

    // Convert the value from the first unit to the second unit
    double result;
    if (strcmp(unit1, "feet") == 0 && strcmp(unit2, "meters") == 0) {
        result = feet_to_meters(value);
    } else if (strcmp(unit1, "meters") == 0 && strcmp(unit2, "feet") == 0) {
        result = meters_to_feet(value);
    } else if (strcmp(unit1, "pounds") == 0 && strcmp(unit2, "kilograms") == 0) {
        result = pounds_to_kilograms(value);
    } else if (strcmp(unit1, "kilograms") == 0 && strcmp(unit2, "pounds") == 0) {
        result = kilograms_to_pounds(value);
    } else if (strcmp(unit1, "celsius") == 0 && strcmp(unit2, "fahrenheit") == 0) {
        result = celsius_to_fahrenheit(value);
    } else if (strcmp(unit1, "fahrenheit") == 0 && strcmp(unit2, "celsius") == 0) {
        result = fahrenheit_to_celsius(value);
    } else {
        printf("Invalid conversion.\n");
        return 1;
    }

    // Print the result
    printf("%f %s = %f %s\n", value, unit1, result, unit2);

    return 0;
}