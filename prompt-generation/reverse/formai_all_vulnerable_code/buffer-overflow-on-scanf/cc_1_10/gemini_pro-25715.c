//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define the unit conversion functions
double cm_to_inches(double cm) {
    return cm / 2.54;
}

double inches_to_cm(double inches) {
    return inches * 2.54;
}

double kg_to_pounds(double kg) {
    return kg * 2.205;
}

double pounds_to_kg(double pounds) {
    return pounds / 2.205;
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
    printf("Enter the value to be converted: ");
    double value;
    scanf("%lf", &value);

    printf("Enter the unit of the value (cm, inches, kg, pounds, celsius, fahrenheit): ");
    char unit[10];
    scanf("%s", unit);

    // Convert the value to the desired unit
    double convertedValue;
    if (strcmp(unit, "cm") == 0) {
        convertedValue = cm_to_inches(value);
    } else if (strcmp(unit, "inches") == 0) {
        convertedValue = inches_to_cm(value);
    } else if (strcmp(unit, "kg") == 0) {
        convertedValue = kg_to_pounds(value);
    } else if (strcmp(unit, "pounds") == 0) {
        convertedValue = pounds_to_kg(value);
    } else if (strcmp(unit, "celsius") == 0) {
        convertedValue = celsius_to_fahrenheit(value);
    } else if (strcmp(unit, "fahrenheit") == 0) {
        convertedValue = fahrenheit_to_celsius(value);
    } else {
        printf("Invalid unit entered.\n");
        return 1;
    }

    // Print the converted value
    printf("The converted value is: %lf\n", convertedValue);

    return 0;
}