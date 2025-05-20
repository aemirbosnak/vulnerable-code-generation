//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n===== Unit Converter =====\n");
    printf("1. Convert Length\n");
    printf("2. Convert Weight\n");
    printf("3. Convert Temperature\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void convertLength() {
    double value;
    int choice;

    printf("Length Conversion:\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Kilometers to Meters\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("Choose a conversion: ");
    scanf("%d", &choice);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            printf("%.2lf Meters = %.2lf Kilometers\n", value, value / 1000);
            break;
        case 2:
            printf("%.2lf Kilometers = %.2lf Meters\n", value, value * 1000);
            break;
        case 3:
            printf("%.2lf Miles = %.2lf Kilometers\n", value, value * 1.60934);
            break;
        case 4:
            printf("%.2lf Kilometers = %.2lf Miles\n", value, value / 1.60934);
            break;
        default:
            printf("Invalid choice!\n");
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
    printf("Choose a conversion: ");
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
            printf("Invalid choice!\n");
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
    printf("Choose a conversion: ");
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
            printf("Invalid choice!\n");
    }
}

int main() {
    int option;

    do {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
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
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }

    } while (option != 4);

    return 0;
}