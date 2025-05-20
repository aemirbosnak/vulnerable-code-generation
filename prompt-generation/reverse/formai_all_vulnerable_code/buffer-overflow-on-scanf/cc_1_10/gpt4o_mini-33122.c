//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>

// Function prototypes
void displayMenu();
void convertLength();
void convertWeight();
void convertTemperature();
double lengthConversion(double value, char unit);
double weightConversion(double value, char unit);
double temperatureConversion(double value, char unit);
void clearBuffer();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice (1-4): ");
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
                printf("Exiting the program. Thank you for using the Unit Converter!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }
}

void displayMenu() {
    printf("=========================================\n");
    printf("         Welcome to Unit Converter\n");
    printf("=========================================\n");
    printf("1. Convert Length\n");
    printf("2. Convert Weight\n");
    printf("3. Convert Temperature\n");
    printf("4. Exit\n");
}

void convertLength() {
    double value;
    char unit;
    printf("Enter the length value followed by its unit (m for meters, km for kilometers, ft for feet, in for inches): ");
    scanf("%lf %c", &value, &unit);

    double convertedValue = lengthConversion(value, unit);
    printf("Converted Value: %.2f m\n", convertedValue);
}

void convertWeight() {
    double value;
    char unit;
    printf("Enter the weight value followed by its unit (g for grams, kg for kilograms, lb for pounds, oz for ounces): ");
    scanf("%lf %c", &value, &unit);

    double convertedValue = weightConversion(value, unit);
    printf("Converted Value: %.2f kg\n", convertedValue);
}

void convertTemperature() {
    double value;
    char unit;
    printf("Enter the temperature value followed by its unit (C for Celsius, F for Fahrenheit, K for Kelvin): ");
    scanf("%lf %c", &value, &unit);

    double convertedValue = temperatureConversion(value, unit);
    printf("Converted Value: %.2f K\n", convertedValue);
}

double lengthConversion(double value, char unit) {
    switch (unit) {
        case 'm': return value; // meters to meters
        case 'k': return value * 1000; // kilometers to meters
        case 'f': return value * 0.3048; // feet to meters
        case 'i': return value * 0.0254; // inches to meters
        default: 
            printf("Invalid length unit provided.\n");
            return 0;
    }
}

double weightConversion(double value, char unit) {
    switch (unit) {
        case 'g': return value / 1000; // grams to kilograms
        case 'k': return value; // kilograms to kilograms
        case 'l': return value * 0.453592; // pounds to kilograms
        case 'o': return value * 0.0283495; // ounces to kilograms
        default: 
            printf("Invalid weight unit provided.\n");
            return 0;
    }
}

double temperatureConversion(double value, char unit) {
    switch (unit) {
        case 'C': return value + 273.15; // Celsius to Kelvin
        case 'F': return (value - 32) * 5.0 / 9.0 + 273.15; // Fahrenheit to Kelvin
        case 'K': return value; // Kelvin to Kelvin
        default: 
            printf("Invalid temperature unit provided.\n");
            return 0;
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}