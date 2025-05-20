//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
void convertLength();
void convertWeight();
void convertTemperature();
void convertArea();
void convertVolume();
void clearInputBuffer();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-5, 0 to exit): ");
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1: convertLength(); break;
            case 2: convertWeight(); break;
            case 3: convertTemperature(); break;
            case 4: convertArea(); break;
            case 5: convertVolume(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}

void displayMenu() {
    printf("\n----- Unit Converter -----\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Area Conversion\n");
    printf("5. Volume Conversion\n");
    printf("0. Exit\n");
}

void convertLength() {
    double value;
    int choice;

    printf("Enter length in meters: ");
    scanf("%lf", &value);
    
    printf("Convert to:\n");
    printf("1. Kilometers\n2. Centimeters\n3. Millimeters\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: printf("%.2f meters = %.2f kilometers\n", value, value / 1000); break;
        case 2: printf("%.2f meters = %.2f centimeters\n", value, value * 100); break;
        case 3: printf("%.2f meters = %.2f millimeters\n", value, value * 1000); break;
        default: printf("Invalid choice.\n");
    }
}

void convertWeight() {
    double value;
    int choice;

    printf("Enter weight in kilograms: ");
    scanf("%lf", &value);
    
    printf("Convert to:\n");
    printf("1. Grams\n2. Pounds\n3. Ounces\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: printf("%.2f kilograms = %.2f grams\n", value, value * 1000); break;
        case 2: printf("%.2f kilograms = %.2f pounds\n", value, value * 2.20462); break;
        case 3: printf("%.2f kilograms = %.2f ounces\n", value, value * 35.274); break;
        default: printf("Invalid choice.\n");
    }
}

void convertTemperature() {
    double value;
    int choice;

    printf("Enter temperature in Celsius: ");
    scanf("%lf", &value);
    
    printf("Convert to:\n");
    printf("1. Fahrenheit\n2. Kelvin\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: printf("%.2f Celsius = %.2f Fahrenheit\n", value, (value * 9/5) + 32); break;
        case 2: printf("%.2f Celsius = %.2f Kelvin\n", value, value + 273.15); break;
        default: printf("Invalid choice.\n");
    }
}

void convertArea() {
    double value;
    int choice;

    printf("Enter area in square meters: ");
    scanf("%lf", &value);
    
    printf("Convert to:\n");
    printf("1. Square feet\n2. Acres\n3. Hectares\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: printf("%.2f square meters = %.2f square feet\n", value, value * 10.7639); break;
        case 2: printf("%.2f square meters = %.2f acres\n", value, value * 0.000247105); break;
        case 3: printf("%.2f square meters = %.2f hectares\n", value, value * 0.0001); break;
        default: printf("Invalid choice.\n");
    }
}

void convertVolume() {
    double value;
    int choice;

    printf("Enter volume in liters: ");
    scanf("%lf", &value);
    
    printf("Convert to:\n");
    printf("1. Gallons\n2. Milliliters\n3. Cubic meters\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: printf("%.2f liters = %.2f gallons\n", value, value * 0.264172); break;
        case 2: printf("%.2f liters = %.2f milliliters\n", value, value * 1000); break;
        case 3: printf("%.2f liters = %.2f cubic meters\n", value, value / 1000); break;
        default: printf("Invalid choice.\n");
    }
}

void clearInputBuffer() {
    while (getchar() != '\n');
}