//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define the temperature range
#define MIN_TEMP -50
#define MAX_TEMP 50

// Define the temperature increment
#define TEMP_INCREMENT 0.1

// Define the temperature units
#define CELSIUS_UNITS "C"
#define FAHRENHEIT_UNITS "F"

// Define the temperature conversion functions
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// Define the temperature display function
void display_temperature(double temperature, char* units) {
    printf("Temperature: %.1f %s\n", temperature, units);
}

// Define the main function
int main() {
    double temperature = MIN_TEMP;
    char units = CELSIUS_UNITS;

    // Loop through the temperature range
    for (temperature = MIN_TEMP; temperature <= MAX_TEMP; temperature += TEMP_INCREMENT) {
        // Convert the temperature to Fahrenheit
        double fahrenheit_temperature = celsius_to_fahrenheit(temperature);

        // Display the temperature in Celsius and Fahrenheit
        display_temperature(temperature, CELSIUS_UNITS);
        display_temperature(fahrenheit_temperature, FAHRENHEIT_UNITS);

        // Ask the user to choose the temperature units
        printf("Enter C to continue displaying temperatures in Celsius, or F to switch to Fahrenheit: ");
        scanf("%c", &units);

        // Check if the user wants to switch temperature units
        if (units == 'F' || units == 'f') {
            printf("Switching to Fahrenheit...\n");
            units = FAHRENHEIT_UNITS;
        }
    }

    return 0;
}