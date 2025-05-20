//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>

// Function to convert length from meters to kilometers
void metersToKilometers(float meters) {
    printf("%.2f meters is equal to %.2f kilometers.\n", meters, meters / 1000);
}

// Function to convert weight from grams to kilograms
void gramsToKilograms(float grams) {
    printf("%.2f grams is equal to %.2f kilograms.\n", grams, grams / 1000);
}

// Function to convert Celsius to Fahrenheit
void celsiusToFahrenheit(float celsius) {
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, (celsius * 9/5) + 32);
}

// Function to convert Fahrenheit to Celsius
void fahrenheitToCelsius(float fahrenheit) {
    printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, (fahrenheit - 32) * 5/9);
}

// Main function displaying a cheerful menu
int main() {
    int choice;
    float value;

    printf("🌟 Welcome to the Happy Unit Converter! 🌟\n");
    printf("Please choose a conversion type:\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Grams to Kilograms\n");
    printf("3. Celsius to Fahrenheit\n");
    printf("4. Fahrenheit to Celsius\n");
    printf("5. Exit\n");

    while (1) {
        printf("Please enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Thank you for using the Happy Unit Converter! Goodbye! 😊\n");
            break;
        }

        // Asking for user input based on the choice
        switch (choice) {
            case 1:
                printf("Enter the value in meters: ");
                scanf("%f", &value);
                metersToKilometers(value);
                break;

            case 2:
                printf("Enter the value in grams: ");
                scanf("%f", &value);
                gramsToKilograms(value);
                break;

            case 3:
                printf("Enter the value in Celsius: ");
                scanf("%f", &value);
                celsiusToFahrenheit(value);
                break;

            case 4:
                printf("Enter the value in Fahrenheit: ");
                scanf("%f", &value);
                fahrenheitToCelsius(value);
                break;

            default:
                printf("Oops! That's not a valid choice. Please try again. 😊\n");
        }

        printf("\n🌈 Would you like to convert another unit? 🌈\n");
        printf("1. Yes\n");
        printf("2. No (exit)\n");
        int continueChoice;
        scanf("%d", &continueChoice);

        if (continueChoice == 2) {
            printf("Thank you for using the Happy Unit Converter! Goodbye! 😊\n");
            break;
        }

        printf("\nLet's continue converting! 🎉\n");
    }

    return 0;
}