//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>

// Define the conversion factors
#define METERS_TO_FEET 3.28084
#define KILOGRAMS_TO_POUNDS 2.20462
#define LITERS_TO_GALLONS 0.264172

// Function prototypes
double metersToFeet(double meters);
double kilogramsToPounds(double kilograms);
double litersToGallons(double liters);

int main() {
    double meters, feet;
    double kilograms, pounds;
    double liters, gallons;

    // Get input from user
    printf("Enter the value in meters: ");
    scanf("%lf", &meters);
    printf("Enter the value in kilograms: ");
    scanf("%lf", &kilograms);
    printf("Enter the value in liters: ");
    scanf("%lf", &liters);

    // Convert meters to feet
    feet = metersToFeet(meters);
    printf("%.2f meters is equal to %.2f feet.\n", meters, feet);

    // Convert kilograms to pounds
    pounds = kilogramsToPounds(kilograms);
    printf("%.2f kilograms is equal to %.2f pounds.\n", kilograms, pounds);

    // Convert liters to gallons
    gallons = litersToGallons(liters);
    printf("%.2f liters is equal to %.2f gallons.\n", liters, gallons);

    return 0;
}

// Function to convert meters to feet
double metersToFeet(double meters) {
    return meters * METERS_TO_FEET;
}

// Function to convert kilograms to pounds
double kilogramsToPounds(double kilograms) {
    return kilograms * KILOGRAMS_TO_POUNDS;
}

// Function to convert liters to gallons
double litersToGallons(double liters) {
    return liters * LITERS_TO_GALLONS;
}