//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
void lengthConversion();
void weightConversion();
void temperatureConversion();
void areaConversion();
void volumeConversion();
float metersToFeet(float meters);
float feetToMeters(float feet);
float gramsToPounds(float grams);
float poundsToGrams(float pounds);
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float squareMetersToAcres(float squareMeters);
float acresToSquareMeters(float acres);
float litersToGallons(float liters);
float gallonsToLiters(float gallons);

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        printf("Please select a conversion option (1-5) or 0 to exit: ");
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
            case 0:
                printf("Exiting program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n************ Unit Converter ************\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Area Conversion\n");
    printf("5. Volume Conversion\n");
    printf("0. Exit\n");
    printf("***************************************\n");
}

void lengthConversion() {
    float meters, feet;
    printf("Enter length in meters: ");
    scanf("%f", &meters);
    
    feet = metersToFeet(meters);
    printf("%.2f meters is equal to %.2f feet.\n", meters, feet);
    
    printf("Enter length in feet: ");
    scanf("%f", &feet);
    
    meters = feetToMeters(feet);
    printf("%.2f feet is equal to %.2f meters.\n", feet, meters);
}

void weightConversion() {
    float grams, pounds;
    printf("Enter weight in grams: ");
    scanf("%f", &grams);
    
    pounds = gramsToPounds(grams);
    printf("%.2f grams is equal to %.2f pounds.\n", grams, pounds);
    
    printf("Enter weight in pounds: ");
    scanf("%f", &pounds);
    
    grams = poundsToGrams(pounds);
    printf("%.2f pounds is equal to %.2f grams.\n", pounds, grams);
}

void temperatureConversion() {
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    
    fahrenheit = celsiusToFahrenheit(celsius);
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
    
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    
    celsius = fahrenheitToCelsius(fahrenheit);
    printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, celsius);
}

void areaConversion() {
    float squareMeters, acres;
    printf("Enter area in square meters: ");
    scanf("%f", &squareMeters);
    
    acres = squareMetersToAcres(squareMeters);
    printf("%.2f square meters is equal to %.2f acres.\n", squareMeters, acres);
    
    printf("Enter area in acres: ");
    scanf("%f", &acres);
    
    squareMeters = acresToSquareMeters(acres);
    printf("%.2f acres is equal to %.2f square meters.\n", acres, squareMeters);
}

void volumeConversion() {
    float liters, gallons;
    printf("Enter volume in liters: ");
    scanf("%f", &liters);
    
    gallons = litersToGallons(liters);
    printf("%.2f liters is equal to %.2f gallons.\n", liters, gallons);
    
    printf("Enter volume in gallons: ");
    scanf("%f", &gallons);
    
    liters = gallonsToLiters(gallons);
    printf("%.2f gallons is equal to %.2f liters.\n", gallons, liters);
}

// Conversion functions
float metersToFeet(float meters) {
    return meters * 3.28084;
}

float feetToMeters(float feet) {
    return feet / 3.28084;
}

float gramsToPounds(float grams) {
    return grams * 0.00220462;
}

float poundsToGrams(float pounds) {
    return pounds / 0.00220462;
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0/5.0) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0/9.0;
}

float squareMetersToAcres(float squareMeters) {
    return squareMeters * 0.000247105;
}

float acresToSquareMeters(float acres) {
    return acres / 0.000247105;
}

float litersToGallons(float liters) {
    return liters * 0.264172;
}

float gallonsToLiters(float gallons) {
    return gallons / 0.264172;
}