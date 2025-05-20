//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>

void lengthConverter();
void weightConverter();
void temperatureConverter();
void displayMenu();

int main() {
    int choice;

    while (1) {
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
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void displayMenu() {
    printf("\n***** Unit Converter *****\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("4. Exit\n");
}

void lengthConverter() {
    double meters, feet;
    printf("\nLength Converter:\n");
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    feet = meters * 3.28084;
    printf("%.2f meters is %.2f feet.\n", meters, feet);
}

void weightConverter() {
    double kilograms, pounds;
    printf("\nWeight Converter:\n");
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    pounds = kilograms * 2.20462;
    printf("%.2f kilograms is %.2f pounds.\n", kilograms, pounds);
}

void temperatureConverter() {
    double celsius, fahrenheit;
    int choice;
    printf("\nTemperature Converter:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%lf", &celsius);
        fahrenheit = (celsius * 9.0 / 5.0) + 32;
        printf("%.2f Celsius is %.2f Fahrenheit.\n", celsius, fahrenheit);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%lf", &fahrenheit);
        celsius = (fahrenheit - 32) * 5.0 / 9.0;
        printf("%.2f Fahrenheit is %.2f Celsius.\n", fahrenheit, celsius);
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}