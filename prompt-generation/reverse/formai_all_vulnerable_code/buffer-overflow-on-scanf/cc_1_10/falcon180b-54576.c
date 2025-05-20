//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to get user input
float getUserInput(char* message) {
    float input;
    printf("%s", message);
    scanf("%f", &input);
    return input;
}

// Main function
int main() {
    char choice;
    do {
        // Prompt user to choose conversion type
        printf("\nWelcome to the Happy Temperature Converter!\n");
        printf("Please choose the type of conversion you would like to perform:\n");
        printf("1. Fahrenheit to Celsius\n2. Celsius to Fahrenheit\n");
        scanf("%c", &choice);

        // Get temperature value from user
        float temperature;
        if (choice == '1' || choice == '2') {
            temperature = getUserInput("Enter the temperature value: ");
        }

        // Perform conversion and display result
        if (choice == '1') {
            float celsius = fahrenheitToCelsius(temperature);
            printf("\n%f degrees Fahrenheit is equal to %f degrees Celsius.\n", temperature, celsius);
        } else if (choice == '2') {
            float fahrenheit = celsiusToFahrenheit(temperature);
            printf("\n%f degrees Celsius is equal to %f degrees Fahrenheit.\n", temperature, fahrenheit);
        }

    } while (choice == '1' || choice == '2');

    printf("\nThank you for using the Happy Temperature Converter! Have a great day!\n");

    return 0;
}