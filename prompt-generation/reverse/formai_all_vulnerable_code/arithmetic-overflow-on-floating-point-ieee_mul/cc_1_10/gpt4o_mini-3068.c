//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void displayMenu();
void convertLength();
void convertTemperature();
void convertWeight();
double kmToMiles(double km);
double milesToKm(double miles);
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
double kgToPounds(double kg);
double poundsToKg(double pounds);

int main() {
    int choice;

    // Program's entry point
    printf("Welcome to the Ultimate Unit Converter!\n");
    do {
        displayMenu();
        printf("Please enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                convertLength();
                break;
            case 2:
                convertTemperature();
                break;
            case 3:
                convertWeight();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n--- Unit Conversion Menu ---\n");
    printf("1. Length Conversion\n");
    printf("2. Temperature Conversion\n");
    printf("3. Weight Conversion\n");
    printf("4. Exit\n");
}

void convertLength() {
    int option;
    double value, result;

    printf("\n--- Length Conversion ---\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Miles to Kilometers\n");
    printf("Please select your conversion option: ");
    scanf("%d", &option);

    if(option == 1) {
        printf("Enter value in kilometers: ");
        scanf("%lf", &value);
        result = kmToMiles(value);
        printf("%.2f kilometers is equal to %.2f miles\n", value, result);
    } else if(option == 2) {
        printf("Enter value in miles: ");
        scanf("%lf", &value);
        result = milesToKm(value);
        printf("%.2f miles is equal to %.2f kilometers\n", value, result);
    } else {
        printf("Invalid option! Returning to main menu.\n");
    }
}

void convertTemperature() {
    int option;
    double value, result;

    printf("\n--- Temperature Conversion ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Please select your conversion option: ");
    scanf("%d", &option);

    if(option == 1) {
        printf("Enter value in Celsius: ");
        scanf("%lf", &value);
        result = celsiusToFahrenheit(value);
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", value, result);
    } else if(option == 2) {
        printf("Enter value in Fahrenheit: ");
        scanf("%lf", &value);
        result = fahrenheitToCelsius(value);
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", value, result);
    } else {
        printf("Invalid option! Returning to main menu.\n");
    }
}

void convertWeight() {
    int option;
    double value, result;

    printf("\n--- Weight Conversion ---\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("Please select your conversion option: ");
    scanf("%d", &option);

    if(option == 1) {
        printf("Enter value in kilograms: ");
        scanf("%lf", &value);
        result = kgToPounds(value);
        printf("%.2f kilograms is equal to %.2f pounds\n", value, result);
    } else if(option == 2) {
        printf("Enter value in pounds: ");
        scanf("%lf", &value);
        result = poundsToKg(value);
        printf("%.2f pounds is equal to %.2f kilograms\n", value, result);
    } else {
        printf("Invalid option! Returning to main menu.\n");
    }
}

// Conversion Functions
double kmToMiles(double km) {
    return km * 0.621371; // Conversion factor from km to miles
}

double milesToKm(double miles) {
    return miles / 0.621371; // Conversion factor from miles to km
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32; // Conversion formula
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9; // Conversion formula
}

double kgToPounds(double kg) {
    return kg * 2.20462; // Conversion factor from kg to pounds
}

double poundsToKg(double pounds) {
    return pounds / 2.20462; // Conversion factor from pounds to kg
}