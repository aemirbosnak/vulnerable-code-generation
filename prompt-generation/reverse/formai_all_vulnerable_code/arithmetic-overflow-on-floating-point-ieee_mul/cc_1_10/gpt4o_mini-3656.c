//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: beginner-friendly
#include <stdio.h>

void displayMenu() {
    printf("\n*** Unit Converter ***\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("5. Grams to Ounces\n");
    printf("6. Ounces to Grams\n");
    printf("7. Liters to Gallons\n");
    printf("8. Gallons to Liters\n");
    printf("9. Exit\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float kilometersToMiles(float kilometers) {
    return kilometers * 0.621371;
}

float milesToKilometers(float miles) {
    return miles / 0.621371;
}

float gramsToOunces(float grams) {
    return grams * 0.035274;
}

float ouncesToGrams(float ounces) {
    return ounces / 0.035274;
}

float litersToGallons(float liters) {
    return liters * 0.264172;
}

float gallonsToLiters(float gallons) {
    return gallons / 0.264172;
}

int main() {
    int choice;
    float input, result;
    
    do {
        displayMenu();
        printf("Please choose an option (1-9): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &input);
                result = celsiusToFahrenheit(input);
                printf("%.2f Celsius = %.2f Fahrenheit\n", input, result);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &input);
                result = fahrenheitToCelsius(input);
                printf("%.2f Fahrenheit = %.2f Celsius\n", input, result);
                break;

            case 3:
                printf("Enter distance in Kilometers: ");
                scanf("%f", &input);
                result = kilometersToMiles(input);
                printf("%.2f Kilometers = %.2f Miles\n", input, result);
                break;

            case 4:
                printf("Enter distance in Miles: ");
                scanf("%f", &input);
                result = milesToKilometers(input);
                printf("%.2f Miles = %.2f Kilometers\n", input, result);
                break;

            case 5:
                printf("Enter weight in Grams: ");
                scanf("%f", &input);
                result = gramsToOunces(input);
                printf("%.2f Grams = %.2f Ounces\n", input, result);
                break;

            case 6:
                printf("Enter weight in Ounces: ");
                scanf("%f", &input);
                result = ouncesToGrams(input);
                printf("%.2f Ounces = %.2f Grams\n", input, result);
                break;

            case 7:
                printf("Enter volume in Liters: ");
                scanf("%f", &input);
                result = litersToGallons(input);
                printf("%.2f Liters = %.2f Gallons\n", input, result);
                break;

            case 8:
                printf("Enter volume in Gallons: ");
                scanf("%f", &input);
                result = gallonsToLiters(input);
                printf("%.2f Gallons = %.2f Liters\n", input, result);
                break;

            case 9:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }

    } while (choice != 9);

    return 0;
}