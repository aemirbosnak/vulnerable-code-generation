//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>

void displayMenu() {
    printf("\nWelcome to the Grateful Unit Converter!\n");
    printf("Please choose a conversion option:\n");
    printf("1. Length (meters to feet)\n");
    printf("2. Weight (kilograms to pounds)\n");
    printf("3. Temperature (Celsius to Fahrenheit)\n");
    printf("4. Volume (liters to gallons)\n");
    printf("5. Exit\n");
}

float metersToFeet(float meters) {
    return meters * 3.28084; // Meters to feet conversion
}

float kilogramsToPounds(float kg) {
    return kg * 2.20462; // Kilograms to pounds conversion
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0/5.0) + 32; // Celsius to Fahrenheit conversion
}

float litersToGallons(float liters) {
    return liters * 0.264172; // Liters to gallons conversion
}

int main() {
    int choice;
    float value, convertedValue;

    do {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter length in meters: ");
            scanf("%f", &value);
            convertedValue = metersToFeet(value);
            printf("Converted Length: %.2f feet\n", convertedValue);
        } else if (choice == 2) {
            printf("Enter weight in kilograms: ");
            scanf("%f", &value);
            convertedValue = kilogramsToPounds(value);
            printf("Converted Weight: %.2f pounds\n", convertedValue);
        } else if (choice == 3) {
            printf("Enter temperature in Celsius: ");
            scanf("%f", &value);
            convertedValue = celsiusToFahrenheit(value);
            printf("Converted Temperature: %.2f Fahrenheit\n", convertedValue);
        } else if (choice == 4) {
            printf("Enter volume in liters: ");
            scanf("%f", &value);
            convertedValue = litersToGallons(value);
            printf("Converted Volume: %.2f gallons\n", convertedValue);
        } else if (choice == 5) {
            printf("Thank you for using the Grateful Unit Converter! Goodbye!\n");
        } else {
            printf("Invalid choice! Please choose a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}