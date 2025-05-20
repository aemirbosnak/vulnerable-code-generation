//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: dynamic
#include <stdio.h>

typedef enum {
    CELSIUS,
    FAHRENHEIT,
    KELVIN
} temperature_scale;

typedef struct {
    float value;
    temperature_scale scale;
} temperature;

float convert_temperature(temperature from, temperature_scale to) {
    float result;
    switch (from.scale) {
        case CELSIUS:
            switch (to) {
                case CELSIUS:
                    result = from.value;
                    break;
                case FAHRENHEIT:
                    result = (from.value * 1.8) + 32;
                    break;
                case KELVIN:
                    result = from.value + 273.15;
                    break;
            }
            break;
        case FAHRENHEIT:
            switch (to) {
                case CELSIUS:
                    result = (from.value - 32) / 1.8;
                    break;
                case FAHRENHEIT:
                    result = from.value;
                    break;
                case KELVIN:
                    result = ((from.value - 32) / 1.8) + 273.15;
                    break;
            }
            break;
        case KELVIN:
            switch (to) {
                case CELSIUS:
                    result = from.value - 273.15;
                    break;
                case FAHRENHEIT:
                    result = ((from.value - 273.15) * 1.8) + 32;
                    break;
                case KELVIN:
                    result = from.value;
                    break;
            }
            break;
    }
    return result;
}

int main() {
    temperature from;
    temperature_scale to;
    float result;

    printf("Enter the temperature value: ");
    scanf("%f", &from.value);

    printf("Enter the temperature scale (Celsius/Fahrenheit/Kelvin): ");
    scanf("%s", &from.scale);

    printf("Enter the desired temperature scale (Celsius/Fahrenheit/Kelvin): ");
    scanf("%s", &to);

    result = convert_temperature(from, to);

    printf("The converted temperature is: %.2f %s\n", result, to);

    return 0;
}