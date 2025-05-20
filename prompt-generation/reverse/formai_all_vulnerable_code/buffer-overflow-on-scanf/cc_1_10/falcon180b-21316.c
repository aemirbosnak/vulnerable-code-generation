//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Function to convert meters to feet
void meters_to_feet(double meters) {
    double feet = meters * 3.28084;
    printf("%.2f meters is equal to %.2f feet.\n", meters, feet);
}

// Function to convert feet to meters
void feet_to_meters(double feet) {
    double meters = feet / 3.28084;
    printf("%.2f feet is equal to %.2f meters.\n", feet, meters);
}

// Function to convert grams to ounces
void grams_to_ounces(double grams) {
    double ounces = grams * 0.035274;
    printf("%.2f grams is equal to %.2f ounces.\n", grams, ounces);
}

// Function to convert ounces to grams
void ounces_to_grams(double ounces) {
    double grams = ounces / 0.035274;
    printf("%.2f ounces is equal to %.2f grams.\n", ounces, grams);
}

// Function to convert liters to gallons
void liters_to_gallons(double liters) {
    double gallons = liters * 0.264172;
    printf("%.2f liters is equal to %.2f gallons.\n", liters, gallons);
}

// Function to convert gallons to liters
void gallons_to_liters(double gallons) {
    double liters = gallons / 0.264172;
    printf("%.2f gallons is equal to %.2f liters.\n", gallons, liters);
}

int main() {
    double meters = 10.0;
    double feet = 3.0;
    double grams = 100.0;
    double ounces = 3.5;
    double liters = 1.0;
    double gallons = 2.0;

    printf("Welcome to the Unit Converter!\n");
    printf("Please select a conversion:\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("3. Grams to Ounces\n");
    printf("4. Ounces to Grams\n");
    printf("5. Liters to Gallons\n");
    printf("6. Gallons to Liters\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            meters_to_feet(meters);
            break;
        case 2:
            feet_to_meters(feet);
            break;
        case 3:
            grams_to_ounces(grams);
            break;
        case 4:
            ounces_to_grams(ounces);
            break;
        case 5:
            liters_to_gallons(liters);
            break;
        case 6:
            gallons_to_liters(gallons);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}