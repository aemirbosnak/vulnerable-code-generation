//FormAI DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>

// Function to convert Centimeters to Inches
float cmToInches(int cm) {
    float inches = cm / 2.54;
    return inches;
}

// Function to convert Inches to Centimeters
float inchesToCm(int inches) {
    float cm = inches * 2.54;
    return cm;
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(int celsius) {
    float fahrenheit = (celsius * (9.0/5.0)) + 32.0;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(int fahrenheit) {
    float celsius = (fahrenheit - 32.0) * (5.0/9.0);
    return celsius;
}

int main() {

    int choice; // Choice entered by user
    float input; // Input entered by user
    
    printf("Welcome to Unit Converter\n");
    printf("1. Centimeters to Inches\n");
    printf("2. Inches to Centimeters\n");
    printf("3. Celsius to Fahrenheit\n");
    printf("4. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice); // Taking input choice from user

    switch(choice) {
        case 1: // Converting Centimeters to Inches
            printf("Enter Centimeters: ");
            scanf("%f", &input); // Taking input from user
            printf("%.2f cm = %.2f inches", input, cmToInches(input)); // Calling function to convert and displaying output
            break;

        case 2: // Converting Inches to Centimeters
            printf("Enter Inches: ");
            scanf("%f", &input); // Taking input from user
            printf("%.2f inches = %.2f cm", input, inchesToCm(input)); // Calling function to convert and displaying output
            break;

        case 3: // Converting Celsius to Fahrenheit
            printf("Enter Celsius: ");
            scanf("%f", &input); // Taking input from user
            printf("%.2f C = %.2f F", input, celsiusToFahrenheit(input)); // Calling function to convert and displaying output
            break;

        case 4: // Converting Fahrenheit to Celsius
            printf("Enter Fahrenheit: ");
            scanf("%f", &input); // Taking input from user
            printf("%.2f F = %.2f C", input, fahrenheitToCelsius(input)); // Calling function to convert and displaying output
            break;

        default: // Handling Invalid Input
            printf("Invalid Input");
            break;
    }

    return 0;
}