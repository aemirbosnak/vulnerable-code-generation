//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Function to display the menu of conversion options
void displayMenu() {
    printf("Welcome to the Unit Conversion Program\n");
    printf("Select a conversion option:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Volume\n");
    printf("5. Exit\n");
}

// Function to convert length
void convertLength() {
    double meters;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    printf("Length in kilometers: %.3f km\n", meters / 1000);
    printf("Length in centimeters: %.3f cm\n", meters * 100);
    printf("Length in feet: %.3f ft\n", meters * 3.28084);
    printf("Length in inches: %.3f in\n", meters * 39.3701);
}

// Function to convert weight
void convertWeight() {
    double grams;
    printf("Enter weight in grams: ");
    scanf("%lf", &grams);
    printf("Weight in kilograms: %.3f kg\n", grams / 1000);
    printf("Weight in pounds: %.3f lbs\n", grams * 0.00220462);
    printf("Weight in ounces: %.3f oz\n", grams * 0.035274);
}

// Function to convert temperature
void convertTemperature() {
    double celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    printf("Temperature in Fahrenheit: %.3f °F\n", (celsius * 9/5) + 32);
    printf("Temperature in Kelvin: %.3f K\n", celsius + 273.15);
}

// Function to convert volume
void convertVolume() {
    double liters;
    printf("Enter volume in liters: ");
    scanf("%lf", &liters);
    printf("Volume in milliliters: %.3f ml\n", liters * 1000);
    printf("Volume in gallons: %.3f gal\n", liters * 0.264172);
    printf("Volume in cubic meters: %.3f m³\n", liters / 1000);
}

// Main function
int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertLength();
                break;
            case 2:
                convertWeight();
                break;
            case 3:
                convertTemperature();
                break;
            case 4:
                convertVolume();
                break;
            case 5:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
        printf("\n");
    } while (choice != 5);

    return 0;
}