//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

// Function to check if input is a valid number
int is_valid_number(const char *input) {
    int i;
    for (i = 0; input[i]!= '\0'; i++) {
        if (!isdigit(input[i])) {
            return FALSE;
        }
    }
    return TRUE;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Function to get user input
double get_input(char *prompt) {
    char input[100];
    printf("%s", prompt);
    fgets(input, 100, stdin);
    return atof(input);
}

// Function to print temperature conversion
void print_conversion(double temperature, char *unit) {
    printf("%.2f %s is %.2f %s\n", temperature, unit, temperature, unit);
}

int main() {
    char input[100];
    int choice;
    double temperature;

    do {
        printf("Enter temperature: ");
        temperature = get_input("");

        // Check if input is a valid number
        if (!is_valid_number(input)) {
            printf("Invalid input. Please enter a valid number.\n");
            continue;
        }

        // Check if input is in Celsius or Fahrenheit
        printf("Is the temperature in Celsius or Fahrenheit? ");
        scanf("%d", &choice);

        // Convert temperature to Celsius or Fahrenheit
        if (choice == 1) {
            temperature = celsius_to_fahrenheit(temperature);
            printf("Temperature converted to Fahrenheit.\n");
        } else if (choice == 2) {
            temperature = fahrenheit_to_celsius(temperature);
            printf("Temperature converted to Celsius.\n");
        } else {
            printf("Invalid choice. Please enter 1 or 2.\n");
            continue;
        }

        // Print temperature conversion
        printf("Enter unit of temperature: ");
        scanf("%s", input);
        print_conversion(temperature, input);
    } while (TRUE);

    return 0;
}