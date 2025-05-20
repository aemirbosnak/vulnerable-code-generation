//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("Welcome to the Universal Unit Converter!\n");
    printf("Please select the conversion type:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void length_conversion() {
    double meters;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    
    printf("Length Conversion Results:\n");
    printf("Feet: %.2f\n", meters * 3.28084);
    printf("Miles: %.2f\n", meters * 0.000621371);
    printf("Yards: %.2f\n", meters * 1.09361);
}

void weight_conversion() {
    double kilograms;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    
    printf("Weight Conversion Results:\n");
    printf("Pounds: %.2f\n", kilograms * 2.20462);
    printf("Ounces: %.2f\n", kilograms * 35.274);
    printf("Stones: %.2f\n", kilograms * 0.157473);
}

void temperature_conversion() {
    double celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    
    printf("Temperature Conversion Results:\n");
    printf("Fahrenheit: %.2f\n", (celsius * 9/5) + 32);
    printf("Kelvin: %.2f\n", celsius + 273.15);
}

int main() {
    int choice;
    do {
        display_menu();
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
                printf("Exiting the converter. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}