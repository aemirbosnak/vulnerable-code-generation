//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: intelligent
#include <stdio.h>

// Define the conversion constants
#define CELSIUS_TO_FAHRENHEIT_FACTOR 1.8
#define FAHRENHEIT_TO_CELSIUS_FACTOR 0.5555555555555556

// Define the temperature unit abbreviations
#define CELSIUS "°C"
#define FAHRENHEIT "°F"

// Define the valid temperature unit options
#define VALID_TEMPERATURE_UNITS "°C, °F"

// Get the temperature unit from the user
char* get_temperature_unit(void) {
    char* temperature_unit = malloc(2);
    while (1) {
        printf("Enter the temperature unit (%s): ", VALID_TEMPERATURE_UNITS);
        scanf("%s", temperature_unit);
        if (strcmp(temperature_unit, CELSIUS) == 0 || strcmp(temperature_unit, FAHRENHEIT) == 0) {
            break;
        } else {
            printf("Invalid temperature unit. Please enter %s.\n", VALID_TEMPERATURE_UNITS);
        }
    }
    return temperature_unit;
}

// Get the temperature value from the user
float get_temperature_value(void) {
    float temperature_value;
    printf("Enter the temperature value: ");
    scanf("%f", &temperature_value);
    return temperature_value;
}

// Convert the temperature to the specified unit
float convert_temperature(float temperature_value, char* temperature_unit, char* target_temperature_unit) {
    float converted_temperature_value;
    if (strcmp(temperature_unit, CELSIUS) == 0 && strcmp(target_temperature_unit, FAHRENHEIT) == 0) {
        converted_temperature_value = (temperature_value * CELSIUS_TO_FAHRENHEIT_FACTOR) + 32;
    } else if (strcmp(temperature_unit, FAHRENHEIT) == 0 && strcmp(target_temperature_unit, CELSIUS) == 0) {
        converted_temperature_value = (temperature_value - 32) * FAHRENHEIT_TO_CELSIUS_FACTOR;
    } else {
        printf("Invalid temperature unit conversion. Please enter a valid conversion.");
    }
    return converted_temperature_value;
}

// Print the converted temperature
void print_converted_temperature(float converted_temperature_value, char* target_temperature_unit) {
    printf("The converted temperature is %.2f %s.\n", converted_temperature_value, target_temperature_unit);
}

int main(void) {
    char* temperature_unit = get_temperature_unit();
    float temperature_value = get_temperature_value();
    char* target_temperature_unit;
    if (strcmp(temperature_unit, CELSIUS) == 0) {
        target_temperature_unit = FAHRENHEIT;
    } else {
        target_temperature_unit = CELSIUS;
    }
    float converted_temperature_value = convert_temperature(temperature_value, temperature_unit, target_temperature_unit);
    print_converted_temperature(converted_temperature_value, target_temperature_unit);
    return 0;
}