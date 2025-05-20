//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: Alan Turing
#include <stdio.h>

// Function to convert from inches to centimeters
float inches_to_centimeters(float inches) {
    return inches * 2.54;
}

// Function to convert from centimeters to inches
float centimeters_to_inches(float centimeters) {
    return centimeters / 2.54;
}

// Function to convert from pounds to kilograms
float pounds_to_kilograms(float pounds) {
    return pounds * 0.453592;
}

// Function to convert from kilograms to pounds
float kilograms_to_pounds(float kilograms) {
    return kilograms / 0.453592;
}

// Function to convert from miles to kilometers
float miles_to_kilometers(float miles) {
    return miles * 1.60934;
}

// Function to convert from kilometers to miles
float kilometers_to_miles(float kilometers) {
    return kilometers / 1.60934;
}

// Function to convert from fahrenheit to celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to convert from celsius to fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

int main() {
    // Get the user's input
    printf("Enter the value to be converted: ");
    float value;
    scanf("%f", &value);

    printf("Enter the unit of the value: ");
    char unit;
    scanf(" %c", &unit);

    // Convert the value to the desired unit
    float converted_value;
    switch (unit) {
        case 'i':
            converted_value = inches_to_centimeters(value);
            printf("The converted value is: %.2f cm\n", converted_value);
            break;
        case 'c':
            converted_value = centimeters_to_inches(value);
            printf("The converted value is: %.2f in\n", converted_value);
            break;
        case 'l':
            converted_value = pounds_to_kilograms(value);
            printf("The converted value is: %.2f kg\n", converted_value);
            break;
        case 'k':
            converted_value = kilograms_to_pounds(value);
            printf("The converted value is: %.2f lb\n", converted_value);
            break;
        case 'm':
            converted_value = miles_to_kilometers(value);
            printf("The converted value is: %.2f km\n", converted_value);
            break;
        case 'n':
            converted_value = kilometers_to_miles(value);
            printf("The converted value is: %.2f mi\n", converted_value);
            break;
        case 'f':
            converted_value = fahrenheit_to_celsius(value);
            printf("The converted value is: %.2f C\n", converted_value);
            break;
        case 'r':
            converted_value = celsius_to_fahrenheit(value);
            printf("The converted value is: %.2f F\n", converted_value);
            break;
        default:
            printf("Invalid unit\n");
    }

    return 0;
}