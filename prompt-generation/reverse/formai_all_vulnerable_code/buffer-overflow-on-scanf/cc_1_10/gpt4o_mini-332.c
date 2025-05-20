//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: light-weight
#include <stdio.h>

void displayMenu() {
    printf("\n--- Unit Converter ---\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Exit\n");
    printf("Select an option (1-4): ");
}

void lengthConverter() {
    float meters, feet, inches;
    printf("Enter length in meters: ");
    scanf("%f", &meters);
    feet = meters * 3.28084;
    inches = meters * 39.3701;
    printf("%.2f meters = %.2f feet\n", meters, feet);
    printf("%.2f meters = %.2f inches\n", meters, inches);
}

void weightConverter() {
    float kilograms, pounds, ounces;
    printf("Enter weight in kilograms: ");
    scanf("%f", &kilograms);
    pounds = kilograms * 2.20462;
    ounces = kilograms * 35.274;
    printf("%.2f kilograms = %.2f pounds\n", kilograms, pounds);
    printf("%.2f kilograms = %.2f ounces\n", kilograms, ounces);
}

void temperatureConverter() {
    float celsius, fahrenheit, kelvin;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9/5) + 32;
    kelvin = celsius + 273.15;
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    printf("%.2f Celsius = %.2f Kelvin\n", celsius, kelvin);
}

int main() {
    int choice;
    
    while (1) {
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
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}