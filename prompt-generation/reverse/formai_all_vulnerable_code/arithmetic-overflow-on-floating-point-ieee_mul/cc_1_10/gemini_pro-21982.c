//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Welcome the user to the program.
    printf("\n\n\t\t\t\t██████████                ██████████");
    printf("\n\t\t\t\t██    ██    ██        ██    ██    ██");
    printf("\n\t\t\t\t██    ██    ██        ██    ██    ██");
    printf("\n\t\t\t\t██████████  █████      ██████████  █████");
    printf("\n\t\t\t\t██         ██    ██    ██         ██    ██");
    printf("\n\t\t\t\t██         ██    ██    ██         ██    ██");
    printf("\n\t\t\t\t██████████  ██    ██    ██████████  ██    ██");
    printf("\n\n\t\t\t\t██████████  ██    ██  ██████████  ██    ██");
    printf("\n\t\t\t\t██    ██    ██    ██    ██    ██    ██    ██");
    printf("\n\t\t\t\t██    ██    ██    ██    ██    ██    ██    ██");
    printf("\n\t\t\t\t██████████    ████      ██████████    ████");
    printf("\n");
    printf("\n\t\t\t\t██      ████    ██    ████      ██      ████");
    printf("\n\t\t\t\t██      ██  ██  ██      ██  ██  ██      ██  ██");
    printf("\n\t\t\t\t██      ██    ████      ██████████      ██    ██");
    printf("\n\t\t\t\t██████████    ██        ██    ██    ██████████");
    printf("\n");
    printf("\n\t\t\t\t██    ██    ██    ██    ██    ██    ██    ██");
    printf("\n\t\t\t\t██    ██    ██    ██    ██    ██    ██    ██");
    printf("\n\t\t\t\t██████████  ██████    ██████████  ██████");
    printf("\n\n");
    printf("\t\t\t\t██      ████    ██    ████      ██      ████");
    printf("\n\t\t\t\t██      ██  ██  ██      ██  ██  ██      ██  ██");
    printf("\n\t\t\t\t██      ██    ████      ██████████      ██    ██");
    printf("\n\t\t\t\t██████████    ██        ██    ██    ██████████");
    printf("\n\n");

    // Get the user's input.
    float temperature;
    char units;
    printf("\n\t\t\t\tEnter the temperature: ");
    scanf("%f", &temperature);
    printf("\n\t\t\t\tEnter the units (C or F): ");
    scanf(" %c", &units);

    // Convert the temperature to the other units.
    float converted_temperature;
    if (units == 'C') {
        converted_temperature = temperature * 9 / 5 + 32;
        printf("\n\t\t\t\t%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, converted_temperature);
    } else if (units == 'F') {
        converted_temperature = (temperature - 32) * 5 / 9;
        printf("\n\t\t\t\t%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, converted_temperature);
    } else {
        printf("\n\t\t\t\tInvalid units. Please enter 'C' for Celsius or 'F' for Fahrenheit.\n");
    }

    return 0;
}