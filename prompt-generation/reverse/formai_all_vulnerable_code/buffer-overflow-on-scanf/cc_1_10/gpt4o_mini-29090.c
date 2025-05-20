//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

void showMenu() {
    printf("\nUnit Converter Menu:\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("4. Exit\n");
    printf("Select an option (1-4): ");
}

void lengthConverter() {
    double meters, kilometers, miles, feet;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    printf("Meters: %.2lf\n", meters);
    kilometers = meters / 1000;
    miles = meters * 0.000621371;
    feet = meters * 3.28084;
    printf("Kilometers: %.2lf\n", kilometers);
    printf("Miles: %.2lf\n", miles);
    printf("Feet: %.2lf\n", feet);
}

void weightConverter() {
    double grams, kilograms, pounds, ounces;
    printf("Enter weight in grams: ");
    scanf("%lf", &grams);
    printf("Grams: %.2lf\n", grams);
    kilograms = grams / 1000;
    pounds = grams * 0.00220462;
    ounces = grams * 0.035274;
    printf("Kilograms: %.2lf\n", kilograms);
    printf("Pounds: %.2lf\n", pounds);
    printf("Ounces: %.2lf\n", ounces);
}

void temperatureConverter() {
    double celsius, fahrenheit, kelvin;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    printf("Celsius: %.2lf\n", celsius);
    fahrenheit = (celsius * 9/5) + 32;
    kelvin = celsius + 273.15;
    printf("Fahrenheit: %.2lf\n", fahrenheit);
    printf("Kelvin: %.2lf\n", kelvin);
}

int main() {
    int choice;
    
    while (1) {
        showMenu();
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
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}