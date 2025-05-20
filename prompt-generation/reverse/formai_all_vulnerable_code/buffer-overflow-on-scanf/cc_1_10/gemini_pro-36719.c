//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: complex
// A Comprehensive Temperature Converter in C

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Enumerating temperature units for user-friendly input
typedef enum TempUnit {
    KELVIN,
    CELSIUS,
    FAHRENHEIT,
} TempUnit;

// A multipurpose struct for representing temperature values
typedef struct Temperature {
    double value;
    TempUnit unit;
} Temperature;

// Function to convert a temperature to Kelvin
Temperature to_kelvin(Temperature temp) {
    switch (temp.unit) {
        case CELSIUS:
            temp.value += 273.15;
            break;
        case FAHRENHEIT:
            temp.value = (temp.value - 32) * 5 / 9 + 273.15;
            break;
        default:
            // Already in Kelvin
            break;
    }
    temp.unit = KELVIN;
    return temp;
}

// Function to convert a temperature from Kelvin to another unit
Temperature from_kelvin(Temperature temp, TempUnit target_unit) {
    switch (target_unit) {
        case CELSIUS:
            temp.value -= 273.15;
            break;
        case FAHRENHEIT:
            temp.value = (temp.value - 273.15) * 9 / 5 + 32;
            break;
        default:
            // Already in Kelvin
            break;
    }
    temp.unit = target_unit;
    return temp;
}

// Function to print a temperature value in a friendly format
void print_temperature(Temperature temp) {
    char unit_symbol;
    switch (temp.unit) {
        case KELVIN:
            unit_symbol = 'K';
            break;
        case CELSIUS:
            unit_symbol = 'C';
            break;
        case FAHRENHEIT:
            unit_symbol = 'F';
            break;
    }
    printf("%g %c\n", temp.value, unit_symbol);
}

// Function to handle user input
Temperature get_temperature_input(void) {
    Temperature temp;
    double value;
    int unit_choice;
    printf("Enter a temperature value: ");
    scanf("%lf", &value);
    printf("Enter the unit:\n1. Kelvin\n2. Celsius\n3. Fahrenheit\n");
    scanf("%d", &unit_choice);
    temp.value = value;
    temp.unit = unit_choice - 1;
    return temp;
}

// Function to handle user choice
TempUnit get_target_unit_choice(void) {
    int unit_choice;
    printf("Convert to:\n1. Kelvin\n2. Celsius\n3. Fahrenheit\n");
    scanf("%d", &unit_choice);
    return unit_choice - 1;
}

int main(void) {
    Temperature temp, converted_temp;
    temp = get_temperature_input();
    TempUnit target_unit = get_target_unit_choice();
    converted_temp = from_kelvin(to_kelvin(temp), target_unit);
    printf("The converted temperature is: ");
    print_temperature(converted_temp);
    return 0;
}