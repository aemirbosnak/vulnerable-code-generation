//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: romantic
#include <stdio.h>

void displayWelcomeMessage() {
    printf("********************************************************\n");
    printf("*               Welcome to the Temperature               *\n");
    printf("*                 Converter of Love and Dreams!         *\n");
    printf("********************************************************\n\n");
    printf("In this magical world of temperatures,\n");
    printf("Let us convert them and embrace the warmth or coolness,\n");
    printf("For between Celsius and Fahrenheit,\n");
    printf("A loving touch can turn the cold into delight.\n\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void displayFarewellMessage() {
    printf("\nThank you for visiting our Temperature Converter!\n");
    printf("May every degree bring you closer to the one you cherish.\n");
    printf("Farewell, until we meet again in another romantic calculation!\n");
}

int main() {
    float temperature, convertedTemperature;
    int choice;
    char continueChoice;

    displayWelcomeMessage();

    do {
        printf("Please choose your conversion:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        
        while (1) {
            printf("Enter (1 or 2): ");
            if (scanf("%d", &choice) == 1 && (choice == 1 || choice == 2)) {
                break;
            }
            else {
                printf("Oh, darling! That wasn't an option. Please try again.\n");
                while(getchar() != '\n'); // clear input buffer
            }
        }

        if (choice == 1) {
            printf("Ah, you've chosen to transform the coolness of Celsius.\n");
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            convertedTemperature = celsiusToFahrenheit(temperature);
            printf("As the magic unfolds, %.2f°C becomes %.2f°F.\n", temperature, convertedTemperature);
        } else {
            printf("Ah, the warmth of Fahrenheit must be tamed!\n");
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            convertedTemperature = fahrenheitToCelsius(temperature);
            printf("As the romance of calculations shines, %.2f°F becomes %.2f°C.\n", temperature, convertedTemperature);
        }
        
        printf("Would you like to convert another temperature, my love? (y/n): ");
        while(getchar() != '\n'); // clear input buffer
        scanf("%c", &continueChoice);
        
    } while (continueChoice == 'y' || continueChoice == 'Y');

    displayFarewellMessage();

    return 0;
}