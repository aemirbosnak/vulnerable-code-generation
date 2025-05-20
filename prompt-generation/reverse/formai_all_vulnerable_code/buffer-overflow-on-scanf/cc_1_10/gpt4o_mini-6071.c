//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>

void displayMenu() {
    printf("\n===Unit Converter===\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Volume\n");
    printf("4. Temperature\n");
    printf("5. Exit\n");
    printf("Please choose an option (1-5): ");
}

void lengthConverter() {
    double meters, feet, yards;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    
    feet = meters * 3.28084;
    yards = meters * 1.09361;
    
    printf("%.2lf meters is equal to:\n", meters);
    printf("%.2lf feet\n", feet);
    printf("%.2lf yards\n", yards);
}

void weightConverter() {
    double kilograms, pounds, grams;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    
    pounds = kilograms * 2.20462;
    grams = kilograms * 1000;
    
    printf("%.2lf kilograms is equal to:\n", kilograms);
    printf("%.2lf pounds\n", pounds);
    printf("%.2lf grams\n", grams);
}

void volumeConverter() {
    double liters, gallons, cups;
    printf("Enter volume in liters: ");
    scanf("%lf", &liters);
    
    gallons = liters * 0.264172;
    cups = liters * 4.22675;
    
    printf("%.2lf liters is equal to:\n", liters);
    printf("%.2lf gallons\n", gallons);
    printf("%.2lf cups\n", cups);
}

void temperatureConverter() {
    double celsius, fahrenheit, kelvin;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    
    fahrenheit = (celsius * 9/5) + 32;
    kelvin = celsius + 273.15;
    
    printf("%.2lf Celsius is equal to:\n", celsius);
    printf("%.2lf Fahrenheit\n", fahrenheit);
    printf("%.2lf Kelvin\n", kelvin);
}

int main() {
    int choice;
    
    do {
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
                volumeConverter();
                break;
            case 4:
                temperatureConverter();
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}