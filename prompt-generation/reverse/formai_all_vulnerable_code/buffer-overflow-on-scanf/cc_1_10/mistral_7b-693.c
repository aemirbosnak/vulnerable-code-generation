//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef enum { FAHRENHEIT, CELSIUS } TemperatureUnit;

struct TemperatureConversion {
    double value;
    TemperatureUnit unit;
};

struct TemperatureConversion FahrenheitToCelsius(struct TemperatureConversion fahrenheit) {
    struct TemperatureConversion celsius;
    double celsiusFormula = (fahrenheit.value - 32.0) * 5.0 / 9.0;

    celsius.value = celsiusFormula;
    celsius.unit = CELSIUS;

    return celsius;
}

struct TemperatureConversion CelsiusToFahrenheit(struct TemperatureConversion celsius) {
    struct TemperatureConversion fahrenheit;
    double fahrenheitFormula = celsius.value * 9.0 / 5.0 + 32.0;

    fahrenheit.value = fahrenheitFormula;
    fahrenheit.unit = FAHRENHEIT;

    return fahrenheit;
}

int main() {
    struct TemperatureConversion userInput, convertedTemp;
    char inputUnit;
    double temperatureValue;

    printf("Enter temperature value: ");
    scanf("%lf", &temperatureValue);

    printf("Enter temperature unit (F for Fahrenheit, C for Celsius): ");
    scanf(" %c", &inputUnit);

    if (inputUnit == 'F' || inputUnit == 'f') {
        userInput.value = temperatureValue;
        userInput.unit = FAHRENHEIT;

        convertedTemp = FahrenheitToCelsius(userInput);

        printf("\nTemperature converted to Celsius: %.2lf°C\n", convertedTemp.value);
    } else if (inputUnit == 'C' || inputUnit == 'c') {
        userInput.value = temperatureValue;
        userInput.unit = CELSIUS;

        convertedTemp = CelsiusToFahrenheit(userInput);

        printf("\nTemperature converted to Fahrenheit: %.2lf°F\n", convertedTemp.value);
    } else {
        printf("\nInvalid temperature unit entered.\n");
    }

    return 0;
}