//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("Welcome to the Unit Converter!\n");
    printf("-------------------------------------------------\n");
    printf("Choose a conversion:\n");
    printf("1: Length (meters to feet)\n");
    printf("2: Weight (kilograms to pounds)\n");
    printf("3: Temperature (Celsius to Fahrenheit)\n");
    printf("4: Exit\n");
    printf("-------------------------------------------------\n");
}

double metersToFeet(double meters) {
    return meters * 3.28084;
}

double kilogramsToPounds(double kg) {
    return kg * 2.20462;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

void conversionMystery() {
    double inputValue;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if(scanf("%d", &choice) != 1) {
            printf("Oops! That's not a valid number. Try again.\n");
            // Clear invalid input
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter length in meters: ");
                scanf("%lf", &inputValue);
                printf("%.2lf meters is equal to %.2lf feet.\n", inputValue, metersToFeet(inputValue));
                break;
            case 2:
                printf("Enter weight in kilograms: ");
                scanf("%lf", &inputValue);
                printf("%.2lf kilograms is equal to %.2lf pounds.\n", inputValue, kilogramsToPounds(inputValue));
                break;
            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &inputValue);
                printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", inputValue, celsiusToFahrenheit(inputValue));
                break;
            case 4:
                printf("Exiting the Unit Converter. Thank you for using it!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("-------------------------------------------------\n");
    }
}

int main() {
    conversionMystery();
    return 0;
}