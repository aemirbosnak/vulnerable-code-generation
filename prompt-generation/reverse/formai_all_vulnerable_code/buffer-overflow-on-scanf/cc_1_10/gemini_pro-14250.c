//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>

// Define the unit conversion functions
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double miles_to_kilometers(double miles) {
    return miles * 1.60934;
}

double kilometers_to_miles(double kilometers) {
    return kilometers / 1.60934;
}

double pounds_to_kilograms(double pounds) {
    return pounds / 2.20462;
}

double kilograms_to_pounds(double kilograms) {
    return kilograms * 2.20462;
}

double gallons_to_liters(double gallons) {
    return gallons * 3.78541;
}

double liters_to_gallons(double liters) {
    return liters / 3.78541;
}

// Define the main function
int main() {
    // Declare the variables
    double value;
    char unit;

    // Get the input from the user
    printf("Enter the value and unit (e.g., 100 F): ");
    scanf("%lf %c", &value, &unit);

    // Convert the value to the desired unit
    switch (unit) {
        case 'F':
            printf("%.2f degrees Fahrenheit is %.2f degrees Celsius\n", value, fahrenheit_to_celsius(value));
            break;
        case 'C':
            printf("%.2f degrees Celsius is %.2f degrees Fahrenheit\n", value, celsius_to_fahrenheit(value));
            break;
        case 'M':
            printf("%.2f miles is %.2f kilometers\n", value, miles_to_kilometers(value));
            break;
        case 'K':
            printf("%.2f kilometers is %.2f miles\n", value, kilometers_to_miles(value));
            break;
        case 'P':
            printf("%.2f pounds is %.2f kilograms\n", value, pounds_to_kilograms(value));
            break;
        case 'G':
            printf("%.2f gallons is %.2f liters\n", value, gallons_to_liters(value));
            break;
        case 'L':
            printf("%.2f liters is %.2f gallons\n", value, liters_to_gallons(value));
            break;
        default:
            printf("Invalid unit\n");
    }

    return 0;
}