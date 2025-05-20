//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    char input[100];
    char unit[10];
    double temperature;
    int choice;

    // Prompt the user to enter a temperature with a unit
    printf("Enter a temperature with a unit (e.g. 10 C): ");
    scanf("%s", input);

    // Extract the unit from the input
    strcpy(unit, input + strlen(input) - 1);

    // Remove the unit from the input
    input[strlen(input) - 2] = '\0';

    // Convert the input to a temperature
    temperature = atof(input);

    // Prompt the user to choose a conversion
    printf("Choose a conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    scanf("%d", &choice);

    // Convert the temperature
    switch(choice) {
        case 1:
            // Celsius to Fahrenheit
            temperature = (temperature * 9.0 / 5.0) + 32;
            printf("%.2f C is %.2f F\n", temperature, temperature);
            break;
        case 2:
            // Celsius to Kelvin
            temperature += 273.15;
            printf("%.2f C is %.2f K\n", temperature, temperature);
            break;
        default:
            // Invalid choice
            printf("Invalid choice\n");
            break;
    }

    return 0;
}