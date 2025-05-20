//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void displayMenu();
void convertLength();
void convertWeight();
void convertTemperature();

// The main function
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
            printf("Exiting the program. Thank you!\n");
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

// Function to display the conversion menu
void displayMenu() {
    printf("\n=======================\n");
    printf(" Unit Conversion Menu\n");
    printf("=======================\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Exit\n");
}

// Function to convert lengths
void convertLength() {
    double value, convertedValue;
    int choice;

    printf("\nLength Conversion:\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    
    printf("Select your conversion choice (1-4): ");
    scanf("%d", &choice);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
    case 1:
        convertedValue = value * 3.28084;
        printf("%.2lf meters is equal to %.2lf feet.\n", value, convertedValue);
        break;
    case 2:
        convertedValue = value / 3.28084;
        printf("%.2lf feet is equal to %.2lf meters.\n", value, convertedValue);
        break;
    case 3:
        convertedValue = value * 0.621371;
        printf("%.2lf kilometers is equal to %.2lf miles.\n", value, convertedValue);
        break;
    case 4:
        convertedValue = value / 0.621371;
        printf("%.2lf miles is equal to %.2lf kilometers.\n", value, convertedValue);
        break;
    default:
        printf("Invalid choice.\n");
    }
}

// Function to convert weights
void convertWeight() {
    double value, convertedValue;
    int choice;

    printf("\nWeight Conversion:\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Grams to Ounces\n");
    printf("4. Ounces to Grams\n");

    printf("Select your conversion choice (1-4): ");
    scanf("%d", &choice);
    
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
    case 1:
        convertedValue = value * 2.20462;
        printf("%.2lf kilograms is equal to %.2lf pounds.\n", value, convertedValue);
        break;
    case 2:
        convertedValue = value / 2.20462;
        printf("%.2lf pounds is equal to %.2lf kilograms.\n", value, convertedValue);
        break;
    case 3:
        convertedValue = value * 0.035274;
        printf("%.2lf grams is equal to %.2lf ounces.\n", value, convertedValue);
        break;
    case 4:
        convertedValue = value / 0.035274;
        printf("%.2lf ounces is equal to %.2lf grams.\n", value, convertedValue);
        break;
    default:
        printf("Invalid choice.\n");
    }
}

// Function to convert temperatures
void convertTemperature() {
    double value, convertedValue;
    int choice;

    printf("\nTemperature Conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");

    printf("Select your conversion choice (1-4): ");
    scanf("%d", &choice);
    
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
    case 1:
        convertedValue = (value * 9.0/5.0) + 32.0;
        printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", value, convertedValue);
        break;
    case 2:
        convertedValue = (value - 32.0) * 5.0/9.0;
        printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", value, convertedValue);
        break;
    case 3:
        convertedValue = value + 273.15;
        printf("%.2lf Celsius is equal to %.2lf Kelvin.\n", value, convertedValue);
        break;
    case 4:
        convertedValue = value - 273.15;
        printf("%.2lf Kelvin is equal to %.2lf Celsius.\n", value, convertedValue);
        break;
    default:
        printf("Invalid choice.\n");
    }
}