//FormAI DATASET v1.0 Category: Unit converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void menu();
void convert(int, double);
void celsiusToFahrenheit(double);
void fahrenheitToCelsius(double);
void metersToFeet(double);
void feetToMeters(double);

int main() {
    int choice;
    double input;
    
    printf("---Unit Converter---\n");
    do {
        menu(); // Display menu
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // Celsius to Fahrenheit
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &input);
                convert(choice, input);
                break;
            case 2: // Fahrenheit to Celsius
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &input);
                convert(choice, input);
                break;
            case 3: // Meters to Feet
                printf("Enter length in meters: ");
                scanf("%lf", &input);
                convert(choice, input);
                break;
            case 4: // Feet to Meters
                printf("Enter length in feet: ");
                scanf("%lf", &input);
                convert(choice, input);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5); // Repeat until user chooses to exit
    
    return 0;
}

void menu() {
    printf("\n---Menu---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    printf("5. Quit\n");
}

void convert(int choice, double input) {
    switch(choice) {
        case 1: // Celsius to Fahrenheit
            celsiusToFahrenheit(input);
            break;
        case 2: // Fahrenheit to Celsius
            fahrenheitToCelsius(input);
            break;
        case 3: // Meters to Feet
            metersToFeet(input);
            break;
        case 4: // Feet to Meters
            feetToMeters(input);
            break;
    }
}

void celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 9/5) + 32;
    printf("%.2lf Celsius is %.2lf Fahrenheit\n", celsius, fahrenheit);
}

void fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5/9;
    printf("%.2lf Fahrenheit is %.2lf Celsius\n", fahrenheit, celsius);
}

void metersToFeet(double meters) {
    double feet = meters * 3.28084;
    printf("%.2lf meters is %.2lf feet\n", meters, feet);
}

void feetToMeters(double feet) {
    double meters = feet / 3.28084;
    printf("%.2lf feet is %.2lf meters\n", feet, meters);
}