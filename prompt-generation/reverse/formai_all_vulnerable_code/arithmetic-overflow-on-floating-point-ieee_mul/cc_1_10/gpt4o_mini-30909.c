//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n--- Unit Converter ---\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

void lengthConverter() {
    double meters, feet, inches;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    
    feet = meters * 3.28084;
    inches = feet * 12;

    printf("Length in Feet: %.2f ft\n", feet);
    printf("Length in Inches: %.2f in\n", inches);
}

void weightConverter() {
    double kilograms, pounds, ounces;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    
    pounds = kilograms * 2.20462;
    ounces = pounds * 16;

    printf("Weight in Pounds: %.2f lbs\n", pounds);
    printf("Weight in Ounces: %.2f oz\n", ounces);
}

void temperatureConverter() {
    double celsius, fahrenheit, kelvin;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    
    fahrenheit = (celsius * 9/5) + 32;
    kelvin = celsius + 273.15;

    printf("Temperature in Fahrenheit: %.2f °F\n", fahrenheit);
    printf("Temperature in Kelvin: %.2f K\n", kelvin);
}

int main() {
    int choice;

    while(1) {
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
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}