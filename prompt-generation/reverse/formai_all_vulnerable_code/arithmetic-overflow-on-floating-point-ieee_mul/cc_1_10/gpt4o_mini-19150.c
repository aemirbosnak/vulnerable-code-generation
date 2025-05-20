//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: decentralized
#include <stdio.h>

// Function Declarations
void convertLength();
void convertTemperature();
void convertWeight();
void printMainMenu();
void printGoodbye();

// Function to convert Length
void convertLength() {
    int choice;
    float length, convertedLength;
    printf("\nLength Conversion:\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter length in meters: ");
        scanf("%f", &length);
        convertedLength = length * 3.28084; // Meters to Feet
        printf("%.2f meters = %.2f feet\n", length, convertedLength);
    } else if (choice == 2) {
        printf("Enter length in feet: ");
        scanf("%f", &length);
        convertedLength = length * 0.3048; // Feet to Meters
        printf("%.2f feet = %.2f meters\n", length, convertedLength);
    } else {
        printf("Invalid option. Please try again.\n");
    }
}

// Function to convert Temperature
void convertTemperature() {
    int choice;
    float temperature, convertedTemperature;
    printf("\nTemperature Conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        convertedTemperature = (temperature * 9 / 5) + 32; // Celsius to Fahrenheit
        printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, convertedTemperature);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        convertedTemperature = (temperature - 32) * 5 / 9; // Fahrenheit to Celsius
        printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, convertedTemperature);
    } else {
        printf("Invalid option. Please try again.\n");
    }
}

// Function to convert Weight
void convertWeight() {
    int choice;
    float weight, convertedWeight;
    printf("\nWeight Conversion:\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter weight in kilograms: ");
        scanf("%f", &weight);
        convertedWeight = weight * 2.20462; // Kilograms to Pounds
        printf("%.2f kilograms = %.2f pounds\n", weight, convertedWeight);
    } else if (choice == 2) {
        printf("Enter weight in pounds: ");
        scanf("%f", &weight);
        convertedWeight = weight * 0.453592; // Pounds to Kilograms
        printf("%.2f pounds = %.2f kilograms\n", weight, convertedWeight);
    } else {
        printf("Invalid option. Please try again.\n");
    }
}

// Main menu to choose the conversion type
void printMainMenu() {
    printf("\nUnit Converter:\n");
    printf("1. Length Conversion\n");
    printf("2. Temperature Conversion\n");
    printf("3. Weight Conversion\n");
    printf("4. Exit\n");
    printf("Select an option (1-4): ");
}

// Goodbye message 
void printGoodbye() {
    printf("\nThank you for using the Unit Converter. Goodbye!\n");
}

int main() {
    int option;

    do {
        printMainMenu();
        scanf("%d", &option);

        switch (option) {
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
                printGoodbye();
                break;
            default:
                printf("Invalid option, please try again!\n");
                break;
        }
    } while (option != 4);

    return 0;
}