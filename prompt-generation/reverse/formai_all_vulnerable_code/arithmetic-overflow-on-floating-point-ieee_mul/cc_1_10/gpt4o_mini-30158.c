//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>

void displayWelcomeMessage() {
    printf("🌞 Welcome to the Happy Temperature Converter! 🌞\n");
    printf("We are here to make your temperature conversions cheerful and fun! 🎉\n");
    printf("Let's get started!\n\n");
}

void displayMenu() {
    printf("Choose the conversion you would like to perform:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void performConversion() {
    int choice;
    float temperature, convertedTemperature;

    while (1) {
        displayMenu();
        printf("Please enter your choice (1/2/3): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            convertedTemperature = celsiusToFahrenheit(temperature);
            printf("🎉 %.2f Celsius is equal to %.2f Fahrenheit! 🎉\n\n", temperature, convertedTemperature);
        } 
        else if (choice == 2) {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            convertedTemperature = fahrenheitToCelsius(temperature);
            printf("🎉 %.2f Fahrenheit is equal to %.2f Celsius! 🎉\n\n", temperature, convertedTemperature);
        } 
        else if (choice == 3) {
            printf("Thank you for using the Happy Temperature Converter! 😄\n");
            printf("Have a wonderful day! 🌈\n");
            break;  // Exit the loop and the program
        } 
        else {
            printf("📌 Oops! That's not a valid choice. Please try again! 📌\n\n");
        }
    }
}

int main() {
    displayWelcomeMessage();
    performConversion();
    return 0;
}