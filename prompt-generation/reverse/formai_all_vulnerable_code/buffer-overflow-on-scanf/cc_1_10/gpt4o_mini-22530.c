//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void lengthConverter();
void weightConverter();
void temperatureConverter();
void volumeConverter();
void areaConverter();
void currencyConverter();
void performLengthConversion(int choice);
void performWeightConversion(int choice);
void performTemperatureConversion(int choice);
void performVolumeConversion(int choice);
void performAreaConversion(int choice);
void performCurrencyConversion(int choice);
void lengthInstructions();
void weightInstructions();
void temperatureInstructions();
void volumeInstructions();
void areaInstructions();
void currencyInstructions();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Choose a conversion type (1-6) or 0 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: lengthConverter(); break;
            case 2: weightConverter(); break;
            case 3: temperatureConverter(); break;
            case 4: volumeConverter(); break;
            case 5: areaConverter(); break;
            case 6: currencyConverter(); break;
            case 0: printf("Exiting the program. Thank you!"); return 0;
            default: printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }
}

void displayMenu() {
    printf("=== Universal Unit Converter ===\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Volume\n");
    printf("5. Area\n");
    printf("6. Currency\n");
    printf("0. Exit\n");
}

void lengthConverter() {
    int choice;
    lengthInstructions();
    printf("Your choice: ");
    scanf("%d", &choice);
    performLengthConversion(choice);
}

void performLengthConversion(int choice) {
    double value, result;

    switch (choice) {
        case 1:
            printf("Enter value in meters: ");
            scanf("%lf", &value);
            result = value * 100; // Meters to Centimeters
            printf("%.2lf meters = %.2lf centimeters\n", value, result);
            break;
        case 2:
            printf("Enter value in kilometers: ");
            scanf("%lf", &value);
            result = value * 1000; // Kilometers to Meters
            printf("%.2lf kilometers = %.2lf meters\n", value, result);
            break;
        case 3:
            printf("Enter value in miles: ");
            scanf("%lf", &value);
            result = value * 1609.34; // Miles to Meters
            printf("%.2lf miles = %.2lf meters\n", value, result);
            break;
        default:
            printf("Invalid length option.\n");
    }
}

void lengthInstructions() {
    printf("=== Length Conversion ===\n");
    printf("1. Meters to Centimeters\n");
    printf("2. Kilometers to Meters\n");
    printf("3. Miles to Meters\n");
}

void weightConverter() {
    int choice;
    weightInstructions();
    printf("Your choice: ");
    scanf("%d", &choice);
    performWeightConversion(choice);
}

void performWeightConversion(int choice) {
    double value, result;

    switch (choice) {
        case 1:
            printf("Enter value in kilograms: ");
            scanf("%lf", &value);
            result = value * 1000; // Kilograms to Grams
            printf("%.2lf kilograms = %.2lf grams\n", value, result);
            break;
        case 2:
            printf("Enter value in pounds: ");
            scanf("%lf", &value);
            result = value * 453.592; // Pounds to Grams
            printf("%.2lf pounds = %.2lf grams\n", value, result);
            break;
        case 3:
            printf("Enter value in ounces: ");
            scanf("%lf", &value);
            result = value * 28.3495; // Ounces to Grams
            printf("%.2lf ounces = %.2lf grams\n", value, result);
            break;
        default:
            printf("Invalid weight option.\n");
    }
}

void weightInstructions() {
    printf("=== Weight Conversion ===\n");
    printf("1. Kilograms to Grams\n");
    printf("2. Pounds to Grams\n");
    printf("3. Ounces to Grams\n");
}

void temperatureConverter() {
    int choice;
    temperatureInstructions();
    printf("Your choice: ");
    scanf("%d", &choice);
    performTemperatureConversion(choice);
}

void performTemperatureConversion(int choice) {
    double value, result;

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &value);
            result = (value * 9/5) + 32; // Celsius to Fahrenheit
            printf("%.2lf Celsius = %.2lf Fahrenheit\n", value, result);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &value);
            result = (value - 32) * 5/9; // Fahrenheit to Celsius
            printf("%.2lf Fahrenheit = %.2lf Celsius\n", value, result);
            break;
        default:
            printf("Invalid temperature option.\n");
    }
}

void temperatureInstructions() {
    printf("=== Temperature Conversion ===\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
}

void volumeConverter() {
    int choice;
    volumeInstructions();
    printf("Your choice: ");
    scanf("%d", &choice);
    performVolumeConversion(choice);
}

void performVolumeConversion(int choice) {
    double value, result;

    switch (choice) {
        case 1:
            printf("Enter volume in liters: ");
            scanf("%lf", &value);
            result = value * 1000; // Liters to Milliliters
            printf("%.2lf liters = %.2lf milliliters\n", value, result);
            break;
        case 2:
            printf("Enter volume in gallons: ");
            scanf("%lf", &value);
            result = value * 3785.41; // Gallons to Milliliters
            printf("%.2lf gallons = %.2lf milliliters\n", value, result);
            break;
        default:
            printf("Invalid volume option.\n");
    }
}

void volumeInstructions() {
    printf("=== Volume Conversion ===\n");
    printf("1. Liters to Milliliters\n");
    printf("2. Gallons to Milliliters\n");
}

void areaConverter() {
    int choice;
    areaInstructions();
    printf("Your choice: ");
    scanf("%d", &choice);
    performAreaConversion(choice);
}

void performAreaConversion(int choice) {
    double value, result;

    switch (choice) {
        case 1:
            printf("Enter area in acres: ");
            scanf("%lf", &value);
            result = value * 4046.86; // Acres to Square Meters
            printf("%.2lf acres = %.2lf square meters\n", value, result);
            break;
        case 2:
            printf("Enter area in square feet: ");
            scanf("%lf", &value);
            result = value * 0.092903; // Square Feet to Square Meters
            printf("%.2lf square feet = %.2lf square meters\n", value, result);
            break;
        default:
            printf("Invalid area option.\n");
    }
}

void areaInstructions() {
    printf("=== Area Conversion ===\n");
    printf("1. Acres to Square Meters\n");
    printf("2. Square Feet to Square Meters\n");
}

void currencyConverter() {
    int choice;
    currencyInstructions();
    printf("Your choice: ");
    scanf("%d", &choice);
    performCurrencyConversion(choice);
}

void performCurrencyConversion(int choice) {
    double value, result;

    switch (choice) {
        case 1:
            printf("Enter amount in USD: ");
            scanf("%lf", &value);
            result = value * 0.85; // USD to Euro
            printf("%.2lf USD = %.2lf Euros\n", value, result);
            break;
        case 2:
            printf("Enter amount in Euros: ");
            scanf("%lf", &value);
            result = value * 1.176; // Euro to USD
            printf("%.2lf Euros = %.2lf USD\n", value, result);
            break;
        default:
            printf("Invalid currency option.\n");
    }
}

void currencyInstructions() {
    printf("=== Currency Conversion ===\n");
    printf("1. USD to Euro\n");
    printf("2. Euro to USD\n");
}