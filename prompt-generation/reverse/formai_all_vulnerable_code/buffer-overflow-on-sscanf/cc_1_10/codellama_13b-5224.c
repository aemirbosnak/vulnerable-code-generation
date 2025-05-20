//Code Llama-13B DATASET v1.0 Category: Temperature Converter ; Style: distributed
/* Distributed Temperature Converter */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 80
#define MAX_DEGREES 10

// Define the temperature unit enum
typedef enum {
    CELSIUS,
    FAHRENHEIT,
    KELVIN
} temperature_unit_t;

// Define the temperature struct
typedef struct {
    temperature_unit_t unit;
    double value;
} temperature_t;

// Function to convert temperature from one unit to another
temperature_t convert_temperature(temperature_t temp, temperature_unit_t target_unit) {
    switch (temp.unit) {
        case CELSIUS:
            switch (target_unit) {
                case CELSIUS:
                    return temp;
                case FAHRENHEIT:
                    return (temperature_t) {FAHRENHEIT, (temp.value * 1.8) + 32};
                case KELVIN:
                    return (temperature_t) {KELVIN, temp.value + 273.15};
            }
            break;
        case FAHRENHEIT:
            switch (target_unit) {
                case CELSIUS:
                    return (temperature_t) {CELSIUS, (temp.value - 32) / 1.8};
                case FAHRENHEIT:
                    return temp;
                case KELVIN:
                    return (temperature_t) {KELVIN, (temp.value + 459.67) * (5 / 9)};
            }
            break;
        case KELVIN:
            switch (target_unit) {
                case CELSIUS:
                    return (temperature_t) {CELSIUS, temp.value - 273.15};
                case FAHRENHEIT:
                    return (temperature_t) {FAHRENHEIT, (temp.value - 273.15) * (9 / 5) + 32};
                case KELVIN:
                    return temp;
            }
            break;
    }
    return (temperature_t) {CELSIUS, 0};
}

// Main function to test the temperature converter
int main() {
    temperature_t temp;
    temperature_unit_t target_unit;
    char input[MAX_INPUT];
    char target_unit_str[MAX_INPUT];

    // Get input temperature and target unit
    printf("Enter temperature: ");
    fgets(input, MAX_INPUT, stdin);
    sscanf(input, "%lf %s", &temp.value, target_unit_str);

    // Convert input temperature to uppercase
    for (int i = 0; i < strlen(target_unit_str); i++) {
        target_unit_str[i] = toupper(target_unit_str[i]);
    }

    // Set target unit based on input
    if (strcmp(target_unit_str, "CELSIUS") == 0) {
        target_unit = CELSIUS;
    } else if (strcmp(target_unit_str, "FAHRENHEIT") == 0) {
        target_unit = FAHRENHEIT;
    } else if (strcmp(target_unit_str, "KELVIN") == 0) {
        target_unit = KELVIN;
    } else {
        printf("Invalid target unit\n");
        return 1;
    }

    // Convert temperature to target unit
    temp = convert_temperature(temp, target_unit);

    // Print output temperature
    printf("Temperature in %s: %f\n", target_unit_str, temp.value);

    return 0;
}