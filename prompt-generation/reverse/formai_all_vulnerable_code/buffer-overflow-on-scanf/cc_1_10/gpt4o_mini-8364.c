//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void print_welcome() {
    printf("===============================================\n");
    printf("       Welcome to the Peaceful Unit Converter   \n");
    printf("===============================================\n");
    printf(" A place where all your unit conversion dreams  \n");
    printf("     blossom into reality with harmony.         \n");
    printf("===============================================\n");
}

void print_menu() {
    printf("\nChoose the type of conversion:\n");
    printf("1. Length\n");
    printf("2. Mass\n");
    printf("3. Temperature\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void length_converter() {
    double value;
    int choice;
    
    printf("Select the type of length conversion:\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Kilometers to Meters\n");
    printf("3. Inches to Centimeters\n");
    printf("4. Centimeters to Inches\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            printf("Result: %.5lf Kilometers\n", value / 1000);
            break;
        case 2:
            printf("Result: %.5lf Meters\n", value * 1000);
            break;
        case 3:
            printf("Result: %.5lf Centimeters\n", value * 2.54);
            break;
        case 4:
            printf("Result: %.5lf Inches\n", value / 2.54);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void mass_converter() {
    double value;
    int choice;

    printf("Select the type of mass conversion:\n");
    printf("1. Kilograms to Grams\n");
    printf("2. Grams to Kilograms\n");
    printf("3. Pounds to Kilograms\n");
    printf("4. Kilograms to Pounds\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            printf("Result: %.5lf Grams\n", value * 1000);
            break;
        case 2:
            printf("Result: %.5lf Kilograms\n", value / 1000);
            break;
        case 3:
            printf("Result: %.5lf Kilograms\n", value * 0.453592);
            break;
        case 4:
            printf("Result: %.5lf Pounds\n", value / 0.453592);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void temperature_converter() {
    double value;
    int choice;

    printf("Select the type of temperature conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            printf("Result: %.5lf Fahrenheit\n", (value * 9/5) + 32);
            break;
        case 2:
            printf("Result: %.5lf Celsius\n", (value - 32) * 5/9);
            break;
        case 3:
            printf("Result: %.5lf Kelvin\n", value + 273.15);
            break;
        case 4:
            printf("Result: %.5lf Celsius\n", value - 273.15);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

int main() {
    print_welcome();
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                length_converter();
                break;
            case 2:
                mass_converter();
                break;
            case 3:
                temperature_converter();
                break;
            case 4:
                printf("Thank you for using the Peaceful Unit Converter.\n");
                break;
            default:
                printf("Please select a valid option from the menu.\n");
        }
    } while (choice != 4);

    return 0;
}