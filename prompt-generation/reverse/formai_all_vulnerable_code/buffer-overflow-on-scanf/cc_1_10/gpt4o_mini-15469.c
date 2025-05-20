//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("=================================\n");
    printf("       UNIT CONVERTER           \n");
    printf("=================================\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Currency Conversion\n");
    printf("5. Exit\n");
    printf("=================================\n");
    printf("Choose an option (1-5): ");
}

void lengthConversion() {
    double meters, feet;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    feet = meters * 3.28084; // meters to feet conversion
    printf("%.2lf meters is equivalent to %.2lf feet\n", meters, feet);
}

void weightConversion() {
    double kilograms, pounds;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    pounds = kilograms * 2.20462; // kilograms to pounds conversion
    printf("%.2lf kilograms is equivalent to %.2lf pounds\n", kilograms, pounds);
}

void temperatureConversion() {
    double celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9/5) + 32; // Celsius to Fahrenheit conversion
    printf("%.2lf Celsius is equivalent to %.2lf Fahrenheit\n", celsius, fahrenheit);
}

void currencyConversion() {
    double usd, eur;
    const double conversion_rate = 0.85; // sample conversion rate for USD to EUR
    printf("Enter amount in USD: ");
    scanf("%lf", &usd);
    eur = usd * conversion_rate; // USD to EUR conversion
    printf("%.2lf USD is equivalent to %.2lf EUR\n", usd, eur);
}

void pause() {
    printf("Press Enter to continue...");
    while(getchar() != '\n');
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                lengthConversion();
                break;
            case 2:
                weightConversion();
                break;
            case 3:
                temperatureConversion();
                break;
            case 4:
                currencyConversion();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }

        if (choice != 5) {
            pause();
        }

    } while (choice != 5);

    return 0;
}