//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void displayMenu();
void convertLength();
void convertWeight();
void convertTemperature();
void lengthConversionMenu();
void weightConversionMenu();
void temperatureConversionMenu();
void lengthOptions(double meters);
void weightOptions(double kilograms);
void temperatureOptions(double celsius);

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-4) or 0 to exit: ");
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
            case 0:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("\n--- Unit Converter Menu ---\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("0. Exit\n");
}

// Function to convert length
void convertLength() {
    double meters;
    lengthConversionMenu();
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    lengthOptions(meters);
}

// Function to display the length conversion menu
void lengthConversionMenu() {
    printf("\n--- Length Conversion Options ---\n");
    printf("You can convert meters to:\n");
    printf("1. Kilometers\n");
    printf("2. Centimeters\n");
    printf("3. Millimeters\n");
    printf("4. Feet\n");
    printf("5. Inches\n");
}

// Function with options for length conversions
void lengthOptions(double meters) {
    int choice;
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("%.2f meters is %.2f kilometers\n", meters, meters / 1000);
            break;
        case 2:
            printf("%.2f meters is %.2f centimeters\n", meters, meters * 100);
            break;
        case 3:
            printf("%.2f meters is %.2f millimeters\n", meters, meters * 1000);
            break;
        case 4:
            printf("%.2f meters is %.2f feet\n", meters, meters * 3.28084);
            break;
        case 5:
            printf("%.2f meters is %.2f inches\n", meters, meters * 39.3701);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

// Function to convert weight
void convertWeight() {
    double kilograms;
    weightConversionMenu();
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    weightOptions(kilograms);
}

// Function to display the weight conversion menu
void weightConversionMenu() {
    printf("\n--- Weight Conversion Options ---\n");
    printf("You can convert kilograms to:\n");
    printf("1. Grams\n");
    printf("2. Pounds\n");
    printf("3. Ounces\n");
}

// Function with options for weight conversions
void weightOptions(double kilograms) {
    int choice;
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("%.2f kilograms is %.2f grams\n", kilograms, kilograms * 1000);
            break;
        case 2:
            printf("%.2f kilograms is %.2f pounds\n", kilograms, kilograms * 2.20462);
            break;
        case 3:
            printf("%.2f kilograms is %.2f ounces\n", kilograms, kilograms * 35.274);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

// Function to convert temperature
void convertTemperature() {
    double celsius;
    temperatureConversionMenu();
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    temperatureOptions(celsius);
}

// Function to display the temperature conversion menu
void temperatureConversionMenu() {
    printf("\n--- Temperature Conversion Options ---\n");
    printf("You can convert Celsius to:\n");
    printf("1. Fahrenheit\n");
    printf("2. Kelvin\n");
}

// Function with options for temperature conversions
void temperatureOptions(double celsius) {
    int choice;
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, (celsius * 9/5) + 32);
            break;
        case 2:
            printf("%.2f Celsius is %.2f Kelvin\n", celsius, celsius + 273.15);
            break;
        default:
            printf("Invalid choice!\n");
    }
}