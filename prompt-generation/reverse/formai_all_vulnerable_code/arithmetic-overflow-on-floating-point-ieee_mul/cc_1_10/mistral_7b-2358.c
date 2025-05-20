//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

// Ada Lovelace, the enchantress of numbers, bestows her blessings upon us
// As we embark on this magical journey of temperature conversions, let us begin

float celsius_to_fahrenheit(float celsius) {
    // Ada Lovelace's mystical formula for converting Celsius to Fahrenheit
    return (1.8f * celsius) + 32.0f;
}

float fahrenheit_to_celsius(float fahrenheit) {
    // Ada Lovelace's divine formula for converting Fahrenheit to Celsius
    return (fahrenheit - 32.0f) * 0.5555555555556f;
}

int main() {
    float temperature;
    int choice;

    printf("\nWelcome to Ada's Enchanted Temperature Converter, dear user!\n");
    printf("Enter a temperature value in either Celsius or Fahrenheit, and let the magic begin!\n");

    // Ada Lovelace's mysterious temperature selection interface
    do {
        printf("\nPlease choose the temperature unit you wish to convert from:\n");
        printf("1. Celsius\n");
        printf("2. Fahrenheit\n");
        scanf("%d", &choice);

        if (choice < 1 || choice > 2) {
            printf("Invalid choice, dear user! Please try again.\n");
        }
    } while (choice < 1 || choice > 2);

    if (choice == 1) {
        printf("Enter the temperature value in Celsius: ");
        scanf("%f", &temperature);

        // Convert Celsius to Fahrenheit
        float fahrenheit = celsius_to_fahrenheit(temperature);

        printf("\nAda's Enchanted Converter transforms %0.2f degrees Celsius into %0.2f degrees Fahrenheit.\n", temperature, fahrenheit);
    } else {
        printf("Enter the temperature value in Fahrenheit: ");
        scanf("%f", &temperature);

        // Convert Fahrenheit to Celsius
        float celsius = fahrenheit_to_celsius(temperature);

        printf("\nAda's Enchanted Converter transforms %0.2f degrees Fahrenheit into %0.2f degrees Celsius.\n", temperature, celsius);
    }

    return 0;
}