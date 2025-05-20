//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: multivariable
#include <stdio.h>

void kilometersToMiles(float kilometers);
void milesToKilometers(float miles);
void litersToGallons(float liters);
void gallonsToLiters(float gallons);
void celsiusToFahrenheit(float celsius);
void fahrenheitToCelsius(float fahrenheit);
void metersToFeet(float meters);
void feetToMeters(float feet);

void displayMenu() {
    printf("Unit Converter Menu:\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Miles to Kilometers\n");
    printf("3. Liters to Gallons\n");
    printf("4. Gallons to Liters\n");
    printf("5. Celsius to Fahrenheit\n");
    printf("6. Fahrenheit to Celsius\n");
    printf("7. Meters to Feet\n");
    printf("8. Feet to Meters\n");
    printf("9. Exit\n");
    printf("Select an option (1-9): ");
}

int main() {
    int choice;
    float value;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        if (choice == 9) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        printf("Enter the value to convert: ");
        scanf("%f", &value);

        switch (choice) {
            case 1:
                kilometersToMiles(value);
                break;
            case 2:
                milesToKilometers(value);
                break;
            case 3:
                litersToGallons(value);
                break;
            case 4:
                gallonsToLiters(value);
                break;
            case 5:
                celsiusToFahrenheit(value);
                break;
            case 6:
                fahrenheitToCelsius(value);
                break;
            case 7:
                metersToFeet(value);
                break;
            case 8:
                feetToMeters(value);
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}

void kilometersToMiles(float kilometers) {
    float miles = kilometers * 0.621371;
    printf("%.2f kilometers is %.2f miles\n", kilometers, miles);
}

void milesToKilometers(float miles) {
    float kilometers = miles / 0.621371;
    printf("%.2f miles is %.2f kilometers\n", miles, kilometers);
}

void litersToGallons(float liters) {
    float gallons = liters * 0.264172;
    printf("%.2f liters is %.2f gallons\n", liters, gallons);
}

void gallonsToLiters(float gallons) {
    float liters = gallons / 0.264172;
    printf("%.2f gallons is %.2f liters\n", gallons, liters);
}

void celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9 / 5) + 32;
    printf("%.2f degrees Celsius is %.2f degrees Fahrenheit\n", celsius, fahrenheit);
}

void fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5 / 9;
    printf("%.2f degrees Fahrenheit is %.2f degrees Celsius\n", fahrenheit, celsius);
}

void metersToFeet(float meters) {
    float feet = meters * 3.28084;
    printf("%.2f meters is %.2f feet\n", meters, feet);
}

void feetToMeters(float feet) {
    float meters = feet / 3.28084;
    printf("%.2f feet is %.2f meters\n", feet, meters);
}