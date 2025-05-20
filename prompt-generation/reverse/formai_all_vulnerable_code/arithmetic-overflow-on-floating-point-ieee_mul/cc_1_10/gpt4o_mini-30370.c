//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void displayMenu();
void convertLength();
void convertWeight();
void convertTemperature();
void convertArea();
void convertVolume();
void handleInvalidInput();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-6, or 0 to exit): ");
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
                convertVolume();
                break;
            case 0:
                printf("Exiting the unit converter. Goodbye!\n");
                exit(0);
            default:
                handleInvalidInput();
                break;
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n=== Unit Converter ===\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Area\n");
    printf("5. Volume\n");
    printf("0. Exit\n");
    printf("=======================\n");
}

void convertLength() {
    double value;
    int choice;
    
    printf("Length Conversion:\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    printf("Enter value: ");
    scanf("%lf", &value);
    
    if (choice == 1) {
        printf("%.2f Meters = %.2f Feet\n", value, value * 3.28084);
    } else {
        printf("%.2f Feet = %.2f Meters\n", value, value / 3.28084);
    }
}

void convertWeight() {
    double value;
    int choice;
    
    printf("Weight Conversion:\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    printf("Enter value: ");
    scanf("%lf", &value);
    
    if (choice == 1) {
        printf("%.2f Kilograms = %.2f Pounds\n", value, value * 2.20462);
    } else {
        printf("%.2f Pounds = %.2f Kilograms\n", value, value / 2.20462);
    }
}

void convertTemperature() {
    double value;
    int choice;

    printf("Temperature Conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    printf("Enter value: ");
    scanf("%lf", &value);
    
    if (choice == 1) {
        printf("%.2f Celsius = %.2f Fahrenheit\n", value, (value * 9/5) + 32);
    } else {
        printf("%.2f Fahrenheit = %.2f Celsius\n", value, (value - 32) * 5/9);
    }
}

void convertArea() {
    double value;
    int choice;

    printf("Area Conversion:\n");
    printf("1. Square Meters to Acres\n");
    printf("2. Acres to Square Meters\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    printf("Enter value: ");
    scanf("%lf", &value);
    
    if (choice == 1) {
        printf("%.2f Square Meters = %.2f Acres\n", value, value * 0.000247105);
    } else {
        printf("%.2f Acres = %.2f Square Meters\n", value, value / 0.000247105);
    }
}

void convertVolume() {
    double value;
    int choice;

    printf("Volume Conversion:\n");
    printf("1. Liters to Gallons\n");
    printf("2. Gallons to Liters\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter value: ");
    scanf("%lf", &value);
    
    if (choice == 1) {
        printf("%.2f Liters = %.2f Gallons\n", value, value * 0.264172);
    } else {
        printf("%.2f Gallons = %.2f Liters\n", value, value / 0.264172);
    }
}

void handleInvalidInput() {
    printf("Invalid input! Please select a valid option.\n");
}