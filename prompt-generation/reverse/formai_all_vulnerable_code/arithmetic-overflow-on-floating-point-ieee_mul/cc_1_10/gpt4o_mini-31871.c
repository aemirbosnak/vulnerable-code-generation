//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include <stdio.h>

void displayMenu();
void convertLength();
void convertWeight();
void convertTemperature();

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice (1-4, or 0 to exit): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: convertLength(); break;
            case 2: convertWeight(); break;
            case 3: convertTemperature(); break;
            case 0: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}

void displayMenu() {
    printf("\n--- Unit Converter ---\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("0. Exit\n");
}

void convertLength() {
    float value;
    int choice;
    printf("Enter length value: ");
    scanf("%f", &value);
    printf("Convert from:\n1. Meters\n2. Kilometers\n3. Miles\n");
    printf("Select an option: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("%.2f Meters = %.2f Kilometers\n", value, value / 1000);
            printf("%.2f Meters = %.2f Miles\n", value, value / 1609.34);
            break;
        case 2:
            printf("%.2f Kilometers = %.2f Meters\n", value, value * 1000);
            printf("%.2f Kilometers = %.2f Miles\n", value, value / 1.60934);
            break;
        case 3:
            printf("%.2f Miles = %.2f Meters\n", value, value * 1609.34);
            printf("%.2f Miles = %.2f Kilometers\n", value, value * 1.60934);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

void convertWeight() {
    float value;
    int choice;
    printf("Enter weight value: ");
    scanf("%f", &value);
    printf("Convert from:\n1. Grams\n2. Kilograms\n3. Pounds\n");
    printf("Select an option: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("%.2f Grams = %.2f Kilograms\n", value, value / 1000);
            printf("%.2f Grams = %.2f Pounds\n", value, value / 453.592);
            break;
        case 2:
            printf("%.2f Kilograms = %.2f Grams\n", value, value * 1000);
            printf("%.2f Kilograms = %.2f Pounds\n", value, value * 2.20462);
            break;
        case 3:
            printf("%.2f Pounds = %.2f Grams\n", value, value * 453.592);
            printf("%.2f Pounds = %.2f Kilograms\n", value, value / 2.20462);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

void convertTemperature() {
    float value;
    int choice;
    printf("Enter temperature value: ");
    scanf("%f", &value);
    printf("Convert from:\n1. Celsius\n2. Fahrenheit\n3. Kelvin\n");
    printf("Select an option: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("%.2f Celsius = %.2f Fahrenheit\n", value, (value * 9/5) + 32);
            printf("%.2f Celsius = %.2f Kelvin\n", value, value + 273.15);
            break;
        case 2:
            printf("%.2f Fahrenheit = %.2f Celsius\n", value, (value - 32) * 5/9);
            printf("%.2f Fahrenheit = %.2f Kelvin\n", value, (value - 32) * 5/9 + 273.15);
            break;
        case 3:
            printf("%.2f Kelvin = %.2f Celsius\n", value, value - 273.15);
            printf("%.2f Kelvin = %.2f Fahrenheit\n", value, (value - 273.15) * 9/5 + 32);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}