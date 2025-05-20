//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

// Function to get user input
float get_user_input(char *message) {
    float input;
    printf("%s", message);
    scanf("%f", &input);
    return input;
}

// Main function
int main() {
    char choice;
    float temperature;

    do {
        // Get user input for temperature
        temperature = get_user_input("Enter temperature in Celsius or Fahrenheit: ");

        // Get user input for conversion
        printf("Convert to Celsius (C) or Fahrenheit (F)? ");
        scanf(" %c", &choice);

        // Convert temperature based on user input
        if (choice == 'C' || choice == 'c') {
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, celsius_to_fahrenheit(temperature));
        } else if (choice == 'F' || choice == 'f') {
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, fahrenheit_to_celsius(temperature));
        } else {
            printf("Invalid choice. Please enter C or F.\n");
        }

        // Ask user if they want to continue
        printf("Do you want to continue? (Y/N) ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    return 0;
}