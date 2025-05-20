//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>

void displayMenu() {
    printf("\nUnit Converter Menu:\n");
    printf("1. Length Conversion\n");
    printf("2. Area Conversion\n");
    printf("3. Volume Conversion\n");
    printf("4. Weight Conversion\n");
    printf("5. Temperature Conversion\n");
    printf("6. Exit\n");
    printf("Choose an option (1-6): ");
}

void lengthConversion() {
    float meters, feet, inches;
    printf("\nLength Conversion:\n");
    printf("Enter length in meters: ");
    scanf("%f", &meters);

    feet = meters * 3.28084;
    inches = meters * 39.3701;

    printf("%.2f meters is equal to %.2f feet and %.2f inches.\n", meters, feet, inches);
}

void areaConversion() {
    float squareMeters, acres, hectares;
    printf("\nArea Conversion:\n");
    printf("Enter area in square meters: ");
    scanf("%f", &squareMeters);

    acres = squareMeters * 0.000247105;
    hectares = squareMeters * 0.0001;

    printf("%.2f square meters is equal to %.2f acres and %.2f hectares.\n", squareMeters, acres, hectares);
}

void volumeConversion() {
    float liters, gallons, cubicMeters;
    printf("\nVolume Conversion:\n");
    printf("Enter volume in liters: ");
    scanf("%f", &liters);

    gallons = liters * 0.264172;
    cubicMeters = liters * 0.001;

    printf("%.2f liters is equal to %.2f gallons and %.2f cubic meters.\n", liters, gallons, cubicMeters);
}

void weightConversion() {
    float kilograms, pounds, ounces;
    printf("\nWeight Conversion:\n");
    printf("Enter weight in kilograms: ");
    scanf("%f", &kilograms);

    pounds = kilograms * 2.20462;
    ounces = kilograms * 35.274;

    printf("%.2f kilograms is equal to %.2f pounds and %.2f ounces.\n", kilograms, pounds, ounces);
}

void temperatureConversion() {
    float celsius, fahrenheit;
    printf("\nTemperature Conversion:\n");
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9/5) + 32;

    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                lengthConversion();
                break;
            case 2:
                areaConversion();
                break;
            case 3:
                volumeConversion();
                break;
            case 4:
                weightConversion();
                break;
            case 5:
                temperatureConversion();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}