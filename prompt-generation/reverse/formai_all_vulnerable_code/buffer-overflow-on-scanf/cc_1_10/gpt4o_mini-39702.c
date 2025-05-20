//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>

// Function prototypes for conversion
void convertLength();
void convertWeight();
void convertTemperature();
void convertArea();

// Function to display a menu
void displayMenu() {
    printf("***************************************\n");
    printf("*        Universal Unit Converter     *\n");
    printf("***************************************\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Area Conversion\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

// Function to convert length
void convertLength() {
    double meters;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    printf("Length in kilometers: %.2lf km\n", meters / 1000);
    printf("Length in centimeters: %.2lf cm\n", meters * 100);
    printf("Length in feet: %.2lf ft\n", meters * 3.28084);
    printf("Length in inches: %.2lf in\n", meters * 39.3701);
}

// Function to convert weight
void convertWeight() {
    double kg;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kg);
    printf("Weight in grams: %.2lf g\n", kg * 1000);
    printf("Weight in pounds: %.2lf lbs\n", kg * 2.20462);
    printf("Weight in ounces: %.2lf oz\n", kg * 35.274);
}

// Function to convert temperature
void convertTemperature() {
    double celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    printf("Temperature in Fahrenheit: %.2lf °F\n", celsius * 9/5 + 32);
    printf("Temperature in Kelvin: %.2lf K\n", celsius + 273.15);
}

// Function to convert area
void convertArea() {
    double squareMeters;
    printf("Enter area in square meters: ");
    scanf("%lf", &squareMeters);
    printf("Area in square kilometers: %.6lf km²\n", squareMeters / 1e6);
    printf("Area in hectares: %.4lf ha\n", squareMeters / 10000);
    printf("Area in acres: %.4lf acres\n", squareMeters * 0.000247105);
}

// Main function
int main() {
    int choice;
    while (1) {
        displayMenu();
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
                convertArea();
                break;
            case 5:
                printf("Thank you for using the Universal Unit Converter. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
        printf("\n");
    }
    return 0;
}