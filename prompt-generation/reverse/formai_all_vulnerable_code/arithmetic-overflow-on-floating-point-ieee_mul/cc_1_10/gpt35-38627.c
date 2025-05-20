//FormAI DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

int main() {
    int choice;
    double input, output;
    
    printf("Welcome to the Unit Converter!\n");
    printf("Please select the conversion you would like to perform:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    scanf("%d", &choice);

    // Take user input
    printf("Enter the value to convert: ");
    scanf("%lf", &input);

    // Perform the selected conversion
    switch(choice) {
        case 1:
            output = celsiusToFahrenheit(input);
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit", input, output);
            break;
        case 2:
            output = fahrenheitToCelsius(input);
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius", input, output);
            break;
        case 3:
            output = celsiusToKelvin(input);
            printf("%.2lf degrees Celsius is equal to %.2lf Kelvin", input, output);
            break;
        case 4:
            output = kelvinToCelsius(input);
            printf("%.2lf Kelvin is equal to %.2lf degrees Celsius", input, output);
            break;
        default:
            printf("Invalid choice!");
            break;
    }
    
    return 0;
}