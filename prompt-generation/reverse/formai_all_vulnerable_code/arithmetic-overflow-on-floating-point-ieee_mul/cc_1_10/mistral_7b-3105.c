//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// The Alchemist's constants
#define FREEZING_POINT_FAHRENHEIT 32
#define BOILING_POINT_FAHRENHEIT 212
#define FREEZING_POINT_CELSIUS 0
#define BOILING_POINT_CELSIUS 100
#define TWO_DEGREES_CELSIUS_INCREMENT 0.01

// Struct for temperature data
typedef struct {
    double temperature;
    char unit;
} Temperature;

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double temperatureFahrenheit) {
    double temperatureCelsius = (temperatureFahrenheit - FREEZING_POINT_FAHRENHEIT) * 5.0 / 9.0;
    return temperatureCelsius;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double temperatureCelsius) {
    double temperatureFahrenheit = (temperatureCelsius * 9.0 / 5.0) + FREEZING_POINT_FAHRENHEIT;
    return temperatureFahrenheit;
}

// Function to print temperature information in an artistic style
void printTemperature(Temperature temperature) {
    double temperatureInFahrenheit = celsiusToFahrenheit(temperature.temperature);

    printf("\n=========================================================\n");
    printf("|                   The Alchemist's                       |\n");
    printf("|                Temperature Transmutation               |\n");
    printf("|                  -----------------------------------|\n");

    if (temperature.unit == 'F') {
        printf("| From Fahrenheit: %1.1f°F                          |\n", temperature.temperature);
        printf("| To Celsius: %1.1f°C                               |\n", fahrenheitToCelsius(temperature.temperature));
    } else {
        printf("| From Celsius: %1.1f°C                             |\n", temperature.temperature);
        printf("| To Fahrenheit: %1.1f°F                           |\n", temperatureInFahrenheit);
    }

    printf("|---------------------------------------------------|\n");
}

int main(int argc, char *argv[]) {
    Temperature temperatureInput;
    char unit;

    if (argc != 3) {
        printf("\nUsage: %s <temperature> <F or C> \n", argv[0]);
        return 1;
    }

    temperatureInput.temperature = atof(argv[1]);
    unit = argv[2][0];

    if (unit != 'F' && unit != 'C') {
        printf("\nInvalid unit. Use 'F' for Fahrenheit or 'C' for Celsius.\n");
        return 1;
    }

    temperatureInput.unit = unit;
    printTemperature(temperatureInput);

    return 0;
}