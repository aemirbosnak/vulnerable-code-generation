//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>

// Function to convert length from meters to feet
void meters_to_feet(double meters) {
    double feet = meters * 3.28084;
    printf("%.2f meters is equal to %.2f feet.\n", meters, feet);
}

// Function to convert length from feet to meters
void feet_to_meters(double feet) {
    double meters = feet / 3.28084;
    printf("%.2f feet is equal to %.2f meters.\n", feet, meters);
}

// Function to convert weight from kilograms to pounds
void kilograms_to_pounds(double kilograms) {
    double pounds = kilograms * 2.20462;
    printf("%.2f kilograms is equal to %.2f pounds.\n", kilograms, pounds);
}

// Function to convert weight from pounds to kilograms
void pounds_to_kilograms(double pounds) {
    double kilograms = pounds / 2.20462;
    printf("%.2f pounds is equal to %.2f kilograms.\n", pounds, kilograms);
}

// Function to convert temperature from Celsius to Fahrenheit
void celsius_to_fahrenheit(double celsius) {
    double fahrenheit = (celsius * 9.0) / 5.0 + 32;
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
}

// Function to convert temperature from Fahrenheit to Celsius
void fahrenheit_to_celsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5.0 / 9.0;
    printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
}

int main() {
    double length, weight, temperature;
    char choice;

    // Get user input for length, weight or temperature
    printf("Enter 'L' for length, 'W' for weight or 'T' for temperature: ");
    scanf("%c", &choice);

    // Convert length, weight or temperature based on user input
    switch(choice) {
        case 'L':
            printf("Enter length in meters: ");
            scanf("%lf", &length);
            meters_to_feet(length);
            break;
        case 'W':
            printf("Enter weight in kilograms: ");
            scanf("%lf", &weight);
            kilograms_to_pounds(weight);
            break;
        case 'T':
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            celsius_to_fahrenheit(temperature);
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }

    return 0;
}