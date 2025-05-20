//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert meters to feet and inches
void metersToFeetAndInches(double meters) {
    double feet, inches;
    feet = meters * 3.28084;
    inches = (feet - (int)feet) * 12;
    printf("%.2f meters is equal to %.2f feet and %.2f inches.\n", meters, feet, inches);
}

// Function to convert kilometers to miles
void kilometersToMiles(double kilometers) {
    double miles;
    miles = kilometers * 0.621371;
    printf("%.2f kilometers is equal to %.2f miles.\n", kilometers, miles);
}

// Function to convert liters to gallons
void litersToGallons(double liters) {
    double gallons;
    gallons = liters * 0.264172;
    printf("%.2f liters is equal to %.2f gallons.\n", liters, gallons);
}

// Function to convert Celsius to Fahrenheit
void celsiusToFahrenheit(double celsius) {
    double fahrenheit;
    fahrenheit = celsius * 1.8 + 32;
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
}

int main() {
    double meters, kilometers, liters, celsius;

    // Get input from user
    printf("Enter the value to convert:\n");
    scanf("%lf", &meters);

    // Convert meters to feet and inches
    metersToFeetAndInches(meters);

    // Convert kilometers to miles
    kilometersToMiles(meters / 1000);

    // Convert liters to gallons
    litersToGallons(liters);

    // Convert Celsius to Fahrenheit
    celsiusToFahrenheit(celsius);

    return 0;
}