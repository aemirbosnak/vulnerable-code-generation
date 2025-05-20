//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

void displayWelcomeMessage() {
    printf("*******************************\n");
    printf("* Welcome to the Temperature   *\n");
    printf("* Converter of the Mind-Bending *\n");
    printf("* Realm!                       *\n");
    printf("*******************************\n\n");
}

double fahrenheitToCelsius(double f) {
    return (f - 32) * 5.0 / 9.0;
}

double celsiusToFahrenheit(double c) {
    return (c * 9.0 / 5.0) + 32;
}

void showConversionOptions() {
    printf("Choose your path:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Exit the Mind-Bending Realm\n");
    printf("Enter your choice (1-3): ");
}

void handleUserChoice(int choice) {
    double temp, convertedTemp;

    switch (choice) {
        case 1:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temp);
            convertedTemp = fahrenheitToCelsius(temp);
            printf("The temperature in Celsius is: %.2f°C\n", convertedTemp);
            break;
        case 2:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temp);
            convertedTemp = celsiusToFahrenheit(temp);
            printf("The temperature in Fahrenheit is: %.2f°F\n", convertedTemp);
            break;
        case 3:
            printf("You have chosen to exit the realm. May your journey be warm!\n");
            exit(0);
        default:
            printf("Invalid option, please choose again!\n");
            break;
    }
}

void infiniteLoopOfChoices() {
    int choice;
    while (1) {
        showConversionOptions();
        scanf("%d", &choice);
        handleUserChoice(choice);
        printf("\nLet's continue in this temperature journey!\n\n");
    }
}

int main() {
    displayWelcomeMessage();
    infiniteLoopOfChoices();
    return 0;
}