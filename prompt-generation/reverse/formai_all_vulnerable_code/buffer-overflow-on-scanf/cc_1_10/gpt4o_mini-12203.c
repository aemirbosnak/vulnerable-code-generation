//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n=====================\n");
    printf("SHOCKING UNIT CONVERTER\n");
    printf("=====================\n");
    printf("Choose a conversion type:\n");
    printf("1. Length (meters to feet)\n");
    printf("2. Weight (kilograms to pounds)\n");
    printf("3. Temperature (Celsius to Fahrenheit)\n");
    printf("4. Exit\n");
    printf("=====================\n");
}

void lengthConverter() {
    float meters;
    printf("Enter length in meters: ");
    scanf("%f", &meters);
    float feet = meters * 3.28084;
    printf("%.2f meters is equal to %.2f feet!\n\n", meters, feet);
}

void weightConverter() {
    float kilograms;
    printf("Enter weight in kilograms: ");
    scanf("%f", &kilograms);
    float pounds = kilograms * 2.20462;
    printf("%.2f kilograms is equal to %.2f pounds!\n\n", kilograms, pounds);
}

void temperatureConverter() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    float fahrenheit = (celsius * 9.0/5.0) + 32.0;
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit!\n\n", celsius, fahrenheit);
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("Exiting the SHOCKING UNIT CONVERTER... oh no! Why are you leaving?\n");
                break;
            default:
                printf("What?! That's not a valid option! Try again...\n");
                break;
        }
    } while (choice != 4);

    printf("Thanks for using the SHOCKING UNIT CONVERTER! Stay curious!\n");
    return 0;
}