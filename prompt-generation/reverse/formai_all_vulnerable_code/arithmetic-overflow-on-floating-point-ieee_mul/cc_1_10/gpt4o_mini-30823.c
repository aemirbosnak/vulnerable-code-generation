//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>

void convertLength();
void convertWeight();
void convertTemperature();
void displayMenu();

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
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please choose again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== Unit Converter ===\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Exit\n");
}

void convertLength() {
    double value;
    int choice;
    printf("Length Conversion:\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("Choose a conversion (1-4): ");
    scanf("%d", &choice);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            printf("%.2lf Meters = %.2lf Feet\n", value, value * 3.28084);
            break;
        case 2:
            printf("%.2lf Feet = %.2lf Meters\n", value, value / 3.28084);
            break;
        case 3:
            printf("%.2lf Kilometers = %.2lf Miles\n", value, value * 0.621371);
            break;
        case 4:
            printf("%.2lf Miles = %.2lf Kilometers\n", value, value / 0.621371);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void convertWeight() {
    double value;
    int choice;
    printf("Weight Conversion:\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Grams to Ounces\n");
    printf("4. Ounces to Grams\n");
    printf("Choose a conversion (1-4): ");
    scanf("%d", &choice);
  
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            printf("%.2lf Kilograms = %.2lf Pounds\n", value, value * 2.20462);
            break;
        case 2:
            printf("%.2lf Pounds = %.2lf Kilograms\n", value, value / 2.20462);
            break;
        case 3:
            printf("%.2lf Grams = %.2lf Ounces\n", value, value / 28.3495);
            break;
        case 4:
            printf("%.2lf Ounces = %.2lf Grams\n", value, value * 28.3495);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void convertTemperature() {
    double value;
    int choice;
    printf("Temperature Conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    printf("Choose a conversion (1-4): ");
    scanf("%d", &choice);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            printf("%.2lf Celsius = %.2lf Fahrenheit\n", value, (value * 9/5) + 32);
            break;
        case 2:
            printf("%.2lf Fahrenheit = %.2lf Celsius\n", value, (value - 32) * 5/9);
            break;
        case 3:
            printf("%.2lf Kelvin = %.2lf Celsius\n", value, value - 273.15);
            break;
        case 4:
            printf("%.2lf Celsius = %.2lf Kelvin\n", value, value + 273.15);
            break;
        default:
            printf("Invalid choice.\n");
    }
}