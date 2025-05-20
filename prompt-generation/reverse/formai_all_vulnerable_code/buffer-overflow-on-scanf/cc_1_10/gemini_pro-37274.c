//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: complex
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define CELSIUS_TO_FAHRENHEIT(C) ((C * 9 / 5) + 32)
#define FAHRENHEIT_TO_CELSIUS(F) ((F - 32) * 5 / 9)
#define KELVIN_TO_CELSIUS(K) (K - 273.15)
#define CELSIUS_TO_KELVIN(C) (C + 273.15)
#define FAHRENHEIT_TO_KELVIN(F) (CELSIUS_TO_KELVIN(FAHRENHEIT_TO_CELSIUS(F)))
#define KELVIN_TO_FAHRENHEIT(K) (FAHRENHEIT_TO_CELSIUS(K - 273.15))

typedef struct {
    float value;
    char unit;
} Temperature;

Temperature convert(Temperature temp, char from, char to) {
    float convertedValue;
    switch (from) {
        case 'C':
            switch (to) {
                case 'C':
                    convertedValue = temp.value;
                    break;
                case 'F':
                    convertedValue = CELSIUS_TO_FAHRENHEIT(temp.value);
                    break;
                case 'K':
                    convertedValue = CELSIUS_TO_KELVIN(temp.value);
                    break;
            }
            break;
        case 'F':
            switch (to) {
                case 'C':
                    convertedValue = FAHRENHEIT_TO_CELSIUS(temp.value);
                    break;
                case 'F':
                    convertedValue = temp.value;
                    break;
                case 'K':
                    convertedValue = FAHRENHEIT_TO_KELVIN(temp.value);
                    break;
            }
            break;
        case 'K':
            switch (to) {
                case 'C':
                    convertedValue = KELVIN_TO_CELSIUS(temp.value);
                    break;
                case 'F':
                    convertedValue = KELVIN_TO_FAHRENHEIT(temp.value);
                    break;
                case 'K':
                    convertedValue = temp.value;
                    break;
            }
            break;
    }
    Temperature result;
    result.value = convertedValue;
    result.unit = to;
    return result;
}

int main() {
    Temperature temp;
    char from, to;
    printf("Enter the temperature value: ");
    scanf("%f", &temp.value);
    printf("Enter the unit of the temperature (C, F, or K): ");
    scanf(" %c", &from);
    printf("Enter the unit to convert to (C, F, or K): ");
    scanf(" %c", &to);
    Temperature result = convert(temp, from, to);
    printf("The converted temperature is: %.2f %c\n", result.value, result.unit);
    return 0;
}