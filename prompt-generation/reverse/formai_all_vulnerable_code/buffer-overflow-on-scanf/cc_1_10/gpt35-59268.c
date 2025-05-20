//FormAI DATASET v1.0 Category: Unit converter ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = 32.0 + (celsius * 1.8);
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32.0) / 1.8;
    return celsius;
}

// Function to check if value is within valid range
bool withinValidRange(float value, float min, float max) {
    if (value >= min && value <= max) {
        return true;
    } else {
        return false;
    }
}

int main() {
    float input;
    char choice;
    const float CELSIUS_MIN = -273.15; // Absolute zero in Celsius
    const float CELSIUS_MAX = 1000;    // Maximum Celsius value
    const float FAHRENHEIT_MIN = -459.67; // Absolute zero in Fahrenheit
    const float FAHRENHEIT_MAX = 1832;    // Maximum Fahrenheit value

    printf("Welcome to the paranoid unit converter program.\n");
    printf("Please choose an option:\n");
    printf("A. Celsius to Fahrenheit\n");
    printf("B. Fahrenheit to Celsius\n");

    scanf(" %c", &choice);
    choice = toupper(choice);

    switch (choice) {
        case 'A':
            printf("\nEnter a temperature in Celsius: ");
            scanf("%f", &input);
            if (withinValidRange(input, CELSIUS_MIN, CELSIUS_MAX)) {
                printf("\n%.2f Celsius is %.2f Fahrenheit.\n", input, celsiusToFahrenheit(input));
            } else {
                printf("\nError: input value is outside of the valid range (%.2f - %.2f Celsius).\n", CELSIUS_MIN, CELSIUS_MAX);
            }
            break;
        case 'B':
            printf("\nEnter a temperature in Fahrenheit: ");
            scanf("%f", &input);
            if (withinValidRange(input, FAHRENHEIT_MIN, FAHRENHEIT_MAX)) {
                printf("\n%.2f Fahrenheit is %.2f Celsius.\n", input, fahrenheitToCelsius(input));
            } else {
                printf("\nError: input value is outside of the valid range (%.2f - %.2f Fahrenheit).\n", FAHRENHEIT_MIN, FAHRENHEIT_MAX);
            }
            break;
        default:
            printf("\nError: invalid choice.\n");
            break;
    }

    return 0;
}