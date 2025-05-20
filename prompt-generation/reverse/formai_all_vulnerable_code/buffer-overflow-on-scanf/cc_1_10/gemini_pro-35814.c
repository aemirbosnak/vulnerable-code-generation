//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: lively
// Welcome to the Unit Converter Extravaganza, where we'll dance with dimensions!

#include <stdio.h>
#include <stdlib.h>

// Define our conversion factors for a wild ride:
#define INCHES_TO_CENTIMETERS 2.54
#define POUNDS_TO_KILOGRAMS 0.453592
#define CELSIUS_TO_FAHRENHEIT 1.8
#define MILES_TO_KILOMETERS 1.60934

// Function declarations: Let's keep things tidy!
void printMenu();
float convertInchesToCentimeters(float inches);
float convertPoundsToKilograms(float pounds);
float convertCelsiusToFahrenheit(float celsius);
float convertMilesToKilometers(float miles);

int main() {
    // Welcome our intrepid users to the unit conversion fiesta!
    printf("Welcome to the Unit Converter Extravaganza! Let's get this party started!\n");

    // Display the menu of conversion options:
    printMenu();

    // Initialize user's choice to kick off the adventure:
    int choice;
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    // Loop until the user decides to wave goodbye:
    while (choice != 0) {
        float value;

        // Time to convert! We'll handle each option with grace:
        switch (choice) {
            case 1:
                printf("Enter the value in inches: ");
                scanf("%f", &value);
                printf("%.2f inches is %.2f centimeters.\n", value, convertInchesToCentimeters(value));
                break;
            case 2:
                printf("Enter the value in pounds: ");
                scanf("%f", &value);
                printf("%.2f pounds is %.2f kilograms.\n", value, convertPoundsToKilograms(value));
                break;
            case 3:
                printf("Enter the value in Celsius: ");
                scanf("%f", &value);
                printf("%.2f Celsius is %.2f Fahrenheit.\n", value, convertCelsiusToFahrenheit(value));
                break;
            case 4:
                printf("Enter the value in miles: ");
                scanf("%f", &value);
                printf("%.2f miles is %.2f kilometers.\n", value, convertMilesToKilometers(value));
                break;
            default:
                printf("Oops! Invalid choice. Please try again.\n");
        }

        // Display the updated menu:
        printMenu();

        // Ask for the next conversion adventure:
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
    }

    // Bid farewell to our esteemed users:
    printf("Hasta la vista, amigo! Thanks for joining the unit conversion fiesta.\n");
    return 0;
}

// Display the menu of conversion options:
void printMenu() {
    printf("\nChoose your conversion adventure:\n");
    printf("1. Inches to Centimeters\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Celsius to Fahrenheit\n");
    printf("4. Miles to Kilometers\n");
    printf("0. Exit\n");
}

// Convert inches to centimeters:
float convertInchesToCentimeters(float inches) {
    return inches * INCHES_TO_CENTIMETERS;
}

// Convert pounds to kilograms:
float convertPoundsToKilograms(float pounds) {
    return pounds * POUNDS_TO_KILOGRAMS;
}

// Convert Celsius to Fahrenheit:
float convertCelsiusToFahrenheit(float celsius) {
    return (celsius * CELSIUS_TO_FAHRENHEIT) + 32;
}

// Convert miles to kilometers:
float convertMilesToKilometers(float miles) {
    return miles * MILES_TO_KILOMETERS;
}