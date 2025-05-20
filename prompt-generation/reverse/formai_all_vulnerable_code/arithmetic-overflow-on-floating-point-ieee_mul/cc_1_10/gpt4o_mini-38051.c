//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void displayWelcomeMessage();
void displayAllUnits();
void performConversion(int choice);
void convertMetersToFeet();
void convertFeetToMeters();
void convertKilogramsToPounds();
void convertPoundsToKilograms();
void convertCelsiusToFahrenheit();
void convertFahrenheitToCelsius();
void farewellMessage();

int main() {
    displayWelcomeMessage();

    int choice;
    do {
        displayAllUnits();
        printf("Enter your choice (1-6), or 0 to exit: ");
        scanf("%d", &choice);
        if (choice != 0) {
            performConversion(choice);
        }
    } while (choice != 0);

    farewellMessage();
    return 0;
}

void displayWelcomeMessage() {
    printf("=========================================\n");
    printf("   Welcome to the Sherlock Holmes Unit  \n");
    printf("         Converter. Investigate the     \n");
    printf("         mysteries of measurement!      \n");
    printf("=========================================\n");
}

void displayAllUnits() {
    printf("\nPlease select the unit conversions you wish to make:\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("3. Kilograms to Pounds\n");
    printf("4. Pounds to Kilograms\n");
    printf("5. Celsius to Fahrenheit\n");
    printf("6. Fahrenheit to Celsius\n");
}

void performConversion(int choice) {
    switch (choice) {
        case 1: convertMetersToFeet(); break;
        case 2: convertFeetToMeters(); break;
        case 3: convertKilogramsToPounds(); break;
        case 4: convertPoundsToKilograms(); break;
        case 5: convertCelsiusToFahrenheit(); break;
        case 6: convertFahrenheitToCelsius(); break;
        default: printf("Invalid choice! Please try again.\n"); break;
    }
}

void convertMetersToFeet() {
    double meters;
    printf("Enter the length in meters: ");
    scanf("%lf", &meters);
    double feet = meters * 3.28084;
    printf("%.2f meters is equivalent to %.2f feet.\n", meters, feet);
}

void convertFeetToMeters() {
    double feet;
    printf("Enter the length in feet: ");
    scanf("%lf", &feet);
    double meters = feet / 3.28084;
    printf("%.2f feet is equivalent to %.2f meters.\n", feet, meters);
}

void convertKilogramsToPounds() {
    double kilograms;
    printf("Enter the weight in kilograms: ");
    scanf("%lf", &kilograms);
    double pounds = kilograms * 2.20462;
    printf("%.2f kilograms is equivalent to %.2f pounds.\n", kilograms, pounds);
}

void convertPoundsToKilograms() {
    double pounds;
    printf("Enter the weight in pounds: ");
    scanf("%lf", &pounds);
    double kilograms = pounds / 2.20462;
    printf("%.2f pounds is equivalent to %.2f kilograms.\n", pounds, kilograms);
}

void convertCelsiusToFahrenheit() {
    double celsius;
    printf("Enter the temperature in Celsius: ");
    scanf("%lf", &celsius);
    double fahrenheit = (celsius * 9 / 5) + 32;
    printf("%.2f Celsius is equivalent to %.2f Fahrenheit.\n", celsius, fahrenheit);
}

void convertFahrenheitToCelsius() {
    double fahrenheit;
    printf("Enter the temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    double celsius = (fahrenheit - 32) * 5 / 9;
    printf("%.2f Fahrenheit is equivalent to %.2f Celsius.\n", fahrenheit, celsius);
}

void farewellMessage() {
    printf("\nThank you for using the Sherlock Holmes Unit Converter!\n");
    printf("May your measurements always be precise and insightful.\n");
}