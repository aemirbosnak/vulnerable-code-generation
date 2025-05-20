//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the unit conversion factors
const double METERS_TO_FEET = 3.28084;
const double FEET_TO_METERS = 0.3048;
const double KILOMETERS_TO_MILES = 0.621371;
const double MILES_TO_KILOMETERS = 1.60934;
const double POUNDS_TO_KILOGRAMS = 0.453592;
const double KILOGRAMS_TO_POUNDS = 2.20462;
const double GALLONS_TO_LITERS = 3.78541;
const double LITERS_TO_GALLONS = 0.264172;

// Declare the function prototypes
void print_menu();
double convert_meters_to_feet(double meters);
double convert_feet_to_meters(double feet);
double convert_kilometers_to_miles(double kilometers);
double convert_miles_to_kilometers(double miles);
double convert_pounds_to_kilograms(double pounds);
double convert_kilograms_to_pounds(double kilograms);
double convert_gallons_to_liters(double gallons);
double convert_liters_to_gallons(double liters);

// Define the main function
int main() {
    // Print the menu
    print_menu();

    // Get the user's choice
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Convert the units based on the user's choice
    double value;
    switch (choice) {
        case 1:
            printf("Enter the value in meters: ");
            scanf("%lf", &value);
            printf("%lf meters = %lf feet\n", value, convert_meters_to_feet(value));
            break;
        case 2:
            printf("Enter the value in feet: ");
            scanf("%lf", &value);
            printf("%lf feet = %lf meters\n", value, convert_feet_to_meters(value));
            break;
        case 3:
            printf("Enter the value in kilometers: ");
            scanf("%lf", &value);
            printf("%lf kilometers = %lf miles\n", value, convert_kilometers_to_miles(value));
            break;
        case 4:
            printf("Enter the value in miles: ");
            scanf("%lf", &value);
            printf("%lf miles = %lf kilometers\n", value, convert_miles_to_kilometers(value));
            break;
        case 5:
            printf("Enter the value in pounds: ");
            scanf("%lf", &value);
            printf("%lf pounds = %lf kilograms\n", value, convert_pounds_to_kilograms(value));
            break;
        case 6:
            printf("Enter the value in kilograms: ");
            scanf("%lf", &value);
            printf("%lf kilograms = %lf pounds\n", value, convert_kilograms_to_pounds(value));
            break;
        case 7:
            printf("Enter the value in gallons: ");
            scanf("%lf", &value);
            printf("%lf gallons = %lf liters\n", value, convert_gallons_to_liters(value));
            break;
        case 8:
            printf("Enter the value in liters: ");
            scanf("%lf", &value);
            printf("%lf liters = %lf gallons\n", value, convert_liters_to_gallons(value));
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 8.\n");
    }

    return 0;
}

// Define the function to print the menu
void print_menu() {
    printf("Unit Converter\n");
    printf("1. Convert meters to feet\n");
    printf("2. Convert feet to meters\n");
    printf("3. Convert kilometers to miles\n");
    printf("4. Convert miles to kilometers\n");
    printf("5. Convert pounds to kilograms\n");
    printf("6. Convert kilograms to pounds\n");
    printf("7. Convert gallons to liters\n");
    printf("8. Convert liters to gallons\n");
}

// Define the function to convert meters to feet
double convert_meters_to_feet(double meters) {
    return meters * METERS_TO_FEET;
}

// Define the function to convert feet to meters
double convert_feet_to_meters(double feet) {
    return feet * FEET_TO_METERS;
}

// Define the function to convert kilometers to miles
double convert_kilometers_to_miles(double kilometers) {
    return kilometers * KILOMETERS_TO_MILES;
}

// Define the function to convert miles to kilometers
double convert_miles_to_kilometers(double miles) {
    return miles * MILES_TO_KILOMETERS;
}

// Define the function to convert pounds to kilograms
double convert_pounds_to_kilograms(double pounds) {
    return pounds * POUNDS_TO_KILOGRAMS;
}

// Define the function to convert kilograms to pounds
double convert_kilograms_to_pounds(double kilograms) {
    return kilograms * KILOGRAMS_TO_POUNDS;
}

// Define the function to convert gallons to liters
double convert_gallons_to_liters(double gallons) {
    return gallons * GALLONS_TO_LITERS;
}

// Define the function to convert liters to gallons
double convert_liters_to_gallons(double liters) {
    return liters * LITERS_TO_GALLONS;
}