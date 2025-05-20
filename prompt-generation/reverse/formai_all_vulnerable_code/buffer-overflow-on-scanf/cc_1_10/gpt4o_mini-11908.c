//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void displayMenu();
void convertLength();
void convertWeight();
void convertTemperature();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-4, 0 to exit): ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear buffer to remove any extra input

        switch (choice) {
            case 1: convertLength(); break;
            case 2: convertWeight(); break;
            case 3: convertTemperature(); break;
            case 0: printf("Exiting the unit converter. Goodbye!\n"); return 0;
            default: printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }
    return 0;
}

void displayMenu() {
    printf("Unit Converter Menu:\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("0. Exit\n");
}

void convertLength() {
    double value;
    char unit[3];

    printf("Length Conversion:\n");
    printf("Enter value (e.g., 5.5): ");
    scanf("%lf", &value);
    clearInputBuffer(); // Clear buffer for unit input

    printf("Enter unit (m for meters, km for kilometers, ft for feet, in for inches): ");
    fgets(unit, sizeof(unit), stdin);
    unit[strcspn(unit, "\n")] = 0; // Remove newline character

    if (strcmp(unit, "m") == 0) {
        printf("%.2f meters = %.2f kilometers\n", value, value / 1000);
        printf("%.2f meters = %.2f feet\n", value, value * 3.28084);
        printf("%.2f meters = %.2f inches\n", value, value * 39.3701);
    } else if (strcmp(unit, "km") == 0) {
        printf("%.2f kilometers = %.2f meters\n", value, value * 1000);
        printf("%.2f kilometers = %.2f feet\n", value, value * 3280.84);
        printf("%.2f kilometers = %.2f inches\n", value, value * 39370.1);
    } else if (strcmp(unit, "ft") == 0) {
        printf("%.2f feet = %.2f meters\n", value, value / 3.28084);
        printf("%.2f feet = %.2f kilometers\n", value, value / 3280.84);
        printf("%.2f feet = %.2f inches\n", value, value * 12);
    } else if (strcmp(unit, "in") == 0) {
        printf("%.2f inches = %.2f meters\n", value, value / 39.3701);
        printf("%.2f inches = %.2f kilometers\n", value, value / 39370.1);
        printf("%.2f inches = %.2f feet\n", value, value / 12);
    } else {
        printf("Invalid unit.\n");
    }
}

void convertWeight() {
    double value;
    char unit[3];

    printf("Weight Conversion:\n");
    printf("Enter value (e.g., 70.5): ");
    scanf("%lf", &value);
    clearInputBuffer(); 

    printf("Enter unit (kg for kilograms, lb for pounds, g for grams): ");
    fgets(unit, sizeof(unit), stdin);
    unit[strcspn(unit, "\n")] = 0;

    if (strcmp(unit, "kg") == 0) {
        printf("%.2f kilograms = %.2f pounds\n", value, value * 2.20462);
        printf("%.2f kilograms = %.2f grams\n", value, value * 1000);
    } else if (strcmp(unit, "lb") == 0) {
        printf("%.2f pounds = %.2f kilograms\n", value, value / 2.20462);
        printf("%.2f pounds = %.2f grams\n", value, value / 0.00220462);
    } else if (strcmp(unit, "g") == 0) {
        printf("%.2f grams = %.2f kilograms\n", value, value / 1000);
        printf("%.2f grams = %.2f pounds\n", value, value * 0.00220462);
    } else {
        printf("Invalid unit.\n");
    }
}

void convertTemperature() {
    double value;
    char unit[3];

    printf("Temperature Conversion:\n");
    printf("Enter value (e.g., 32): ");
    scanf("%lf", &value);
    clearInputBuffer();

    printf("Enter unit (C for Celsius, F for Fahrenheit, K for Kelvin): ");
    fgets(unit, sizeof(unit), stdin);
    unit[strcspn(unit, "\n")] = 0;

    if (strcmp(unit, "C") == 0) {
        printf("%.2f Celsius = %.2f Fahrenheit\n", value, (value * 9/5) + 32);
        printf("%.2f Celsius = %.2f Kelvin\n", value, value + 273.15);
    } else if (strcmp(unit, "F") == 0) {
        printf("%.2f Fahrenheit = %.2f Celsius\n", value, (value - 32) * 5/9);
        printf("%.2f Fahrenheit = %.2f Kelvin\n", value, (value - 32) * 5/9 + 273.15);
    } else if (strcmp(unit, "K") == 0) {
        printf("%.2f Kelvin = %.2f Celsius\n", value, value - 273.15);
        printf("%.2f Kelvin = %.2f Fahrenheit\n", value, (value - 273.15) * 9/5 + 32);
    } else {
        printf("Invalid unit.\n");
    }
}

void clearInputBuffer() {
    while (getchar() != '\n');
}