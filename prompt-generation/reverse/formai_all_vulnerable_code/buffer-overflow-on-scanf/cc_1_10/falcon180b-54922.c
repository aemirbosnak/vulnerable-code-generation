//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 10

int main() {
    char input[MAX_LENGTH];
    char *endptr;
    double temperature;
    int choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter a temperature value:\n");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Convert input to temperature value
    temperature = strtod(input, &endptr);

    // Check if input is valid
    if (endptr == input || temperature < -273.15 || temperature > 1000) {
        printf("Invalid input. Please enter a valid temperature value.\n");
        return 1;
    }

    printf("Please choose the unit of the temperature value:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
    scanf("%d", &choice);

    // Convert temperature to selected unit
    switch (choice) {
        case 1:
            temperature += 273.15;
            printf("%.2f Celsius is %.2f Kelvin and %.2f Fahrenheit.\n", temperature, temperature, (temperature * 9/5) + 32);
            break;
        case 2:
            temperature = (temperature - 32) * 5/9;
            printf("%.2f Fahrenheit is %.2f Celsius and %.2f Kelvin.\n", temperature, (temperature * 5/9) + 32, temperature);
            break;
        case 3:
            printf("%.2f Kelvin is %.2f Celsius and %.2f Fahrenheit.\n", temperature, temperature - 273.15, (temperature * 9/5) + 32);
            break;
        default:
            printf("Invalid choice. Please choose a valid unit.\n");
            return 1;
    }

    return 0;
}