//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void convertTemperature();
void convertLength();
void convertWeight();
void convertArea();

// Function to read input and return it
double getInput(const char *prompt) {
    double value;
    printf("%s", prompt);
    scanf("%lf", &value);
    return value;
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        choice = (int)getInput("Choose an option (1-4) or 0 to exit: ");

        switch (choice) {
            case 0:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            case 1:
                convertTemperature();
                break;
            case 2:
                convertLength();
                break;
            case 3:
                convertWeight();
                break;
            case 4:
                convertArea();
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Unit Converter ---\n");
    printf("1. Temperature Converter\n");
    printf("2. Length Converter\n");
    printf("3. Weight Converter\n");
    printf("4. Area Converter\n");
    printf("0. Exit\n");
}

void convertTemperature() {
    double celsius, fahrenheit;
    printf("\n--- Temperature Conversion ---\n");
    celsius = getInput("Enter temperature in Celsius: ");
    fahrenheit = (celsius * 9/5) + 32;
    printf("%.2lf Celsius is %.2lf Fahrenheit.\n", celsius, fahrenheit);
}

void convertLength() {
    double meters, feet, yards;
    printf("\n--- Length Conversion ---\n");
    meters = getInput("Enter length in meters: ");
    feet = meters * 3.28084;
    yards = meters * 1.09361;
    printf("%.2lf meters is %.2lf feet or %.2lf yards.\n", meters, feet, yards);
}

void convertWeight() {
    double kilograms, pounds;
    printf("\n--- Weight Conversion ---\n");
    kilograms = getInput("Enter weight in kilograms: ");
    pounds = kilograms * 2.20462;
    printf("%.2lf kilograms is %.2lf pounds.\n", kilograms, pounds);
}

void convertArea() {
    double squareMeters, squareFeet, acres;
    printf("\n--- Area Conversion ---\n");
    squareMeters = getInput("Enter area in square meters: ");
    squareFeet = squareMeters * 10.7639;
    acres = squareMeters * 0.000247105;
    printf("%.2lf square meters is %.2lf square feet or %.2lf acres.\n", squareMeters, squareFeet, acres);
}