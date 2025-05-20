//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: immersive
#include <stdio.h>

// Function prototypes
void showMenu();
void metersToFeet();
void feetToMeters();
void celsiusToFahrenheit();
void fahrenheitToCelsius();
void kilometersToMiles();
void milesToKilometers();

int main() {
    int choice;
    
    printf("Welcome to the Ultimate Unit Converter!\n");
    printf("========================================\n");

    do {
        showMenu();
        printf("Enter your choice (1-6, or 0 to exit): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                metersToFeet();
                break;
            case 2:
                feetToMeters();
                break;
            case 3:
                celsiusToFahrenheit();
                break;
            case 4:
                fahrenheitToCelsius();
                break;
            case 5:
                kilometersToMiles();
                break;
            case 6:
                milesToKilometers();
                break;
            case 0:
                printf("Thank you for using the Ultimate Unit Converter!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 0);

    return 0;
}

void showMenu() {
    printf("\nUnit Conversion Options:\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("3. Celsius to Fahrenheit\n");
    printf("4. Fahrenheit to Celsius\n");
    printf("5. Kilometers to Miles\n");
    printf("6. Miles to Kilometers\n");
    printf("0. Exit\n");
}

void metersToFeet() {
    float meters;
    printf("Enter length in meters: ");
    scanf("%f", &meters);
    float feet = meters * 3.28084;
    printf("%.2f meters is equivalent to %.2f feet\n", meters, feet);
}

void feetToMeters() {
    float feet;
    printf("Enter length in feet: ");
    scanf("%f", &feet);
    float meters = feet / 3.28084;
    printf("%.2f feet is equivalent to %.2f meters\n", feet, meters);
}

void celsiusToFahrenheit() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    float fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f Celsius is equivalent to %.2f Fahrenheit\n", celsius, fahrenheit);
}

void fahrenheitToCelsius() {
    float fahrenheit;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    float celsius = (fahrenheit - 32) * 5/9;
    printf("%.2f Fahrenheit is equivalent to %.2f Celsius\n", fahrenheit, celsius);
}

void kilometersToMiles() {
    float kilometers;
    printf("Enter distance in kilometers: ");
    scanf("%f", &kilometers);
    float miles = kilometers * 0.621371;
    printf("%.2f kilometers is equivalent to %.2f miles\n", kilometers, miles);
}

void milesToKilometers() {
    float miles;
    printf("Enter distance in miles: ");
    scanf("%f", &miles);
    float kilometers = miles / 0.621371;
    printf("%.2f miles is equivalent to %.2f kilometers\n", miles, kilometers);
}