//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n---------------------------\n");
    printf("Welcome to the Super Unit Converter!\n");
    printf("---------------------------\n");
    printf("Choose a conversion type:\n");
    printf("1. Length Converter\n");
    printf("2. Temperature Converter\n");
    printf("3. Weight Converter\n");
    printf("4. Exit\n");
    printf("---------------------------\n");
    printf("Enter your choice (1-4): ");
}

void lengthConverter() {
    double meters, feet;
    printf("\nLength Converter (Meters to Feet)\n");
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    feet = meters * 3.28084;
    printf("%.2f meters is equal to %.2f feet.\n", meters, feet);
}

void temperatureConverter() {
    double celsius, fahrenheit;
    printf("\nTemperature Converter (Celsius to Fahrenheit)\n");
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
}

void weightConverter() {
    double kilograms, pounds;
    printf("\nWeight Converter (Kilograms to Pounds)\n");
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    pounds = kilograms * 2.20462;
    printf("%.2f kilograms is equal to %.2f pounds.\n", kilograms, pounds);
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                lengthConverter();
                break;
            case 2:
                temperatureConverter();
                break;
            case 3:
                weightConverter();
                break;
            case 4:
                printf("Exiting the Super Unit Converter. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option (1-4).\n");
                break;
        }
    }
    return 0;
}