//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void convertLength();
void convertWeight();
void convertTemperature();

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear buffer
}

int main() {
    int choice = 0;
    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer(); // Clean buffer before retrying
            choice = 0; // Reset choice to allow retry
            continue;
        }

        switch (choice) {
            case 1:
                convertLength();
                break;
            case 2:
                convertWeight();
                break;
            case 3:
                convertTemperature();
                break;
            case 4:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Option not recognized, please try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}

void displayMenu() {
    printf("\n***** Unit Converter *****\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Exit\n");
    printf("Please select an option (1-4): ");
}

void convertLength() {
    double meters, feet;
    printf("Enter length in meters: ");
    if (scanf("%lf", &meters) != 1) {
        printf("Invalid input, returning to main menu.\n");
        clearInputBuffer();
        return;
    }
    feet = meters * 3.28084; // conversion factor from meters to feet
    printf("%.2f meters is equal to %.2f feet.\n", meters, feet);
}

void convertWeight() {
    double kilograms, pounds;
    printf("Enter weight in kilograms: ");
    if (scanf("%lf", &kilograms) != 1) {
        printf("Invalid input, returning to main menu.\n");
        clearInputBuffer();
        return;
    }
    pounds = kilograms * 2.20462; // conversion factor from kilograms to pounds
    printf("%.2f kilograms is equal to %.2f pounds.\n", kilograms, pounds);
}

void convertTemperature() {
    double celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    if (scanf("%lf", &celsius) != 1) {
        printf("Invalid input, returning to main menu.\n");
        clearInputBuffer();
        return;
    }
    fahrenheit = (celsius * 9/5) + 32; // conversion formula from Celsius to Fahrenheit
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
}