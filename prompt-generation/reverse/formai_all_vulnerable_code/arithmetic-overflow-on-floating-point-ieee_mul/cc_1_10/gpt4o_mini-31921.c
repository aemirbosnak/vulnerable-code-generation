//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("*****************************\n");
    printf("      Unit Converter\n");
    printf("*****************************\n");
    printf("1. Length\n");
    printf("2. Mass\n");
    printf("3. Temperature\n");
    printf("4. Volume\n");
    printf("5. Exit\n");
    printf("Select an option (1-5): ");
}

void convertLength() {
    double meters, feet;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    feet = meters * 3.28084; // 1 meter = 3.28084 feet
    printf("%.2f meters is equal to %.2f feet\n", meters, feet);
}

void convertMass() {
    double kg, pounds;
    printf("Enter mass in kilograms: ");
    scanf("%lf", &kg);
    pounds = kg * 2.20462; // 1 kilogram = 2.20462 pounds
    printf("%.2f kilograms is equal to %.2f pounds\n", kg, pounds);
}

void convertTemperature() {
    double celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9.0 / 5.0) + 32; // C to F conversion
    printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);
}

void convertVolume() {
    double liters, gallons;
    printf("Enter volume in liters: ");
    scanf("%lf", &liters);
    gallons = liters * 0.264172; // 1 liter = 0.264172 gallons
    printf("%.2f liters is equal to %.2f gallons\n", liters, gallons);
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
                convertMass();
                break;
            case 3:
                convertTemperature();
                break;
            case 4:
                convertVolume();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        printf("\n");
    } while (choice != 5);

    return 0;
}