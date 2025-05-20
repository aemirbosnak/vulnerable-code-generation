//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>

void displayMenu() {
    printf("Unit Converter\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void lengthConverter() {
    double meters;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    printf("In kilometers: %.3f km\n", meters / 1000);
    printf("In centimeters: %.3f cm\n", meters * 100);
    printf("In millimeters: %.3f mm\n", meters * 1000);
}

void weightConverter() {
    double kilograms;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    printf("In grams: %.3f g\n", kilograms * 1000);
    printf("In pounds: %.3f lb\n", kilograms * 2.20462);
    printf("In ounces: %.3f oz\n", kilograms * 35.274);
}

void temperatureConverter() {
    double celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    printf("In Fahrenheit: %.3f °F\n", (celsius * 9/5) + 32);
    printf("In Kelvin: %.3f K\n", celsius + 273.15);
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                lengthConverter();
                break;
            case 2:
                weightConverter();
                break;
            case 3:
                temperatureConverter();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}