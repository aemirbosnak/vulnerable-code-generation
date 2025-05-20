//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert length from meters to feet and inches
void meterToFeetInches(double meters) {
    double feet = meters * 3.28084;
    double inches = (feet - (int)feet) * 12;

    printf("%.2f meters is equal to %.2f feet and %.2f inches.\n", meters, feet, inches);
}

// Function to convert length from feet and inches to meters
void feetInchesToMeter(double feet, double inches) {
    double meter = (feet + inches / 12.0) / 3.28084;

    printf("%.2f feet and %.2f inches is equal to %.2f meters.\n", feet, inches, meter);
}

// Function to convert weight from kilograms to pounds and ounces
void kgToPoundsOunces(double kg) {
    double pounds = kg * 2.20462;
    double ounces = (pounds - (int)pounds) * 16;

    printf("%.2f kg is equal to %.2f pounds and %.2f ounces.\n", kg, pounds, ounces);
}

// Function to convert weight from pounds and ounces to kilograms
void poundsOuncesToKg(double pounds, double ounces) {
    double kg = (pounds + ounces / 16.0) / 2.20462;

    printf("%.2f pounds and %.2f ounces is equal to %.2f kg.\n", pounds, ounces, kg);
}

// Function to convert temperature from Celsius to Fahrenheit
void celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 1.8) + 32;

    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
}

// Function to convert temperature from Fahrenheit to Celsius
void fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) / 1.8;

    printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, celsius);
}

// Function to convert volume from liters to gallons
void literToGallon(double liter) {
    double gallon = liter * 0.264172;

    printf("%.2f liters is equal to %.2f gallons.\n", liter, gallon);
}

// Function to convert volume from gallons to liters
void gallonToLiter(double gallon) {
    double liter = gallon * 3.78541;

    printf("%.2f gallons is equal to %.2f liters.\n", gallon, liter);
}

int main() {
    double meters, feet, inches, kg, pounds, ounces, celsius, fahrenheit, liter, gallon;

    // User input for length conversions
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    meterToFeetInches(meters);
    feetInchesToMeter(feet, inches);

    // User input for weight conversions
    printf("Enter weight in kg: ");
    scanf("%lf", &kg);
    kgToPoundsOunces(kg);
    poundsOuncesToKg(pounds, ounces);

    // User input for temperature conversions
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    celsiusToFahrenheit(celsius);
    fahrenheitToCelsius(fahrenheit);

    // User input for volume conversions
    printf("Enter volume in liters: ");
    scanf("%lf", &liter);
    literToGallon(liter);
    gallonToLiter(gallon);

    return 0;
}