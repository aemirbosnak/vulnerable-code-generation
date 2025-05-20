//FormAI DATASET v1.0 Category: Temperature Converter ; Style: automated
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

int main() {
    int menuOption;
    float temperature, result;
    printf("Welcome to the Temperature Converter!\n");

    // Loop to display the menu until the user chooses to exit
    while(1) {
        printf("\nPlease choose an option:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Option: ");
        scanf("%d", &menuOption);

        if(menuOption == 1) {
            // Conversion from Celsius to Fahrenheit
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            result = celsiusToFahrenheit(temperature);
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, result);
        } else if(menuOption == 2) {
            // Conversion from Fahrenheit to Celsius
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            result = fahrenheitToCelsius(temperature);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, result);
        } else if(menuOption == 3) {
            // Exit the program
            printf("Thanks for using the Temperature Converter!");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}