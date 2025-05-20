//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>

void displayMenu() {
    printf("\nUnit Converter\n");
    printf("1. Temperature Converter\n");
    printf("2. Length Converter\n");
    printf("3. Weight Converter\n");
    printf("4. Area Converter\n");
    printf("5. Volume Converter\n");
    printf("6. Exit\n");
    printf("Choose an option (1-6): ");
}

void temperatureConverter() {
    float celsius, fahrenheit, kelvin;
    printf("\nTemperature Converter:\n");
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9/5) + 32;
    kelvin = celsius + 273.15;
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
    printf("Temperature in Kelvin: %.2f\n", kelvin);
}

void lengthConverter() {
    float meters, feet, inches;
    printf("\nLength Converter:\n");
    printf("Enter length in Meters: ");
    scanf("%f", &meters);
    feet = meters * 3.28084;
    inches = meters * 39.3701;
    printf("Length in Feet: %.2f\n", feet);
    printf("Length in Inches: %.2f\n", inches);
}

void weightConverter() {
    float kilograms, pounds, ounces;
    printf("\nWeight Converter:\n");
    printf("Enter weight in Kilograms: ");
    scanf("%f", &kilograms);
    pounds = kilograms * 2.20462;
    ounces = kilograms * 35.274;
    printf("Weight in Pounds: %.2f\n", pounds);
    printf("Weight in Ounces: %.2f\n", ounces);
}

void areaConverter() {
    float squareMeters, acres, hectares;
    printf("\nArea Converter:\n");
    printf("Enter area in Square Meters: ");
    scanf("%f", &squareMeters);
    acres = squareMeters * 0.000247105;
    hectares = squareMeters * 0.0001;
    printf("Area in Acres: %.5f\n", acres);
    printf("Area in Hectares: %.5f\n", hectares);
}

void volumeConverter() {
    float liters, gallons, cubicMeters;
    printf("\nVolume Converter:\n");
    printf("Enter volume in Liters: ");
    scanf("%f", &liters);
    gallons = liters * 0.264172;
    cubicMeters = liters * 0.001;
    printf("Volume in Gallons: %.3f\n", gallons);
    printf("Volume in Cubic Meters: %.3f\n", cubicMeters);
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                temperatureConverter();
                break;
            case 2:
                lengthConverter();
                break;
            case 3:
                weightConverter();
                break;
            case 4:
                areaConverter();
                break;
            case 5:
                volumeConverter();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}