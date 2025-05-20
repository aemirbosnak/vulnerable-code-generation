//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: inquisitive
#include <stdio.h>

void displayMenu() {
    printf("Welcome to the Ultimate Unit Converter!\n");
    printf("Please select a conversion option:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Exit\n");
}

void lengthConversion() {
    int choice;
    double value, result;

    printf("Choose the length conversion:\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            result = value * 3.28084;
            printf("%.2lf meters is %.2lf feet\n", value, result);
            break;
        case 2:
            result = value * 0.3048;
            printf("%.2lf feet is %.2lf meters\n", value, result);
            break;
        case 3:
            result = value * 0.621371;
            printf("%.2lf kilometers is %.2lf miles\n", value, result);
            break;
        case 4:
            result = value * 1.60934;
            printf("%.2lf miles is %.2lf kilometers\n", value, result);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void weightConversion() {
    int choice;
    double value, result;

    printf("Choose the weight conversion:\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Grams to Ounces\n");
    printf("4. Ounces to Grams\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            result = value * 2.20462;
            printf("%.2lf kilograms is %.2lf pounds\n", value, result);
            break;
        case 2:
            result = value * 0.453592;
            printf("%.2lf pounds is %.2lf kilograms\n", value, result);
            break;
        case 3:
            result = value * 0.035274;
            printf("%.2lf grams is %.2lf ounces\n", value, result);
            break;
        case 4:
            result = value * 28.3495;
            printf("%.2lf ounces is %.2lf grams\n", value, result);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void temperatureConversion() {
    int choice;
    double value, result;

    printf("Choose the temperature conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            result = (value * 9/5) + 32;
            printf("%.2lf Celsius is %.2lf Fahrenheit\n", value, result);
            break;
        case 2:
            result = (value - 32) * 5/9;
            printf("%.2lf Fahrenheit is %.2lf Celsius\n", value, result);
            break;
        case 3:
            result = value - 273.15;
            printf("%.2lf Kelvin is %.2lf Celsius\n", value, result);
            break;
        case 4:
            result = value + 273.15;
            printf("%.2lf Celsius is %.2lf Kelvin\n", value, result);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

int main() {
    int option;

    while (1) {
        displayMenu();
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                lengthConversion();
                break;
            case 2:
                weightConversion();
                break;
            case 3:
                temperatureConversion();
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                return 0;
            default:
                printf("Invalid option. Please select a valid option.\n");
        }
        printf("\n");
    }

    return 0;
}