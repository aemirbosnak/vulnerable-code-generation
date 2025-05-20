//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>

void displayMenu();
void lengthConversion();
void weightConversion();
void temperatureConversion();
double convertKilometersToMiles(double kilometers);
double convertPoundsToKilograms(double pounds);
double convertCelsiusToFahrenheit(double celsius);

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
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
                printf("Exiting the converter. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
        printf("\n");
    } while (choice != 4);
    return 0;
}

void displayMenu() {
    printf("=== Unit Converter ===\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Exit\n");
}

void lengthConversion() {
    double kilometers, miles;
    printf("Enter distance in kilometers: ");
    scanf("%lf", &kilometers);
    miles = convertKilometersToMiles(kilometers);
    printf("%.2lf kilometers is equal to %.2lf miles.\n", kilometers, miles);
}

void weightConversion() {
    double pounds, kilograms;
    printf("Enter weight in pounds: ");
    scanf("%lf", &pounds);
    kilograms = convertPoundsToKilograms(pounds);
    printf("%.2lf pounds is equal to %.2lf kilograms.\n", pounds, kilograms);
}

void temperatureConversion() {
    double celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = convertCelsiusToFahrenheit(celsius);
    printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahrenheit);
}

double convertKilometersToMiles(double kilometers) {
    return kilometers * 0.621371;
}

double convertPoundsToKilograms(double pounds) {
    return pounds * 0.453592;
}

double convertCelsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}