//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("================================\n");
    printf("        Unit Converter         \n");
    printf("================================\n");
    printf("1. Length (inches to centimeters)\n");
    printf("2. Temperature (Celsius to Fahrenheit)\n");
    printf("3. Weight (pounds to kilograms)\n");
    printf("4. Volume (gallons to liters)\n");
    printf("5. Exit\n");
    printf("================================\n");
    printf("Please select an option (1-5): ");
}

double convertLength(double inches) {
    return inches * 2.54;
}

double convertTemperature(double celsius) {
    return (celsius * 9/5) + 32;
}

double convertWeight(double pounds) {
    return pounds * 0.453592;
}

double convertVolume(double gallons) {
    return gallons * 3.78541;
}

void handleLengthConversion() {
    double inches;
    printf("Enter length in inches: ");
    scanf("%lf", &inches);
    printf("%.2f inches is equivalent to %.2f centimeters.\n", inches, convertLength(inches));
}

void handleTemperatureConversion() {
    double celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    printf("%.2f Celsius is equivalent to %.2f Fahrenheit.\n", celsius, convertTemperature(celsius));
}

void handleWeightConversion() {
    double pounds;
    printf("Enter weight in pounds: ");
    scanf("%lf", &pounds);
    printf("%.2f pounds is equivalent to %.2f kilograms.\n", pounds, convertWeight(pounds));
}

void handleVolumeConversion() {
    double gallons;
    printf("Enter volume in gallons: ");
    scanf("%lf", &gallons);
    printf("%.2f gallons is equivalent to %.2f liters.\n", gallons, convertVolume(gallons));
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                handleLengthConversion();
                break;
            
            case 2:
                handleTemperatureConversion();
                break;

            case 3:
                handleWeightConversion();
                break;

            case 4:
                handleVolumeConversion();
                break;

            case 5:
                printf("Exiting the Unit Converter. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }

        printf("\n");

    } while (choice != 5);

    return 0;
}