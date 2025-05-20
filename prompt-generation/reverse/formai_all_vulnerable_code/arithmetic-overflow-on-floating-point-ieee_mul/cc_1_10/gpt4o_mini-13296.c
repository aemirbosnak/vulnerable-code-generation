//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\nWelcome to the Unit Converter!\n");
    printf("----------------------------------\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("0. Exit\n");
    printf("Please select an option: ");
}

void lengthConversion() {
    double meters, feet, inches;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    
    feet = meters * 3.28084;
    inches = feet * 12;

    printf("%.2f meters is equal to:\n", meters);
    printf("%.2f feet\n", feet);
    printf("%.2f inches\n", inches);
}

void weightConversion() {
    double kilograms, pounds, grams;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    
    pounds = kilograms * 2.20462;
    grams = kilograms * 1000;

    printf("%.2f kilograms is equal to:\n", kilograms);
    printf("%.2f pounds\n", pounds);
    printf("%.2f grams\n", grams);
}

void temperatureConversion() {
    double celsius, fahrenheit, kelvin;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    
    fahrenheit = celsius * 9/5 + 32;
    kelvin = celsius + 273.15;

    printf("%.2f Celsius is equal to:\n", celsius);
    printf("%.2f Fahrenheit\n", fahrenheit);
    printf("%.2f Kelvin\n", kelvin);
}

void handleInvalidInput() {
    printf("Invalid option. Please try again.\n");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                lengthConversion();
                break;
            case 2:
                weightConversion();
                break;
            case 3:
                temperatureConversion();
                break;
            case 0:
                printf("Thank you for using the Unit Converter. Goodbye!\n");
                exit(0);
            default:
                handleInvalidInput();
                break;
        }
    }

    return 0;
}