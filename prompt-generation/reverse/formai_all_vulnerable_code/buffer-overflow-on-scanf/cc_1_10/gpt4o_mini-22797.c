//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function prototypes for conversion
void convertLength();
void convertWeight();
void convertTemperature();
void showMenu();
void handleChoice(int choice);

int main() {
    int choice;
    
    printf("Welcome to the Unit Converter!\n");
    printf("This program allows you to convert between different units.\n");

    do {
        showMenu();
        printf("Please enter your choice (1-4, or 0 to exit): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear the input buffer
            while(getchar() != '\n');
            choice = -1;
        }
        handleChoice(choice);
    } while (choice != 0);

    printf("Thank you for using the Unit Converter. Goodbye!\n");
    return 0;
}

void showMenu() {
    printf("\nUnit Converter Menu:\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Show all conversions\n");
    printf("0. Exit\n");
}

void handleChoice(int choice) {
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
            printf("All conversions are as follows:\n");
            printf("Length: 1 meter = 100 centimeters = 39.37 inches\n");
            printf("Weight: 1 kilogram = 1000 grams = 2.20462 pounds\n");
            printf("Temperature: Celsius to Fahrenheit conversion\n");
            break;
        case 0:
            // Exit program
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
            break;
    }
}

void convertLength() {
    double meters, feet;
    printf("Enter length in meters: ");
    if (scanf("%lf", &meters) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        // Clear the input buffer
        while(getchar() != '\n');
        return;
    }
    feet = meters * 3.28084;
    printf("%.2lf meters is %.2lf feet.\n", meters, feet);
}

void convertWeight() {
    double kilograms, pounds;
    printf("Enter weight in kilograms: ");
    if (scanf("%lf", &kilograms) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        // Clear the input buffer
        while(getchar() != '\n');
        return;
    }
    pounds = kilograms * 2.20462;
    printf("%.2lf kilograms is %.2lf pounds.\n", kilograms, pounds);
}

void convertTemperature() {
    double celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    if (scanf("%lf", &celsius) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        // Clear the input buffer
        while(getchar() != '\n');
        return;
    }
    fahrenheit = (celsius * 9/5) + 32;
    printf("%.2lf Celsius is %.2lf Fahrenheit.\n", celsius, fahrenheit);
}