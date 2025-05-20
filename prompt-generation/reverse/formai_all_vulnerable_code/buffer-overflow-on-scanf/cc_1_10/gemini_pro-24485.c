//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the unit conversion functions
double convertCelsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double convertFahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double convertMilesToKilometers(double miles) {
    return miles * 1.60934;
}

double convertKilometersToMiles(double kilometers) {
    return kilometers * 0.621371;
}

double convertGallonsToLiters(double gallons) {
    return gallons * 3.78541;
}

double convertLitersToGallons(double liters) {
    return liters * 0.264172;
}

// Define the main function
int main() {
    // Declare the variables
    double value;
    char unit;

    // Get the user input
    printf("Enter the value and unit (e.g., 100 C): ");
    scanf("%lf %c", &value, &unit);

    // Convert the value to the desired unit
    switch (unit) {
        case 'C':
            value = convertCelsiusToFahrenheit(value);
            printf("%.2f F\n", value);
            break;
        case 'F':
            value = convertFahrenheitToCelsius(value);
            printf("%.2f C\n", value);
            break;
        case 'M':
            value = convertMilesToKilometers(value);
            printf("%.2f KM\n", value);
            break;
        case 'K':
            value = convertKilometersToMiles(value);
            printf("%.2f MI\n", value);
            break;
        case 'G':
            value = convertGallonsToLiters(value);
            printf("%.2f L\n", value);
            break;
        case 'L':
            value = convertLitersToGallons(value);
            printf("%.2f GAL\n", value);
            break;
        default:
            printf("Invalid unit\n");
    }

    return 0;
}