//Code Llama-13B DATASET v1.0 Category: Temperature Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define a structure to hold the temperature values
struct temperature {
    float celsius;
    float fahrenheit;
    float kelvin;
};

// function to convert celsius to fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// function to convert fahrenheit to celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// function to convert celsius to kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

// function to convert kelvin to celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// function to convert fahrenheit to kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    return (fahrenheit + 459.67) * 5 / 9;
}

// function to convert kelvin to fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    return (kelvin * 9 / 5) - 459.67;
}

int main() {
    struct temperature t;
    float celsius, fahrenheit, kelvin;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // convert celsius to fahrenheit
    t.celsius = celsius;
    t.fahrenheit = celsius_to_fahrenheit(celsius);

    // convert fahrenheit to celsius
    t.fahrenheit = fahrenheit;
    t.celsius = fahrenheit_to_celsius(fahrenheit);

    // convert celsius to kelvin
    t.celsius = celsius;
    t.kelvin = celsius_to_kelvin(celsius);

    // convert kelvin to celsius
    t.kelvin = kelvin;
    t.celsius = kelvin_to_celsius(kelvin);

    // convert fahrenheit to kelvin
    t.fahrenheit = fahrenheit;
    t.kelvin = fahrenheit_to_kelvin(fahrenheit);

    // convert kelvin to fahrenheit
    t.kelvin = kelvin;
    t.fahrenheit = kelvin_to_fahrenheit(kelvin);

    printf("Temperature in Celsius: %.2f\n", t.celsius);
    printf("Temperature in Fahrenheit: %.2f\n", t.fahrenheit);
    printf("Temperature in Kelvin: %.2f\n", t.kelvin);

    return 0;
}