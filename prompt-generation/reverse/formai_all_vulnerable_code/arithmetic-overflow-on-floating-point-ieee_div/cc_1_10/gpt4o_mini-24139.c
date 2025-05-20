//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

void show_menu();
void length_conversion();
void weight_conversion();
void temperature_conversion();
void exit_program();

int main() {
    int choice;

    do {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                length_conversion();
                break;
            case 2:
                weight_conversion();
                break;
            case 3:
                temperature_conversion();
                break;
            case 4:
                exit_program();
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void show_menu() {
    printf("\n=== Unit Converter Menu ===\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Exit\n");
}

void length_conversion() {
    int option;
    double value;

    printf("\nLength Conversion Options:\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Kilometers to Meters\n");
    printf("3. Meters to Miles\n");
    printf("4. Miles to Meters\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (option) {
        case 1:
            printf("%.2lf Meters = %.2lf Kilometers\n", value, value / 1000);
            break;
        case 2:
            printf("%.2lf Kilometers = %.2lf Meters\n", value, value * 1000);
            break;
        case 3:
            printf("%.2lf Meters = %.2lf Miles\n", value, value * 0.000621371);
            break;
        case 4:
            printf("%.2lf Miles = %.2lf Meters\n", value, value / 0.000621371);
            break;
        default:
            printf("Invalid option!\n");
            break;
    }
}

void weight_conversion() {
    int option;
    double value;

    printf("\nWeight Conversion Options:\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Grams to Ounces\n");
    printf("4. Ounces to Grams\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (option) {
        case 1:
            printf("%.2lf Kilograms = %.2lf Pounds\n", value, value * 2.20462);
            break;
        case 2:
            printf("%.2lf Pounds = %.2lf Kilograms\n", value, value / 2.20462);
            break;
        case 3:
            printf("%.2lf Grams = %.2lf Ounces\n", value, value * 0.035274);
            break;
        case 4:
            printf("%.2lf Ounces = %.2lf Grams\n", value, value / 0.035274);
            break;
        default:
            printf("Invalid option!\n");
            break;
    }
}

void temperature_conversion() {
    int option;
    double value;

    printf("\nTemperature Conversion Options:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (option) {
        case 1:
            printf("%.2lf Celsius = %.2lf Fahrenheit\n", value, (value * 9/5) + 32);
            break;
        case 2:
            printf("%.2lf Fahrenheit = %.2lf Celsius\n", value, (value - 32) * 5/9);
            break;
        case 3:
            printf("%.2lf Celsius = %.2lf Kelvin\n", value, value + 273.15);
            break;
        case 4:
            printf("%.2lf Kelvin = %.2lf Celsius\n", value, value - 273.15);
            break;
        default:
            printf("Invalid option!\n");
            break;
    }
}

void exit_program() {
    printf("Thank you for using the unit converter! Goodbye!\n");
    exit(0);
}