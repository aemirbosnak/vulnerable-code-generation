//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100
#define MAX_OPTIONS 20

// Function prototypes
void displayMenu();
void performConversion(int choice);
void temperatureConversion();
void distanceConversion();
void weightConversion();
void areaConversion();
void volumeConversion();
void displayExitMessage();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-%d) or 0 to exit: ", MAX_OPTIONS);
        scanf("%d", &choice);

        if (choice == 0) {
            displayExitMessage();
            break;
        }
        if (choice < 1 || choice > MAX_OPTIONS) {
            printf("\nInvalid choice! Please try again.\n\n");
            continue;
        }
        performConversion(choice);
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n---- Unit Conversion Program ----\n");
    printf("1. Temperature Conversion\n");
    printf("2. Distance Conversion\n");
    printf("3. Weight Conversion\n");
    printf("4. Area Conversion\n");
    printf("5. Volume Conversion\n");
    printf("Please select a conversion type:\n");
}

void performConversion(int choice) {
    switch (choice) {
        case 1:
            temperatureConversion();
            break;
        case 2:
            distanceConversion();
            break;
        case 3:
            weightConversion();
            break;
        case 4:
            areaConversion();
            break;
        case 5:
            volumeConversion();
            break;
        default:
            printf("Invalid option chosen.\n");
            break;
    }
}

void temperatureConversion() {
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    printf("Celsius: %.2f C = Fahrenheit: %.2f F\n", celsius, fahrenheit);
}

void distanceConversion() {
    float kilometers, miles;
    printf("Enter distance in kilometers: ");
    scanf("%f", &kilometers);
    miles = kilometers * 0.621371;
    printf("Kilometers: %.2f km = Miles: %.2f mi\n", kilometers, miles);
}

void weightConversion() {
    float kilograms, pounds;
    printf("Enter weight in kilograms: ");
    scanf("%f", &kilograms);
    pounds = kilograms * 2.20462;
    printf("Kilograms: %.2f kg = Pounds: %.2f lbs\n", kilograms, pounds);
}

void areaConversion() {
    float squareMeters, squareFeet;
    printf("Enter area in square meters: ");
    scanf("%f", &squareMeters);
    squareFeet = squareMeters * 10.7639;
    printf("Square Meters: %.2f m^2 = Square Feet: %.2f ft^2\n", squareMeters, squareFeet);
}

void volumeConversion() {
    float liters, gallons;
    printf("Enter volume in liters: ");
    scanf("%f", &liters);
    gallons = liters * 0.264172;
    printf("Liters: %.2f L = Gallons: %.2f gal\n", liters, gallons);
}

void displayExitMessage() {
    printf("\nThank you for using the Unit Conversion Program!\n");
    printf("See you next time!\n");
}