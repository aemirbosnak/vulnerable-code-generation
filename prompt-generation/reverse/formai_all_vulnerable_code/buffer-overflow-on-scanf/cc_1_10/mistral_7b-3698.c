//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BOLTZMANN_CONSTANT (1.380649e-23f) // Joules per Kelvin
#define C_TO_F_CONVERSION_FACTOR (1.8f)
#define F_TO_C_CONVERSION_FACTOR (5.0f/9.0f)

typedef struct {
    char unit;
    float value;
} Temperature;

void print_temperature(Temperature temperature) {
    const char *unit_names[] = {"Celsius", "Fahrenheit"};

    printf("%.2f %s\n", temperature.value, unit_names[temperature.unit == 'C' ? 0 : 1]);
}

Temperature celsius_to_fahrenheit(float celsius) {
    Temperature temperature;
    temperature.unit = 'F';
    temperature.value = celsius * C_TO_F_CONVERSION_FACTOR;
    return temperature;
}

Temperature fahrenheit_to_celsius(float fahrenheit) {
    Temperature temperature;
    temperature.unit = 'C';
    temperature.value = fahrenheit * F_TO_C_CONVERSION_FACTOR;
    temperature.value -= 273.15f; // Kelvin to Celsius conversion
    return temperature;
}

int main() {
    Temperature celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius.value);
    celsius.unit = 'C';

    fahrenheit = celsius_to_fahrenheit(celsius.value);
    printf("Equivalent temperature in Fahrenheit: ");
    print_temperature(fahrenheit);

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit.value);
    fahrenheit.unit = 'F';

    celsius = fahrenheit_to_celsius(fahrenheit.value);
    printf("Equivalent temperature in Celsius: ");
    print_temperature(celsius);

    return EXIT_SUCCESS;
}