//FormAI DATASET v1.0 Category: Unit converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printMenu();
void convertTemp();
void convertLength();
void convertWeight();
void convertVolume();

int main() {
    int choice;
    
    do {
        printMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: convertTemp(); break;
            case 2: convertLength(); break;
            case 3: convertWeight(); break;
            case 4: convertVolume(); break;
            case 5: printf("Goodbye!\n"); exit(0);
            default: printf("Invalid option. Please try again.\n");
        }
    } while(1);
    
    return 0;
}

// Function definitions
void printMenu() {
    printf("\n===== Genius Converter =====\n");
    printf("1. Convert temperature\n");
    printf("2. Convert length\n");
    printf("3. Convert weight\n");
    printf("4. Convert volume\n");
    printf("5. Exit\n");
    printf("============================\n");
    printf("Enter your choice: ");
}

void convertTemp() {
    double celsius, fahrenheit, kelvin;
    int choice;
    
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: 
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2lf Celsius = %.2lf Fahrenheit\n", celsius, fahrenheit);
            break;
        case 2:
            kelvin = celsius + 273.15;
            printf("%.2lf Celsius = %.2lf Kelvin\n", celsius, kelvin);
            break;
        default: printf("Invalid option. Please try again.\n");
    }
}

void convertLength() {
    double meters, feet, yards, miles;
    int choice;
    
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    
    printf("1. Meters to feet\n");
    printf("2. Meters to yards\n");
    printf("3. Meters to miles\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: 
            feet = meters * 3.28;
            printf("%.2lf meters = %.2lf feet\n", meters, feet);
            break;
        case 2:
            yards = meters * 1.09;
            printf("%.2lf meters = %.2lf yards\n", meters, yards);
            break;
        case 3:
            miles = meters / 1609.34;
            printf("%.2lf meters = %.2lf miles\n", meters, miles);
            break;
        default: printf("Invalid option. Please try again.\n");
    }
}

void convertWeight() {
    double kilograms, pounds, ounces;
    int choice;
    
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    
    printf("1. Kilograms to pounds\n");
    printf("2. Kilograms to ounces\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: 
            pounds = kilograms * 2.205;
            printf("%.2lf kilograms = %.2lf pounds\n", kilograms, pounds);
            break;
        case 2:
            ounces = kilograms * 35.274;
            printf("%.2lf kilograms = %.2lf ounces\n", kilograms, ounces);
            break;
        default: printf("Invalid option. Please try again.\n");
    }
}

void convertVolume() {
    double liters, gallons, quarts, pints;
    int choice;
    
    printf("Enter volume in liters: ");
    scanf("%lf", &liters);
    
    printf("1. Liters to gallons\n");
    printf("2. Liters to quarts\n");
    printf("3. Liters to pints\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: 
            gallons = liters * 0.2642;
            printf("%.2lf liters = %.2lf gallons\n", liters, gallons);
            break;
        case 2:
            quarts = liters * 1.057;
            printf("%.2lf liters = %.2lf quarts\n", liters, quarts);
            break;
        case 3:
            pints = liters * 2.1134;
            printf("%.2lf liters = %.2lf pints\n", liters, pints);
            break;
        default: printf("Invalid option. Please try again.\n");
    }
}