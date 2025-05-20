//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("Welcome to the Unit Converter!\n");
    printf("Please select a conversion type:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Area\n");
    printf("5. Volume\n");
    printf("6. Exit\n");
}

void lengthConverter() {
    double meters;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    printf("%.2lf meters is:\n", meters);
    printf("%.2lf kilometers\n", meters / 1000);
    printf("%.2lf centimeters\n", meters * 100);
    printf("%.2lf millimeters\n", meters * 1000);
}

void weightConverter() {
    double kilograms;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    printf("%.2lf kilograms is:\n", kilograms);
    printf("%.2lf grams\n", kilograms * 1000);
    printf("%.2lf pounds\n", kilograms * 2.20462);
    printf("%.2lf ounces\n", kilograms * 35.274);
}

void temperatureConverter() {
    double celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    printf("%.2lf Celsius is:\n", celsius);
    printf("%.2lf Fahrenheit\n", (celsius * 9/5) + 32);
    printf("%.2lf Kelvin\n", celsius + 273.15);
}

void areaConverter() {
    double squareMeters;
    printf("Enter area in square meters: ");
    scanf("%lf", &squareMeters);
    printf("%.2lf square meters is:\n", squareMeters);
    printf("%.2lf square kilometers\n", squareMeters / 1e6);
    printf("%.2lf acres\n", squareMeters * 0.000247105);
    printf("%.2lf hectares\n", squareMeters / 10000);
}

void volumeConverter() {
    double cubicMeters;
    printf("Enter volume in cubic meters: ");
    scanf("%lf", &cubicMeters);
    printf("%.2lf cubic meters is:\n", cubicMeters);
    printf("%.2lf liters\n", cubicMeters * 1000);
    printf("%.2lf gallons\n", cubicMeters * 264.172);
}

int main() {
    while (1) {
        displayMenu();

        int choice;
        printf("Enter your choice: ");
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
                areaConverter();
                break;
            case 5:
                volumeConverter();
                break;
            case 6:
                printf("Thank you for using the Unit Converter. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}