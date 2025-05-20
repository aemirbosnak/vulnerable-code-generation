//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH_UNITS "centimeters, meters, kilometers"
#define WEIGHT_UNITS "grams, kilograms, tons"
#define TEMPERATURE_UNITS "celsius, fahrenheit, kelvin"

// Function to convert units of length
void length_convert(double length, char *unit) {
    double converted_length = 0;

    // Check if the input length is negative
    if (length < 0) {
        printf("Error: Negative length not allowed.\n");
        return;
    }

    // Convert length to meters
    if (strcmp(unit, "centimeters") == 0) {
        converted_length = length / 100;
    } else if (strcmp(unit, "meters") == 0) {
        converted_length = length;
    } else if (strcmp(unit, "kilometers") == 0) {
        converted_length = length * 1000;
    }

    // Print the converted length
    printf("Length in meters: %f\n", converted_length);
}

// Function to convert units of weight
void weight_convert(double weight, char *unit) {
    double converted_weight = 0;

    // Check if the input weight is negative
    if (weight < 0) {
        printf("Error: Negative weight not allowed.\n");
        return;
    }

    // Convert weight to kilograms
    if (strcmp(unit, "grams") == 0) {
        converted_weight = weight / 1000;
    } else if (strcmp(unit, "kilograms") == 0) {
        converted_weight = weight;
    } else if (strcmp(unit, "tons") == 0) {
        converted_weight = weight * 1000;
    }

    // Print the converted weight
    printf("Weight in kilograms: %f\n", converted_weight);
}

// Function to convert units of temperature
void temperature_convert(double temperature, char *unit) {
    double converted_temperature = 0;

    // Check if the input temperature is negative
    if (temperature < 0) {
        printf("Error: Negative temperature not allowed.\n");
        return;
    }

    // Convert temperature to celsius
    if (strcmp(unit, "celsius") == 0) {
        converted_temperature = temperature;
    } else if (strcmp(unit, "fahrenheit") == 0) {
        converted_temperature = (temperature - 32) * 5/9;
    } else if (strcmp(unit, "kelvin") == 0) {
        converted_temperature = temperature + 273.15;
    }

    // Print the converted temperature
    printf("Temperature in celsius: %f\n", converted_temperature);
}

int main() {
    double length, weight, temperature;
    char unit[50];

    // Get the length from the user
    printf("Enter length in centimeters: ");
    scanf("%lf", &length);

    // Get the unit from the user
    printf("Enter unit (centimeters, meters, kilometers): ");
    fgets(unit, 50, stdin);

    // Convert length to meters
    length_convert(length, unit);

    // Get the weight from the user
    printf("Enter weight in grams: ");
    scanf("%lf", &weight);

    // Get the unit from the user
    printf("Enter unit (grams, kilograms, tons): ");
    fgets(unit, 50, stdin);

    // Convert weight to kilograms
    weight_convert(weight, unit);

    // Get the temperature from the user
    printf("Enter temperature in celsius: ");
    scanf("%lf", &temperature);

    // Get the unit from the user
    printf("Enter unit (celsius, fahrenheit, kelvin): ");
    fgets(unit, 50, stdin);

    // Convert temperature to celsius
    temperature_convert(temperature, unit);

    return 0;
}