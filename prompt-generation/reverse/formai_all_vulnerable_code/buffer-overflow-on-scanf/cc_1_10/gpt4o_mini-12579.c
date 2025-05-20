//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>

// Function declarations
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);

int main() {
    // Declaration of variables
    float temperature;
    int choice;
    
    // User will see the menu
    printf("Temperature Converter Program\n");
    printf("Choose the conversion you would like to perform:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("Enter your choice (1-6): ");
    
    // User input for choice
    scanf("%d", &choice);
    
    // User input for temperature value
    printf("Enter temperature value: ");
    scanf("%f", &temperature);
    
    // Handling user choice with quadratic decisions
    switch (choice) {
        case 1:
            // Convert Celsius to Fahrenheit
            printf("%.2f Celsius is equal to %.2f Fahrenheit\n", temperature, celsius_to_fahrenheit(temperature));
            break;
        case 2:
            // Convert Fahrenheit to Celsius
            printf("%.2f Fahrenheit is equal to %.2f Celsius\n", temperature, fahrenheit_to_celsius(temperature));
            break;
        case 3:
            // Convert Celsius to Kelvin
            printf("%.2f Celsius is equal to %.2f Kelvin\n", temperature, celsius_to_kelvin(temperature));
            break;
        case 4:
            // Convert Kelvin to Celsius
            printf("%.2f Kelvin is equal to %.2f Celsius\n", temperature, kelvin_to_celsius(temperature));
            break;
        case 5:
            // Convert Fahrenheit to Kelvin
            printf("%.2f Fahrenheit is equal to %.2f Kelvin\n", temperature, fahrenheit_to_kelvin(temperature));
            break;
        case 6:
            // Convert Kelvin to Fahrenheit
            printf("%.2f Kelvin is equal to %.2f Fahrenheit\n", temperature, kelvin_to_fahrenheit(temperature));
            break;
        default:
            // Invalid option
            printf("Invalid choice! Please select a number between 1 and 6.\n");
            break;
    }

    return 0; // end of the program
}

// Function definitions
float celsius_to_fahrenheit(float celsius) {
    // Applying the conversion formula
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    // Applying the conversion formula
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) {
    // Applying the conversion formula
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    // Applying the conversion formula
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    // Converting Fahrenheit to Celsius first
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    // Converting Kelvin to Celsius first
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}