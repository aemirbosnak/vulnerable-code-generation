//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>

void lengthConverter();
void weightConverter();
void temperatureConverter();
void displayMainMenu();
void displayLengthMenu();
void displayWeightMenu();
void displayTemperatureMenu();

int main() {
    int choice;
    while (1) {
        displayMainMenu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: lengthConverter(); break;
            case 2: weightConverter(); break;
            case 3: temperatureConverter(); break;
            case 4: 
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMainMenu() {
    printf("\n--- Unit Converter ---\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Exit\n");
}

void displayLengthMenu() {
    printf("\n--- Length Converter ---\n");
    printf("1. Meters to Yards\n");
    printf("2. Yards to Meters\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
}

void lengthConverter() {
    int choice;
    double value, result;
    displayLengthMenu();
    printf("Choose a conversion (1-4): ");
    scanf("%d", &choice);
    
    printf("Enter value: ");
    scanf("%lf", &value);
    
    switch (choice) {
        case 1:
            result = value * 1.09361; // Meters to Yards
            printf("%.2lf Meters = %.2lf Yards\n", value, result);
            break;
        case 2:
            result = value * 0.9144; // Yards to Meters
            printf("%.2lf Yards = %.2lf Meters\n", value, result);
            break;
        case 3:
            result = value * 0.621371; // Kilometers to Miles
            printf("%.2lf Kilometers = %.2lf Miles\n", value, result);
            break;
        case 4:
            result = value * 1.60934; // Miles to Kilometers
            printf("%.2lf Miles = %.2lf Kilometers\n", value, result);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void displayWeightMenu() {
    printf("\n--- Weight Converter ---\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Grams to Ounces\n");
    printf("4. Ounces to Grams\n");
}

void weightConverter() {
    int choice;
    double value, result;
    displayWeightMenu();
    printf("Choose a conversion (1-4): ");
    scanf("%d", &choice);
    
    printf("Enter value: ");
    scanf("%lf", &value);
    
    switch (choice) {
        case 1:
            result = value * 2.20462; // Kilograms to Pounds
            printf("%.2lf Kilograms = %.2lf Pounds\n", value, result);
            break;
        case 2:
            result = value * 0.453592; // Pounds to Kilograms
            printf("%.2lf Pounds = %.2lf Kilograms\n", value, result);
            break;
        case 3:
            result = value * 0.035274; // Grams to Ounces
            printf("%.2lf Grams = %.2lf Ounces\n", value, result);
            break;
        case 4:
            result = value * 28.3495; // Ounces to Grams
            printf("%.2lf Ounces = %.2lf Grams\n", value, result);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void displayTemperatureMenu() {
    printf("\n--- Temperature Converter ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
}

void temperatureConverter() {
    int choice;
    double value, result;
    displayTemperatureMenu();
    printf("Choose a conversion (1-4): ");
    scanf("%d", &choice);
    
    printf("Enter value: ");
    scanf("%lf", &value);
    
    switch (choice) {
        case 1:
            result = (value * 9/5) + 32; // Celsius to Fahrenheit
            printf("%.2lf Celsius = %.2lf Fahrenheit\n", value, result);
            break;
        case 2:
            result = (value - 32) * 5/9; // Fahrenheit to Celsius
            printf("%.2lf Fahrenheit = %.2lf Celsius\n", value, result);
            break;
        case 3:
            result = value - 273.15; // Kelvin to Celsius
            printf("%.2lf Kelvin = %.2lf Celsius\n", value, result);
            break;
        case 4:
            result = value + 273.15; // Celsius to Kelvin
            printf("%.2lf Celsius = %.2lf Kelvin\n", value, result);
            break;
        default:
            printf("Invalid choice.\n");
    }
}