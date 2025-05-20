//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: genius
#include <stdio.h>

void convertLength() {
    float meters, kilometers, miles;
    printf("\n--- Length Converter ---\n");
    printf("Enter length in meters: ");
    scanf("%f", &meters);
    kilometers = meters / 1000;
    miles = meters / 1609.34;
    printf("%.2f meters = %.2f kilometers\n", meters, kilometers);
    printf("%.2f meters = %.2f miles\n", meters, miles);
}

void convertMass() {
    float grams, kilograms, pounds;
    printf("\n--- Mass Converter ---\n");
    printf("Enter mass in grams: ");
    scanf("%f", &grams);
    kilograms = grams / 1000;
    pounds = grams * 0.00220462;
    printf("%.2f grams = %.2f kilograms\n", grams, kilograms);
    printf("%.2f grams = %.2f pounds\n", grams, pounds);
}

void convertTemperature() {
    float celsius, fahrenheit, kelvin;
    printf("\n--- Temperature Converter ---\n");
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9 / 5) + 32;
    kelvin = celsius + 273.15;
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    printf("%.2f Celsius = %.2f Kelvin\n", celsius, kelvin);
}

void showMenu() {
    printf("\n--- Unit Conversion Menu ---\n");
    printf("1. Convert Length\n");
    printf("2. Convert Mass\n");
    printf("3. Convert Temperature\n");
    printf("4. Exit\n");
    printf("Select an option (1-4): ");
}

int main() {
    int choice;

    while (1) {
        showMenu();
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
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}