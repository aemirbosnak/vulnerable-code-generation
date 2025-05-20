//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void displayMenu();
void lengthConversion();
void weightConversion();
void temperatureConversion();
void volumeConversion();
void currencyConversion();
double getDoubleInput(const char *prompt);
double convertLength(double value, int option);
double convertWeight(double value, int option);
double convertTemperature(double value, int option);
double convertVolume(double value, int option);
double convertCurrency(double value, int option);

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        choice = (int)getDoubleInput("Enter your choice (1-5, or 0 to quit): ");
        
        if (choice == 0) {
            printf("Exiting the unit converter. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                lengthConversion();
                break;
            case 2:
                weightConversion();
                break;
            case 3:
                temperatureConversion();
                break;
            case 4:
                volumeConversion();
                break;
            case 5:
                currencyConversion();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\nWelcome to the Unit Converter!\n");
    printf("Please choose a conversion type:\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Volume Conversion\n");
    printf("5. Currency Conversion\n");
    printf("0. Exit\n");
}

void lengthConversion() {
    int option;
    double value;

    printf("\nLength Conversion:\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    option = (int)getDoubleInput("Choose conversion type: ");
    value = getDoubleInput("Enter the value to convert: ");
    
    double result = convertLength(value, option);
    printf("Converted value: %.2f\n", result);
}

void weightConversion() {
    int option;
    double value;

    printf("\nWeight Conversion:\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Grams to Ounces\n");
    printf("4. Ounces to Grams\n");
    option = (int)getDoubleInput("Choose conversion type: ");
    value = getDoubleInput("Enter the value to convert: ");
    
    double result = convertWeight(value, option);
    printf("Converted value: %.2f\n", result);
}

void temperatureConversion() {
    int option;
    double value;

    printf("\nTemperature Conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    option = (int)getDoubleInput("Choose conversion type: ");
    value = getDoubleInput("Enter the value to convert: ");
    
    double result = convertTemperature(value, option);
    printf("Converted value: %.2f\n", result);
}

void volumeConversion() {
    int option;
    double value;

    printf("\nVolume Conversion:\n");
    printf("1. Liters to Gallons\n");
    printf("2. Gallons to Liters\n");
    printf("3. Milliliters to Fluid Ounces\n");
    printf("4. Fluid Ounces to Milliliters\n");
    option = (int)getDoubleInput("Choose conversion type: ");
    value = getDoubleInput("Enter the value to convert: ");
    
    double result = convertVolume(value, option);
    printf("Converted value: %.2f\n", result);
}

void currencyConversion() {
    int option;
    double value;

    printf("\nCurrency Conversion:\n");
    printf("1. USD to EUR\n");
    printf("2. EUR to USD\n");
    printf("3. GBP to USD\n");
    printf("4. USD to GBP\n");
    option = (int)getDoubleInput("Choose conversion type: ");
    value = getDoubleInput("Enter the amount to convert: ");
    
    double result = convertCurrency(value, option);
    printf("Converted value: %.2f\n", result);
}

// Function to get double input from the user
double getDoubleInput(const char *prompt) {
    double value;
    printf("%s", prompt);
    while (scanf("%lf", &value) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n'); // clear input buffer
    }
    while (getchar() != '\n'); // clear input buffer after reading value
    return value;
}

// Length conversion implementation
double convertLength(double value, int option) {
    switch (option) {
        case 1: return value * 3.28084; // Meters to Feet
        case 2: return value / 3.28084; // Feet to Meters
        case 3: return value * 0.621371; // Kilometers to Miles
        case 4: return value / 0.621371; // Miles to Kilometers
        default: return value; // Return original value for invalid option
    }
}

// Weight conversion implementation
double convertWeight(double value, int option) {
    switch (option) {
        case 1: return value * 2.20462; // Kilograms to Pounds
        case 2: return value / 2.20462; // Pounds to Kilograms
        case 3: return value * 0.035274; // Grams to Ounces
        case 4: return value / 0.035274; // Ounces to Grams
        default: return value; // Return original value for invalid option
    }
}

// Temperature conversion implementation
double convertTemperature(double value, int option) {
    switch (option) {
        case 1: return value * 9.0/5.0 + 32; // Celsius to Fahrenheit
        case 2: return (value - 32) * 5.0/9.0; // Fahrenheit to Celsius
        case 3: return value - 273.15; // Kelvin to Celsius
        case 4: return value + 273.15; // Celsius to Kelvin
        default: return value; // Return original value for invalid option
    }
}

// Volume conversion implementation
double convertVolume(double value, int option) {
    switch (option) {
        case 1: return value * 0.264172; // Liters to Gallons
        case 2: return value / 0.264172; // Gallons to Liters
        case 3: return value * 0.033814; // Milliliters to Fluid Ounces
        case 4: return value / 0.033814; // Fluid Ounces to Milliliters
        default: return value; // Return original value for invalid option
    }
}

// Currency conversion implementation
double convertCurrency(double value, int option) {
    const double usd_to_eur = 0.85; // Example conversion rate
    const double eur_to_usd = 1.18;
    const double gbp_to_usd = 1.39;
    const double usd_to_gbp = 0.72;

    switch (option) {
        case 1: return value * usd_to_eur; // USD to EUR
        case 2: return value * eur_to_usd; // EUR to USD
        case 3: return value * gbp_to_usd; // GBP to USD
        case 4: return value * usd_to_gbp; // USD to GBP
        default: return value; // Return original value for invalid option
    }
}