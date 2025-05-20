//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: genius
#include <stdio.h>

void displayMenu() {
    printf("\n------------ Unit Converter ------------\n");
    printf("1. Length (meters to kilometers)\n");
    printf("2. Weight (grams to kilograms)\n");
    printf("3. Temperature (Celsius to Fahrenheit)\n");
    printf("4. Volume (liters to milliliters)\n");
    printf("5. Area (square meters to square centimeters)\n");
    printf("6. Exit\n");
    printf("----------------------------------------\n");
    printf("Choose an option: ");
}

float metersToKilometers(float meters) {
    return meters / 1000;
}

float gramsToKilograms(float grams) {
    return grams / 1000;
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float litersToMilliliters(float liters) {
    return liters * 1000;
}

float squareMetersToSquareCentimeters(float squareMeters) {
    return squareMeters * 10000;
}

int main() {
    int choice;
    float input, result;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter length in meters: ");
                scanf("%f", &input);
                result = metersToKilometers(input);
                printf("%.2f meters is equal to %.2f kilometers\n", input, result);
                break;
            case 2:
                printf("Enter weight in grams: ");
                scanf("%f", &input);
                result = gramsToKilograms(input);
                printf("%.2f grams is equal to %.2f kilograms\n", input, result);
                break;
            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &input);
                result = celsiusToFahrenheit(input);
                printf("%.2f Celsius is equal to %.2f Fahrenheit\n", input, result);
                break;
            case 4:
                printf("Enter volume in liters: ");
                scanf("%f", &input);
                result = litersToMilliliters(input);
                printf("%.2f liters is equal to %.2f milliliters\n", input, result);
                break;
            case 5:
                printf("Enter area in square meters: ");
                scanf("%f", &input);
                result = squareMetersToSquareCentimeters(input);
                printf("%.2f square meters is equal to %.2f square centimeters\n", input, result);
                break;
            case 6:
                printf("Thank you for using the Unit Converter! Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please choose a valid option from the menu.\n");
        }
    } while (choice != 6);

    return 0;
}