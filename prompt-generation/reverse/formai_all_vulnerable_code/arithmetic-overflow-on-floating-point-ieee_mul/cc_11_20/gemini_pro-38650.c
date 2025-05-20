//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: creative
#include <stdio.h>

// Define the conversion formulas
#define CELSIUS_TO_FAHRENHEIT(c) ((c * 9) / 5) + 32
#define FAHRENHEIT_TO_CELSIUS(f) ((f - 32) * 5) / 9

// Define the temperature ranges
#define MIN_CELSIUS -273.15
#define MAX_CELSIUS 1000
#define MIN_FAHRENHEIT -459.67
#define MAX_FAHRENHEIT 3272.56

// Define the input and output messages
#define INPUT_CELSIUS "Enter a temperature in Celsius: "
#define INPUT_FAHRENHEIT "Enter a temperature in Fahrenheit: "
#define OUTPUT_CELSIUS "The temperature in Celsius is: "
#define OUTPUT_FAHRENHEIT "The temperature in Fahrenheit is: "

int main() {
    // Get the user's input
    float temperature;
    char unit;
    printf(INPUT_CELSIUS);
    scanf("%f", &temperature);
    printf("Enter the unit (C for Celsius, F for Fahrenheit): ");
    scanf(" %c", &unit);

    // Convert the temperature
    float convertedTemperature;
    switch (unit) {
        case 'C':
        case 'c':
            convertedTemperature = CELSIUS_TO_FAHRENHEIT(temperature);
            break;
        case 'F':
        case 'f':
            convertedTemperature = FAHRENHEIT_TO_CELSIUS(temperature);
            break;
        default:
            printf("Invalid unit entered. Please enter 'C' for Celsius or 'F' for Fahrenheit.\n");
            return 1;
    }

    // Check if the converted temperature is within the valid range
    if (convertedTemperature < MIN_CELSIUS || convertedTemperature > MAX_CELSIUS) {
        printf("The converted temperature is outside the valid range (%f to %f degrees Celsius).\n", MIN_CELSIUS, MAX_CELSIUS);
        return 1;
    } else if (convertedTemperature < MIN_FAHRENHEIT || convertedTemperature > MAX_FAHRENHEIT) {
        printf("The converted temperature is outside the valid range (%f to %f degrees Fahrenheit).\n", MIN_FAHRENHEIT, MAX_FAHRENHEIT);
        return 1;
    }

    // Output the converted temperature
    switch (unit) {
        case 'C':
        case 'c':
            printf(OUTPUT_FAHRENHEIT, convertedTemperature);
            break;
        case 'F':
        case 'f':
            printf(OUTPUT_CELSIUS, convertedTemperature);
            break;
    }

    return 0;
}