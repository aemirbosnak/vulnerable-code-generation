//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define a struct for temperature conversions
typedef struct {
    char unit;
    float value;
} Temperature;

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return celsius * 9.0 / 5.0 + 32;
}

int main() {
    // Welcome message in a visionary style
    printf("Once upon a time in a land of numbers,\n");
    printf("Where temperature ruled the roost,\n");
    printf("There lived two mysterious entities,\n");
    printf("Fahrenheit and Celsius, of great renown.\n\n");

    char userChoice;
    Temperature temperatureInput, temperatureOutput;

    printf("Choose temperature unit to convert from (F or C): ");
    scanf(" %c", &userChoice);

    if (userChoice == 'F') {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperatureInput.value);

        temperatureOutput.value = fahrenheitToCelsius(temperatureInput.value);
        temperatureOutput.unit = 'C';

        printf("The temperature in Celsius is: %.2f°C\n", temperatureOutput.value);
    } else if (userChoice == 'C') {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperatureInput.value);

        temperatureOutput.value = celsiusToFahrenheit(temperatureInput.value);
        temperatureOutput.unit = 'F';

        printf("The temperature in Fahrenheit is: %.2f°F\n", temperatureOutput.value);
    } else {
        printf("Invalid input. Please use F or C.\n");
    }

    return 0;
}