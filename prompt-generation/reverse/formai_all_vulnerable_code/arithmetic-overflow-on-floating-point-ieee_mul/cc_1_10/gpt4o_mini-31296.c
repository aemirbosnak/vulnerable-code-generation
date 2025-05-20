//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n=== Unit Converter ===\n");
    printf("1. Length (Meters to Feet)\n");
    printf("2. Weight (Kilograms to Pounds)\n");
    printf("3. Temperature (Celsius to Fahrenheit)\n");
    printf("4. Exit\n");
    printf("======================\n");
    printf("Enter your choice: ");
}

float metersToFeet(float meters) {
    return meters * 3.28084;
}

float kilogramsToPounds(float kg) {
    return kg * 2.20462;
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

void convertLength() {
    float meters;
    printf("Enter length in meters: ");
    scanf("%f", &meters);
    printf("%.2f meters is equal to %.2f feet.\n", meters, metersToFeet(meters));
}

void convertWeight() {
    float kg;
    printf("Enter weight in kilograms: ");
    scanf("%f", &kg);
    printf("%.2f kilograms is equal to %.2f pounds.\n", kg, kilogramsToPounds(kg));
}

void convertTemperature() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, celsiusToFahrenheit(celsius));
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                convertLength();
                break;
            case 2:
                convertWeight();
                break;
            case 3:
                convertTemperature();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}