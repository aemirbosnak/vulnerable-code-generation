//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n====================\n");
    printf("      Unit Converter      \n");
    printf("====================\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Area Conversion\n");
    printf("5. Volume Conversion\n");
    printf("6. Exit\n");
    printf("====================\n");
    printf("Select an option (1-6): ");
}

void lengthConversion() {
    double meters, kilometers, miles, feet;
    printf("\nEnter length in meters: ");
    scanf("%lf", &meters);

    kilometers = meters / 1000;
    miles = meters * 0.000621371192;
    feet = meters * 3.28084;

    printf("%.2f meters is:\n", meters);
    printf("Kilometers: %.2f km\n", kilometers);
    printf("Miles: %.2f mi\n", miles);
    printf("Feet: %.2f ft\n", feet);
}

void weightConversion() {
    double grams, kilograms, pounds, ounces;
    printf("\nEnter weight in grams: ");
    scanf("%lf", &grams);

    kilograms = grams / 1000;
    pounds = grams * 0.00220462;
    ounces = grams * 0.035274;

    printf("%.2f grams is:\n", grams);
    printf("Kilograms: %.2f kg\n", kilograms);
    printf("Pounds: %.2f lb\n", pounds);
    printf("Ounces: %.2f oz\n", ounces);
}

void temperatureConversion() {
    double celsius, fahrenheit, kelvin;
    printf("\nEnter temperature in Celsius: ");
    scanf("%lf", &celsius);

    fahrenheit = (celsius * 9/5) + 32;
    kelvin = celsius + 273.15;

    printf("%.2f °C is:\n", celsius);
    printf("Fahrenheit: %.2f °F\n", fahrenheit);
    printf("Kelvin: %.2f K\n", kelvin);
}

void areaConversion() {
    double squareMeters, squareKilometers, acres, hectares;
    printf("\nEnter area in square meters: ");
    scanf("%lf", &squareMeters);

    squareKilometers = squareMeters / 1e6;
    acres = squareMeters * 0.000247105;
    hectares = squareMeters / 10000;

    printf("%.2f square meters is:\n", squareMeters);
    printf("Square Kilometers: %.2f km²\n", squareKilometers);
    printf("Acres: %.2f acres\n", acres);
    printf("Hectares: %.2f ha\n", hectares);
}

void volumeConversion() {
    double liters, gallons, cubicMeters, cubicFeet;
    printf("\nEnter volume in liters: ");
    scanf("%lf", &liters);

    gallons = liters * 0.264172;
    cubicMeters = liters / 1000;
    cubicFeet = liters * 0.0353147;

    printf("%.2f liters is:\n", liters);
    printf("Gallons: %.2f gal\n", gallons);
    printf("Cubic Meters: %.2f m³\n", cubicMeters);
    printf("Cubic Feet: %.2f ft³\n", cubicFeet);
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
                weightConversion();
                break;
            case 3:
                temperatureConversion();
                break;
            case 4:
                areaConversion();
                break;
            case 5:
                volumeConversion();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a number between 1 and 6.\n");
        }
    }
    return 0;
}