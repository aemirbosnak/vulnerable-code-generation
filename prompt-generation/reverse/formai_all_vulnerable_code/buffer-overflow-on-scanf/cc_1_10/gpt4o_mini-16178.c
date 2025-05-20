//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>

void distance_conversion() {
    double kilometers, miles, meters;
    printf("=== Distance Conversion ===\n");
    printf("Enter distance in kilometers: ");
    scanf("%lf", &kilometers);
    miles = kilometers * 0.621371;
    meters = kilometers * 1000;
    printf("Distance in miles: %.2f\n", miles);
    printf("Distance in meters: %.2f\n", meters);
}

void weight_conversion() {
    double kilograms, pounds, grams;
    printf("=== Weight Conversion ===\n");
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    pounds = kilograms * 2.20462;
    grams = kilograms * 1000;
    printf("Weight in pounds: %.2f\n", pounds);
    printf("Weight in grams: %.2f\n", grams);
}

void temperature_conversion() {
    double celsius, fahrenheit;
    printf("=== Temperature Conversion ===\n");
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
}

void display_menu() {
    printf("\n=== Unit Converter Menu ===\n");
    printf("1. Distance Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("0. Exit\n");
}

int main() {
    int choice;

    printf("Welcome to the Magical Unit Converter!\n");
    printf("Where your numbers transform before your eyes!\n");

    do {
        display_menu();
        printf("Choose your adventure (0-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                distance_conversion();
                break;
            case 2:
                weight_conversion();
                break;
            case 3:
                temperature_conversion();
                break;
            case 0:
                printf("Thank you for using the Magical Unit Converter! Bye bye!\n");
                break;
            default:
                printf("Ah, a mysterious choice! Please try again!\n");
        }

    } while (choice != 0);

    return 0;
}