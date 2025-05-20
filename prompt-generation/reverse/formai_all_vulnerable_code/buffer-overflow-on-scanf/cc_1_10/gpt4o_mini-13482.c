//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: creative
#include <stdio.h>

void displayMenu() {
    printf("\nWelcome to the Magical Unit Converter!\n");
    printf("Choose the conversion type below:\n");
    printf("1. Length (Meters to Feet & Inches)\n");
    printf("2. Weight (Kilograms to Pounds)\n");
    printf("3. Temperature (Celsius to Fahrenheit)\n");
    printf("4. Area (Square Meters to Acres)\n");
    printf("5. Volume (Liters to Gallons)\n");
    printf("6. Quit\n");
    printf("Please enter your choice (1-6): ");
}

float metersToFeet(float meters) {
    return meters * 3.28084; // 1 meter = 3.28084 feet
}

void metersToFeetAndInches(float meters) {
    float totalFeet = metersToFeet(meters);
    int feet = (int)totalFeet;
    float inches = (totalFeet - feet) * 12; // 1 foot = 12 inches
    printf("%.2f meters is approximately %d feet and %.2f inches.\n", meters, feet, inches);
}

float kilogramsToPounds(float kilograms) {
    return kilograms * 2.20462; // 1 kilogram = 2.20462 pounds
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0; // Conversion formula
}

float squareMetersToAcres(float squareMeters) {
    return squareMeters * 0.000247105; // 1 square meter = 0.000247105 acres
}

float litersToGallons(float liters) {
    return liters * 0.264172; // 1 liter = 0.264172 gallons
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
                metersToFeetAndInches(input);
                break;
            case 2:
                printf("Enter weight in kilograms: ");
                scanf("%f", &input);
                result = kilogramsToPounds(input);
                printf("%.2f kilograms is %.2f pounds.\n", input, result);
                break;
            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &input);
                result = celsiusToFahrenheit(input);
                printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", input, result);
                break;
            case 4:
                printf("Enter area in square meters: ");
                scanf("%f", &input);
                result = squareMetersToAcres(input);
                printf("%.2f square meters is %.2f acres.\n", input, result);
                break;
            case 5:
                printf("Enter volume in liters: ");
                scanf("%f", &input);
                result = litersToGallons(input);
                printf("%.2f liters is %.2f gallons.\n", input, result);
                break;
            case 6:
                printf("Exiting the Magical Unit Converter. Have a wonderful day!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}