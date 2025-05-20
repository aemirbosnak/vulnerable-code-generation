//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to print the conversion results
void print_conversion_results(float celsius, float fahrenheit) {
    printf("Celsius: %.2f degrees\n", celsius);
    printf("Fahrenheit: %.2f degrees\n", fahrenheit);
}

// Main function
int main() {
    // Declare variables
    float celsius, fahrenheit;
    int choice;

    // Get the user's choice
    printf("Enter your choice:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    // Convert the temperature based on the user's choice
    switch (choice) {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = celsius_to_fahrenheit(celsius);
            print_conversion_results(celsius, fahrenheit);
            break;
        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = fahrenheit_to_celsius(fahrenheit);
            print_conversion_results(celsius, fahrenheit);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid choice (1, 2, or 3).");
            break;
    }

    return 0;
}