//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Prototypes
void convert_temperature(float temperature, char from_unit, char to_unit);

int main() {
    char from_unit, to_unit;
    float temperature;

    printf("Enter temperature: ");
    scanf("%f", &temperature);

    printf("Enter the unit of temperature (C, F or K): ");
    scanf(" %c", &from_unit);

    printf("Convert temperature to (C, F or K): ");
    scanf(" %c", &to_unit);

    // Convert temperature
    convert_temperature(temperature, from_unit, to_unit);

    return 0;
}

// Function to convert temperature
void convert_temperature(float temperature, char from_unit, char to_unit) {
    float converted_temperature = 0;

    if (from_unit == 'C') {
        if (to_unit == 'F') {
            converted_temperature = (temperature * 9.0 / 5.0) + 32;
        } else if (to_unit == 'K') {
            converted_temperature = temperature + 273.15;
        }
    } else if (from_unit == 'F') {
        if (to_unit == 'C') {
            converted_temperature = (temperature - 32) * 5.0 / 9.0;
        } else if (to_unit == 'K') {
            converted_temperature = (temperature + 459.67) * 5.0 / 9.0;
        }
    } else if (from_unit == 'K') {
        if (to_unit == 'C') {
            converted_temperature = temperature - 273.15;
        } else if (to_unit == 'F') {
            converted_temperature = (temperature * 9.0 / 5.0) - 459.67;
        }
    }

    printf("The converted temperature is: %.2f %c\n", converted_temperature, to_unit);
}