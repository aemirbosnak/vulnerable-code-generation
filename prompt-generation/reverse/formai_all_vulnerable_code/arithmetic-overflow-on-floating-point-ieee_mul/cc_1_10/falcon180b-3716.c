//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

// Function to validate input
int is_valid_input(const char* input) {
    int length = strlen(input);

    // Check if input contains only digits and a decimal point
    for (int i = 0; i < length; i++) {
        if (!isdigit(input[i]) && input[i]!= '.') {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[100];
    float temperature;
    int choice;

    // Cyberpunk-style ASCII art
    printf("                           \n");
    printf("     _____ _ _ _ _ _ _ _ \n");
    printf("    |___ \\| | | | | | | |\n");
    printf("     __) || | | | | | | |\n");
    printf("    |__ <| | | | | | | |\n");
    printf("     ___) || |_| | | | |\n");
    printf("    |____/ |_____| |_| |\n");
    printf("                     \n");

    printf("Welcome to the Cyberpunk Temperature Converter!\n");
    printf("Enter a temperature in Celsius or Fahrenheit to convert:\n");
    scanf("%s", input);

    while (!is_valid_input(input)) {
        printf("Invalid input. Please enter a valid temperature:\n");
        scanf("%s", input);
    }

    temperature = atof(input);

    // Ask user for conversion preference
    printf("Select a conversion preference:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, celsius_to_fahrenheit(temperature));
            break;
        case 2:
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, fahrenheit_to_celsius(temperature));
            break;
        default:
            printf("Invalid choice. Please enter a valid choice.\n");
            break;
    }

    return 0;
}