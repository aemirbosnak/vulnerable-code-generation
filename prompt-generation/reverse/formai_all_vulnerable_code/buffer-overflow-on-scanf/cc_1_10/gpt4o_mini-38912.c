//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>

// Function declarations
void printMenu();
void lengthConverter();
void weightConverter();
void temperatureConverter();
void areaConverter();
void volumeConverter();

// Length conversion functions
void metersToFeet();
void feetToMeters();
void kilometersToMiles();
void milesToKilometers();

// Weight conversion functions
void kilogramsToPounds();
void poundsToKilograms();
void gramsToOunces();
void ouncesToGrams();

// Temperature conversion functions
void celsiusToFahrenheit();
void fahrenheitToCelsius();
void kelvinToCelsius();
void celsiusToKelvin();

// Area conversion functions
void squareMetersToSquareFeet();
void squareFeetToSquareMeters();
void acresToHectares();
void hectaresToAcres();

// Volume conversion functions
void litersToGallons();
void gallonsToLiters();
void cubicMetersToCubicFeet();
void cubicFeetToCubicMeters();

int main() {
    int choice;
    do {
        printMenu();
        printf("Enter your choice (1-5 to choose, 0 to exit): ");
        scanf("%d", &choice);
        
        switch(choice) {
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
            case 0:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 0);
    
    return 0;
}

void printMenu() {
    printf("\n==== Unit Converter ====\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Area Conversion\n");
    printf("5. Volume Conversion\n");
    printf("0. Exit\n");
}

void lengthConverter() {
    int choice;
    printf("\n-- Length Conversion --\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("Choose a conversion: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: metersToFeet(); break;
        case 2: feetToMeters(); break;
        case 3: kilometersToMiles(); break;
        case 4: milesToKilometers(); break;
        default: printf("Invalid choice.\n");
    }
}

void metersToFeet() {
    float meters, feet;
    printf("Enter meters: ");
    scanf("%f", &meters);
    feet = meters * 3.28084;
    printf("%.2f meters = %.2f feet\n", meters, feet);
}

void feetToMeters() {
    float feet, meters;
    printf("Enter feet: ");
    scanf("%f", &feet);
    meters = feet / 3.28084;
    printf("%.2f feet = %.2f meters\n", feet, meters);
}

void kilometersToMiles() {
    float kilometers, miles;
    printf("Enter kilometers: ");
    scanf("%f", &kilometers);
    miles = kilometers * 0.621371;
    printf("%.2f kilometers = %.2f miles\n", kilometers, miles);
}

void milesToKilometers() {
    float miles, kilometers;
    printf("Enter miles: ");
    scanf("%f", &miles);
    kilometers = miles / 0.621371;
    printf("%.2f miles = %.2f kilometers\n", miles, kilometers);
}

void weightConverter() {
    int choice;
    printf("\n-- Weight Conversion --\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Grams to Ounces\n");
    printf("4. Ounces to Grams\n");
    printf("Choose a conversion: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: kilogramsToPounds(); break;
        case 2: poundsToKilograms(); break;
        case 3: gramsToOunces(); break;
        case 4: ouncesToGrams(); break;
        default: printf("Invalid choice.\n");
    }
}

void kilogramsToPounds() {
    float kilograms, pounds;
    printf("Enter kilograms: ");
    scanf("%f", &kilograms);
    pounds = kilograms * 2.20462;
    printf("%.2f kilograms = %.2f pounds\n", kilograms, pounds);
}

void poundsToKilograms() {
    float pounds, kilograms;
    printf("Enter pounds: ");
    scanf("%f", &pounds);
    kilograms = pounds / 2.20462;
    printf("%.2f pounds = %.2f kilograms\n", pounds, kilograms);
}

void gramsToOunces() {
    float grams, ounces;
    printf("Enter grams: ");
    scanf("%f", &grams);
    ounces = grams * 0.035274;
    printf("%.2f grams = %.2f ounces\n", grams, ounces);
}

void ouncesToGrams() {
    float ounces, grams;
    printf("Enter ounces: ");
    scanf("%f", &ounces);
    grams = ounces / 0.035274;
    printf("%.2f ounces = %.2f grams\n", ounces, grams);
}

void temperatureConverter() {
    int choice;
    printf("\n-- Temperature Conversion --\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    printf("Choose a conversion: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: celsiusToFahrenheit(); break;
        case 2: fahrenheitToCelsius(); break;
        case 3: kelvinToCelsius(); break;
        case 4: celsiusToKelvin(); break;
        default: printf("Invalid choice.\n");
    }
}

void celsiusToFahrenheit() {
    float celsius, fahrenheit;
    printf("Enter Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
}

void fahrenheitToCelsius() {
    float fahrenheit, celsius;
    printf("Enter Fahrenheit: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * 5/9;
    printf("%.2f Fahrenheit = %.2f Celsius\n", fahrenheit, celsius);
}

void kelvinToCelsius() {
    float kelvin, celsius;
    printf("Enter Kelvin: ");
    scanf("%f", &kelvin);
    celsius = kelvin - 273.15;
    printf("%.2f Kelvin = %.2f Celsius\n", kelvin, celsius);
}

void celsiusToKelvin() {
    float celsius, kelvin;
    printf("Enter Celsius: ");
    scanf("%f", &celsius);
    kelvin = celsius + 273.15;
    printf("%.2f Celsius = %.2f Kelvin\n", celsius, kelvin);
}

void areaConverter() {
    int choice;
    printf("\n-- Area Conversion --\n");
    printf("1. Square Meters to Square Feet\n");
    printf("2. Square Feet to Square Meters\n");
    printf("3. Acres to Hectares\n");
    printf("4. Hectares to Acres\n");
    printf("Choose a conversion: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: squareMetersToSquareFeet(); break;
        case 2: squareFeetToSquareMeters(); break;
        case 3: acresToHectares(); break;
        case 4: hectaresToAcres(); break;
        default: printf("Invalid choice.\n");
    }
}

void squareMetersToSquareFeet() {
    float squareMeters, squareFeet;
    printf("Enter square meters: ");
    scanf("%f", &squareMeters);
    squareFeet = squareMeters * 10.7639;
    printf("%.2f square meters = %.2f square feet\n", squareMeters, squareFeet);
}

void squareFeetToSquareMeters() {
    float squareFeet, squareMeters;
    printf("Enter square feet: ");
    scanf("%f", &squareFeet);
    squareMeters = squareFeet / 10.7639;
    printf("%.2f square feet = %.2f square meters\n", squareFeet, squareMeters);
}

void acresToHectares() {
    float acres, hectares;
    printf("Enter acres: ");
    scanf("%f", &acres);
    hectares = acres * 0.404686;
    printf("%.2f acres = %.2f hectares\n", acres, hectares);
}

void hectaresToAcres() {
    float hectares, acres;
    printf("Enter hectares: ");
    scanf("%f", &hectares);
    acres = hectares / 0.404686;
    printf("%.2f hectares = %.2f acres\n", hectares, acres);
}

void volumeConverter() {
    int choice;
    printf("\n-- Volume Conversion --\n");
    printf("1. Liters to Gallons\n");
    printf("2. Gallons to Liters\n");
    printf("3. Cubic Meters to Cubic Feet\n");
    printf("4. Cubic Feet to Cubic Meters\n");
    printf("Choose a conversion: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: litersToGallons(); break;
        case 2: gallonsToLiters(); break;
        case 3: cubicMetersToCubicFeet(); break;
        case 4: cubicFeetToCubicMeters(); break;
        default: printf("Invalid choice.\n");
    }
}

void litersToGallons() {
    float liters, gallons;
    printf("Enter liters: ");
    scanf("%f", &liters);
    gallons = liters * 0.264172;
    printf("%.2f liters = %.2f gallons\n", liters, gallons);
}

void gallonsToLiters() {
    float gallons, liters;
    printf("Enter gallons: ");
    scanf("%f", &gallons);
    liters = gallons / 0.264172;
    printf("%.2f gallons = %.2f liters\n", gallons, liters);
}

void cubicMetersToCubicFeet() {
    float cubicMeters, cubicFeet;
    printf("Enter cubic meters: ");
    scanf("%f", &cubicMeters);
    cubicFeet = cubicMeters * 35.3147;
    printf("%.2f cubic meters = %.2f cubic feet\n", cubicMeters, cubicFeet);
}

void cubicFeetToCubicMeters() {
    float cubicFeet, cubicMeters;
    printf("Enter cubic feet: ");
    scanf("%f", &cubicFeet);
    cubicMeters = cubicFeet / 35.3147;
    printf("%.2f cubic feet = %.2f cubic meters\n", cubicFeet, cubicMeters);
}