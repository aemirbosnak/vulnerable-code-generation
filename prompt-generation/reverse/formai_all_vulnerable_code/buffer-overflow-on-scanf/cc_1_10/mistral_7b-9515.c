//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float value;
    char unit;
} Unit;

void print_unit(Unit unit) {
    printf("Value: %.2f, Unit: %c\n", unit.value, unit.unit);
}

Unit convert_kelvin_to_fahrenheit(Unit kelvin) {
    Unit fahrenheit;
    fahrenheit.value = kelvin.value * 1.8 + 32;
    fahrenheit.unit = 'F';
    return fahrenheit;
}

Unit convert_fahrenheit_to_kelvin(Unit fahrenheit) {
    Unit kelvin;
    kelvin.value = (fahrenheit.value - 32) * 5.0/9.0;
    kelvin.unit = 'K';
    return kelvin;
}

int main() {
    Unit temperature;
    char choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("1. Convert Kelvin to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Kelvin\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    printf("Enter temperature value: ");
    scanf("%f", &temperature.value);
    temperature.unit = 'K'; // Assuming Kelvin by default

    switch (choice) {
        case '1':
            temperature = convert_kelvin_to_fahrenheit(temperature);
            break;
        case '2':
            temperature = convert_fahrenheit_to_kelvin(temperature);
            break;
        default:
            printf("Invalid choice. Exiting...\n");
            return 1;
    }

    print_unit(temperature);

    return 0;
}