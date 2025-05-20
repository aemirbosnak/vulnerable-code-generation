//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void display_menu();
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);
float get_valid_input();

int main() {
    int choice;
    float temperature, convertedTemperature;

    while (1) {
        display_menu();
        printf("Enter your choice (1-6) or 0 to exit: ");
        choice = (int)get_valid_input();

        if (choice == 0) {
            printf("Exiting the program. Thank you!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                temperature = get_valid_input();
                convertedTemperature = celsius_to_fahrenheit(temperature);
                printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                temperature = get_valid_input();
                convertedTemperature = fahrenheit_to_celsius(temperature);
                printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, convertedTemperature);
                break;
            case 3:
                printf("Enter temperature in Celsius: ");
                temperature = get_valid_input();
                convertedTemperature = celsius_to_kelvin(temperature);
                printf("%.2f Celsius is %.2f Kelvin\n", temperature, convertedTemperature);
                break;
            case 4:
                printf("Enter temperature in Kelvin: ");
                temperature = get_valid_input();
                convertedTemperature = kelvin_to_celsius(temperature);
                printf("%.2f Kelvin is %.2f Celsius\n", temperature, convertedTemperature);
                break;
            case 5:
                printf("Enter temperature in Fahrenheit: ");
                temperature = get_valid_input();
                convertedTemperature = fahrenheit_to_kelvin(temperature);
                printf("%.2f Fahrenheit is %.2f Kelvin\n", temperature, convertedTemperature);
                break;
            case 6:
                printf("Enter temperature in Kelvin: ");
                temperature = get_valid_input();
                convertedTemperature = kelvin_to_fahrenheit(temperature);
                printf("%.2f Kelvin is %.2f Fahrenheit\n", temperature, convertedTemperature);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}

// Function to display conversion menu
void display_menu() {
    printf("\nTemperature Converter Menu:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
}

// Conversion functions
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

float kelvin_to_fahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}

// Input validation function
float get_valid_input() {
    float input;
    while (1) {
        char buffer[64];
        fgets(buffer, sizeof(buffer), stdin);

        // Check if conversion is successful
        if (sscanf(buffer, "%f", &input) == 1) {
            return input;  // Successfully read a float
        } else {
            printf("Invalid input. Please enter a valid number: ");
        }
    }
}