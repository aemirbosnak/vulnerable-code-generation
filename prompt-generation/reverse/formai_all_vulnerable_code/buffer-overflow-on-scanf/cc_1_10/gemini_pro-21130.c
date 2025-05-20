//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define the enum for the temperature scales
typedef enum {
    CELSIUS,
    FAHRENHEIT,
    KELVIN
} temperature_scale;

// Define the struct for the temperature
typedef struct {
    double value;
    temperature_scale scale;
} temperature;

// Define the function to convert a temperature from one scale to another
temperature convert_temperature(temperature temp, temperature_scale new_scale) {
    // Check if the new scale is the same as the old scale
    if (temp.scale == new_scale) {
        return temp;
    }

    // Convert the temperature to the new scale
    switch (new_scale) {
        case CELSIUS:
            temp.value = (temp.value - 32) * 5 / 9;
            temp.scale = CELSIUS;
            break;
        case FAHRENHEIT:
            temp.value = (temp.value * 9 / 5) + 32;
            temp.scale = FAHRENHEIT;
            break;
        case KELVIN:
            temp.value = temp.value + 273.15;
            temp.scale = KELVIN;
            break;
    }

    // Return the converted temperature
    return temp;
}

// Define the main function
int main() {
    // Get the temperature from the user
    double value;
    char scale;
    printf("Enter the temperature value: ");
    scanf("%lf", &value);
    printf("Enter the temperature scale (C, F, or K): ");
    scanf(" %c", &scale);

    // Convert the temperature to the new scale
    temperature temp = {.value = value, .scale = (temperature_scale) scale};
    temp = convert_temperature(temp, KELVIN);

    // Print the converted temperature
    printf("The temperature in Kelvin is: %.2f\n", temp.value);

    return 0;
}