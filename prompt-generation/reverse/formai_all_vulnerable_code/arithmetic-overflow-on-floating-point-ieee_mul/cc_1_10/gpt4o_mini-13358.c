//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("\n========================\n");
    printf("Welcome to the Unit Converter\n");
    printf("========================\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("0. Exit\n");
    printf("========================\n");
    printf("Please choose an option: ");
}

void length_conversion() {
    double meters, kilometers, miles, feet;
    int choice;
    printf("\nLength Conversion:\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Kilometers to Meters\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Feet to Meters\n");
    printf("Choose a conversion: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter meters: ");
            scanf("%lf", &meters);
            printf("%.2f meters = %.2f kilometers\n", meters, meters / 1000);
            break;
        case 2:
            printf("Enter kilometers: ");
            scanf("%lf", &kilometers);
            printf("%.2f kilometers = %.2f meters\n", kilometers, kilometers * 1000);
            break;
        case 3:
            printf("Enter miles: ");
            scanf("%lf", &miles);
            printf("%.2f miles = %.2f kilometers\n", miles, miles * 1.60934);
            break;
        case 4:
            printf("Enter feet: ");
            scanf("%lf", &feet);
            printf("%.2f feet = %.2f meters\n", feet, feet * 0.3048);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void weight_conversion() {
    double grams, kilograms, pounds, ounces;
    int choice;
    printf("\nWeight Conversion:\n");
    printf("1. Grams to Kilograms\n");
    printf("2. Kilograms to Grams\n");
    printf("3. Pounds to Kilograms\n");
    printf("4. Ounces to Grams\n");
    printf("Choose a conversion: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter grams: ");
            scanf("%lf", &grams);
            printf("%.2f grams = %.2f kilograms\n", grams, grams / 1000);
            break;
        case 2:
            printf("Enter kilograms: ");
            scanf("%lf", &kilograms);
            printf("%.2f kilograms = %.2f grams\n", kilograms, kilograms * 1000);
            break;
        case 3:
            printf("Enter pounds: ");
            scanf("%lf", &pounds);
            printf("%.2f pounds = %.2f kilograms\n", pounds, pounds * 0.453592);
            break;
        case 4:
            printf("Enter ounces: ");
            scanf("%lf", &ounces);
            printf("%.2f ounces = %.2f grams\n", ounces, ounces * 28.3495);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void temperature_conversion() {
    double celsius, fahrenheit, kelvin;
    int choice;
    printf("\nTemperature Conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("Choose a conversion: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter Celsius: ");
            scanf("%lf", &celsius);
            printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, (celsius * 9/5) + 32);
            break;
        case 2:
            printf("Enter Fahrenheit: ");
            scanf("%lf", &fahrenheit);
            printf("%.2f Fahrenheit = %.2f Celsius\n", fahrenheit, (fahrenheit - 32) * 5/9);
            break;
        case 3:
            printf("Enter Celsius: ");
            scanf("%lf", &celsius);
            printf("%.2f Celsius = %.2f Kelvin\n", celsius, celsius + 273.15);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    int option;
    do {
        display_menu();
        scanf("%d", &option);
        
        if(option == 1) {
            length_conversion();
        } else if(option == 2) {
            weight_conversion();
        } else if(option == 3) {
            temperature_conversion();
        } else if(option < 0 || option > 3) {
            if(option != 0) {
                printf("Invalid option! Please try again.\n");
            }
        }
    } while(option != 0);

    printf("Thank you for using the Unit Converter!\n");
    return 0;
}