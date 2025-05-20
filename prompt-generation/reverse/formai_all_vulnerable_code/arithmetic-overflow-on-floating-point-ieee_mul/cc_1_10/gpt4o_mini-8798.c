//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("\n--- Welcome to the Unit Converter! ---\n");
    printf("Please select the conversion you wish to perform:\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Area Conversion\n");
    printf("5. Volume Conversion\n");
    printf("6. Exit\n");
}

void length_conversion() {
    double meters, feet;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    feet = meters * 3.28084; // 1 meter = 3.28084 feet
    printf("%.2lf meters is equal to %.2lf feet\n", meters, feet);
}

void weight_conversion() {
    double kg, pounds;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kg);
    pounds = kg * 2.20462; // 1 kg = 2.20462 pounds
    printf("%.2lf kg is equal to %.2lf pounds\n", kg, pounds);
}

void temperature_conversion() {
    double celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9/5) + 32; // Convert to Fahrenheit
    printf("%.2lf Celsius is equal to %.2lf Fahrenheit\n", celsius, fahrenheit);
}

void area_conversion() {
    double square_meters, acres;
    printf("Enter area in square meters: ");
    scanf("%lf", &square_meters);
    acres = square_meters * 0.000247105; // 1 square meter = 0.000247105 acres
    printf("%.2lf square meters is equal to %.2lf acres\n", square_meters, acres);
}

void volume_conversion() {
    double liters, gallons;
    printf("Enter volume in liters: ");
    scanf("%lf", &liters);
    gallons = liters * 0.264172; // 1 liter = 0.264172 gallons
    printf("%.2lf liters is equal to %.2lf gallons\n", liters, gallons);
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                length_conversion();
                break;
            case 2:
                weight_conversion();
                break;
            case 3:
                temperature_conversion();
                break;
            case 4:
                area_conversion();
                break;
            case 5:
                volume_conversion();
                break;
            case 6:
                printf("Thank you for using the Unit Converter! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}